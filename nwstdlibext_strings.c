//
//  NW STDLIB EXTENSIONS
//
//  Copyright (c) 2006-2018 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//
//  This software is provided 'as-is', without any express or implied
//  warranty. In no event will the authors be held liable for any damages
//  arising from the use of this software. Permission is granted to anyone to
//  use this software for any purpose, including commercial applications, and to
//  alter it and redistribute it freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//     claim that you wrote the original software. If you use this software
//     in a product, an acknowledgment in the product documentation would be
//     appreciated but is not required.
//  2. Altered source versions must be plainly marked as such, and must not be
//     misrepresented as being the original software.
//  3. This notice may not be removed or altered from any source
//     distribution.
//

#include "nwstdlibext.h"
#include <locale.h>

#if __NW_STDLIB_EXT_IMPLEMENTATION
//#error Use only "nwstdlibext.h" and "nwstdlibext.h". Don't compile/include other files directly!

#ifndef __NW_STDLIB_EXT_STRINGS_IMPLEMENTATION__
#define __NW_STDLIB_EXT_STRINGS_IMPLEMENTATION__

#if __NW_MEMMEM
EXTERN_C const void* memmem(const void* array, size_t array_len, const void* needle, size_t needle_len)
{
    const char* item      = (const char*)array;
    const char* last_item = item + array_len;
    
    while (item < last_item)
    {
        if (memcmp(item, needle, needle_len) == 0)
        {
            return item;
        }
        
        item += needle_len;
    }
    
    return 0;
}
#endif

#if __NW_ITOA
char* itoa(int value, char* result, int base)
{
    // check that the base if valid
    if ((base < 2) || (base > 36))
    {
        *result = 0;
        return result;
    }
    
    char* s1 = result;
    char* s2 = result;
    int q, r;
    char char_values[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    
    if (value < 0)
    {
        value = value * (-1);
        *s1   = '-';
        s1++;
        s2++;
    }
    
    do
    {
        q   = (int) value / base;
        r   = value % base;
        *s1 = char_values[r];
        s1++;
        value = q;
    }
    while(value > 0);
    
    *s1 = '\0';
    s1--;
    
    //Reverse
    char  tmp;
    while(s2 < s1)
    {
        tmp = *s1;
        *s1 = *s2;
        *s2 = tmp;
        
        s1--;
        s2++;
    }
    
    return result;
};

#endif //#if __NW_ITOA

const char* sscandigit(const char* str, long long* i, double* d, bool* is_double)
{
    int        n = 0;
    long long _i = 0;
    double    _d = 0.0f;
    bool      _is_double = false;
    
    if (sscanf(str, "%lld%n", &_i, &n) > 0)
    {
        str += n;
        
        if (*str != 0)
        {
            const char* decimal_point = localeconv()->decimal_point;
            if (strcmp(str, decimal_point) == 0)
            {
                _is_double = true;
            }
        }
        
        if ((_is_double == true) || (*str == '.'))
        {
            str++;
            if (sscanf(str, "%lf%n", &_d, &n) > 0)
            {
                str += n;
                
                double divider = pow(10, n);
                _d = _d/divider;
                _d = _d + (double)(_i);
                _is_double = true;
            }
            else
            {
                str--;
            }
        }
        
        if (_is_double)
        {
            *d = _d;
            *i = (long long)(_d);
        }
        else
        {
            *i = _i;
            *d = (double)(_i);
        }
    }
    
    if (is_double != NULL) *is_double = _is_double;
    
    return str;
}

EXTERN_C const char* strbracketpair(const char* str)
{
    char open  = 0;
    char close = 0;
    
    if (str == NULL) { return NULL; }
    
    open = str[0];
    switch (open)
    {
        case '(':  close = ')';  break;
        case '[':  close = ']';  break;
        case '{':  close = '}';  break;
        case '<':  close = '>';  break;
        case '"':  close = '"';  break;
        case '\'': close = '\''; break;
            
        default: return NULL;
    }

    size_t open_counts = 1;
    const char* close_pos = str;
    const char* open_pos  = str;
    
    do
    {
        close_pos = strlchr(open_pos+1, close);
        open_pos  = strlchr(open_pos+1, open);
        
        //close must be less then open.
        //close may be identical to open, if open and close chars are equivalent.
        if ((open_pos == NULL) || (close_pos <= open_pos))
        {
            open_counts--;
            open_pos = close_pos;
        }
        else
        {
            open_counts++;
        }
    }
    while ((open_counts > 0) && (close_pos != NULL) && (open_pos != NULL));
    
    close_pos = (open_counts == 0)?close_pos:NULL;
    return (char*)close_pos;
}

/*
EXTERN_C unsigned long strcount (const char *string, const char *countset)
{
    unsigned long count = 0;
    
    while (*string != 0)
    {
        if (strlchr(countset,  *string) != NULL)
        {
            count++;
        }
        
        string++;
    }
    
    return count;
}
*/

EXTERN_C size_t strcount(const char* str, const char* set, char* (*set_fun)(const char*, const char*))
{
    unsigned long count = 0;
    const char* p = str;
    
    while (*p != 0)
    {
        p = set_fun(p, set);
        
        if (p != NULL)
        {
            count++;
        }
        else
        {
            break;
        }
        
        if (*p != 0) { p++; }
    };
    
    return count;
}

EXTERN_C size_t strncount(const char* str, const char* set, size_t n, char* (*set_fun)(const char*, const char*))
{
    unsigned long count = 0;
    const char* p = str;
    
    while ((*p != 0) && ((p - str) < n) && (n > 0))
    {
        p = set_fun(p, set);
        
        if ((p != NULL) && ((p - str) < n))
        {
            count++;
        }
        else
        {
            break;
        }
        
        if (*p != 0) { p++; }
    };
    
    return count;
}


EXTERN_C char* strpskip (const char *string, const char *skipset)
{
    while (strlchr(skipset,  *string) != NULL)
    {
        string++;
    }
    
    return (char*)string;
}

EXTERN_C char* strpskip_count(const char *string, const char *skipset, const char* countset, size_t* count)
{
    const char* c = strlchr(skipset,  *string);
    
    if (count != NULL)
    {
        *count = 0;
    }
    
    while (c != NULL)
    {
        string++;
    
        if (count != NULL)
        {
            if (strlchr(countset, *c) != NULL)
            {
                (*count)++;
            }
        }
        
        c = strlchr(skipset,  *string);
    }
    
    return (char*)string;
}



EXTERN_C char* strpskip_r (const char *string, const char *skipset, const char* st_string)
{
    while ((string >= st_string) && (strlchr(skipset,  *string) != NULL))
    {
        string--;
    }
    
    if (string < st_string)
    {
        return NULL;
    }
    else
    {
        return (char*)string;
    }
}

EXTERN_C char* strpbrk_r(const char *string, const char *brkset, const char* st_string)
{
    while ((string >= st_string) && (strlchr(brkset,  *string) == NULL))
    {
        string--;
    }
    
    if (string < st_string)
    {
        return NULL;
    }
    else
    {
        return (char*)string;
    }
}

EXTERN_C char* strlchr(const char* string, char chr)
{
    while (*string != chr)
    {
        if (*(++string) == 0)
        {
            return NULL;
        }
    }
    
    return (char*)string;
}


EXTERN_C size_t strncount_strpbrk(const char* str, const char* set, size_t n)
{
	char* (*f)(const char*, const char*) = strpbrk;
	return strncount(str, set, n, f);
};

EXTERN_C size_t strncount_strpskip(const char* str, const char* set, size_t n)
{
	return strncount(str, set, n, strpskip);
};

#endif //#ifndef __NW_STDLIB_EXT_STRINGS_IMPLEMENTATION__

#endif //#if __NW_STDLIB_EXT_IMPLEMENTATION

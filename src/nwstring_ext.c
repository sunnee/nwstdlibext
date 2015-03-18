//
//  nwstdlib_ext
//
//  Created by Alexandr Kavalchuk on 26.05.13.
//  Copyright (c) 2013 Alexandr Kavalchuk. All rights reserved.
//

#include "nwstring_ext.h"


EXTERN_C const void* arritem(const void* array, size_t array_len, const void* needle, size_t needle_len)
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

EXTERN_C size_t strcount(const char* str, const char* set, char* (__cdecl *set_fun)(const char*, const char*))
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
	char* (__cdecl *f)(const char*, const char*) = strpbrk;
	return strncount(str, set, n, f);
};

EXTERN_C size_t strncount_strpskip(const char* str, const char* set, size_t n)
{
	return strncount(str, set, n, strpskip);
};
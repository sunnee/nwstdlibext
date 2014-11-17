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

EXTERN_C const char* strpskip (const char *string, const char *skipset)
{
    while (strlchr(skipset,  *string) != NULL)
    {
        string++;
    }
    
    return (char*) string;
}

EXTERN_C const char* strpskip_r (const char *string, const char *skipset, const char* st_string)
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
        return string;
    }
}

EXTERN_C const char* strpbrk_r(const char *string, const char *brkset, const char* st_string)
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
        return string;
    }
}

EXTERN_C const char* strlchr(const char* string, char chr)
{
    while (*string != chr)
    {
        if (*(++string) == 0)
        {
            return NULL;
        }
    }
    
    return string;
}
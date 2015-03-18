//
//  NW STRINGS
//
//  Created by Alexandr Kavalchuk on 14.11.14.
//  Copyright (c) 2006-2015 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#include "nwunstd.h"

/*
#if __NW_STRPBRK

EXTERN_C char* strpbrk(const char *string, const char *brkset)
{
	while ((*string != 0) && (strlchr(brkset, *string) == NULL))
	{
		string++;
	}

	if (*string == 0)
	{
		return NULL;
	}
	else
	{
		return (char*)string;
	}
}

#endif
*/

EXTERN_C void string_format_free(char** str)
{
    if (str != NULL)
    {
        if (*str != NULL)
        {
            free(*str);
            *str = NULL;
        }
    }
}

EXTERN_C char* string_format_make(const char* format, ...)
{
    va_list ap;
    char* result = NULL;
    
    va_start(ap, format);
    result = string_vformat_make(format, ap);
    va_end(ap);
    
    return result;
}

EXTERN_C char* string_vformat_make(const char* format, va_list ap)
{
    size_t s = 0;
    size_t n = 0;
    char* buffer = NULL;
    
    if (format != NULL)
    {
        s = strnlen(format, 2048);
    }
    
    if (s > 0)
    {
        buffer = malloc(s);
    }

    if (buffer != NULL)
    {
        n = vsnprintf(buffer, s, format, ap);
    }
    
    if (n > s)
    {
        s = (n/16 + 1)*16;
        char* buffer2 = realloc(buffer, s);
        
        if (buffer2 != NULL)
        {
            buffer = buffer2;
            n = vsnprintf(buffer, s, format, ap);
        }
        else
        {
            string_format_free(&buffer);
        }
    }
    
    if (n > s)
    {
        string_format_free(&buffer);
    }

    return buffer;
}


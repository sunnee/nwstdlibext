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

#if __NW_STDLIB_EXT_IMPLEMENTATION
//#error Use only "nwstdlibext.h" and "nwstdlibext.h". Don't compile/include other files directly!

#ifndef __NW_STDLIB_EXT_LOG_IMPLEMENTATION__
#define __NW_STDLIB_EXT_LOG_IMPLEMENTATION__

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

EXTERN_C void debug_out(const char* str)
{
    if (str != NULL)
    {
#ifdef NW_COMPILER_MSVC
        OutputDebugStringA(str);
#elif NW_SYSTEM_APPLE
        fprintf(stderr, "%s", str);
#else
        fprintf(stderr, "%s", str);
#endif
    }
}

EXTERN_C void debug_out_vformat(const char* format, va_list ap)
{
#ifdef NW_COMPILER_MSVC
    
    char* buffer = string_vformat_make(format, ap);
    debug_out(buffer);
    string_format_free(&buffer);
    
#elif NW_SYSTEM_APPLE
    
    vfprintf(stderr, format, ap);
    
#else
    
    vfprintf(stderr, format, ap);
    
#endif
}

EXTERN_C void debug_out_format(const char* format, ...)
{
    va_list ap;
    
    va_start(ap, format);
    debug_out_vformat(format, ap);
    va_end(ap);
}

#endif //__NW_STDLIB_EXT_LOG_IMPLEMENTATION__

#endif //#if __NW_STDLIB_EXT_IMPLEMENTATION

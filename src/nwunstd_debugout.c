//
//  NW DEBUG OUT
//
//  Created by Alexandr Kavalchuk on 11.12.14.
//  Copyright (c) 2006-2015 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#include "nwunstd.h"

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
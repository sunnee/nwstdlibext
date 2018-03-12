//
//  NW STDLIB EXTENSIONS
//
//  Copyright (c) 2006-2018 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#ifndef __NW_STDLIB_EXT_LOG__
#define __NW_STDLIB_EXT_LOG__

EXTERN_C void string_format_free(char** str);
EXTERN_C char* string_format_make(const char* format, ...);
EXTERN_C char* string_vformat_make(const char* format, va_list ap);

EXTERN_C void debug_out(const char* str);
EXTERN_C void debug_out_vformat(const char* format, va_list ap);
EXTERN_C void debug_out_format(const char* format, ...);

#endif //#ifndef __NW_STDLIB_EXT_LOG__

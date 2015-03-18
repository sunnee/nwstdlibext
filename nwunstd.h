//
//  NW UNSTANDART EXTENSIONS
//
//  Copyright (c) 2006-2015 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#ifndef __NW_UNSTD__
#define __NW_UNSTD__

#include "nwstdlibext.h"
#include "nwplatform.h"

EXTERN_C void* base64_decode(const char *data, size_t length, size_t *out_length);
EXTERN_C char* base64_encode(const void *data, size_t length, size_t *out_length, bool separate_lines);

#if !(NW_SYSTEM_WINDOWS)
    #define __NW_ITOA 1
    EXTERN_C char* itoa(int value, char* result, int base);
#endif

EXTERN_C const char* sscandigit(const char* str, long long* i, double* d, bool* is_double);

#if NW_SYSTEM_WINDOWS
	#define strncasecmp(x,y,z) _strnicmp(x,y,z)
#endif

/*
#if NW_SYSTEM_WINDOWS
//#define __NW_STRPBRK 1
    //EXTERN_C char* strpbrk(const char *string, const char *brkset);
#endif
*/

#if NW_SYSTEM_WINDOWS
    #define __NW_SECURE_MEMSET  1
    #define __NW_SECURE_ZEROMEM 0

    #define zeromem_s(P,S) SecureZeroMemory((P), (S))

#elif NW_SYSTEM_APPLE

    #if ((MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_9) || (__IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_7_0))
        #define __NW_SECURE_MEMSET 0
    #else
        #define __NW_SECURE_MEMSET 1
    #endif

    #define __NW_SECURE_ZEROMEM 1

#else
    #define __NW_SECURE_MEMSET  1
    #define __NW_SECURE_ZEROMEM 1
#endif


#if __NW_SECURE_MEMSET
    EXTERN_C void* nw_memset_s(void *s, rsize_t smax, int c, rsize_t n);
    #define memset_s nw_memset_s
#endif

#if __NW_SECURE_ZEROMEM
    #define zeromem_s(P,S) memset_s((P), (S), 0, (S))
#endif

#include "nwunstd_bitmanipulations.h"

EXTERN_C void string_format_free(char** str);
EXTERN_C char* string_format_make(const char* format, ...);
EXTERN_C char* string_vformat_make(const char* format, va_list ap);

EXTERN_C void debug_out(const char* str);
EXTERN_C void debug_out_vformat(const char* format, va_list ap);
EXTERN_C void debug_out_format(const char* format, ...);

#include "nwunstd_lsearch.h"

#endif /* __NW_UNSTD__ */

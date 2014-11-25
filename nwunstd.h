//
//  nwunstd.h
//  iSmartThemeExample
//
//  Created by Alexandr Kavalchuk on 14.11.14.
//  Copyright (c) 2014 nwaves. All rights reserved.
//

#ifndef __NW_UNSTD__
#define __NW_UNSTD__

#include "nwstdlibext.h"
#include "nwmacro.h"

EXTERN_C void* base64_decode(const char *data, size_t length, size_t *out_length);
EXTERN_C char* base64_encode(const void *data, size_t length, size_t *out_length, bool separate_lines);

#ifndef itoa
    #define __NW_ITOA 1
    char* itoa(int value, char* result, int base);
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

#include "nwbitsmanipulations.h"

#ifdef NW_COMPILER_MSVC
    #define DEBUG_OUT(STR) OutputDebugStringA(STR)
#elif NW_SYSTEM_APPLE
    #define DEBUG_OUT(STR) fprintf(stderr, "%s", (STR))
#endif




#endif /* __NW_UNSTD__ */

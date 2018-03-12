//
//  NW STDLIB EXTENSIONS
//
//  Copyright (c) 2006-2018 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#ifndef __NW_STDLIB_EXT_SECURE__
#define __NW_STDLIB_EXT_SECURE__

#if NW_SYSTEM_WINDOWS

#   define __NW_SECURE_MEMSET  1
#   define __NW_SECURE_ZEROMEM 0

#   define zeromem_s(P,S) SecureZeroMemory((P), (S))

#elif NW_SYSTEM_APPLE

#   if ((MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_9) || (__IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_7_0))
#       define __NW_SECURE_MEMSET 0
#   else
#       define __NW_SECURE_MEMSET 1
#   endif

#   define __NW_SECURE_ZEROMEM 1

#else

#   define __NW_SECURE_MEMSET  1
#   define __NW_SECURE_ZEROMEM 1

#endif

#if __NW_SECURE_MEMSET
    EXTERN_C void* nw_memset_s(void *s, rsize_t smax, int c, rsize_t n);
#   define memset_s nw_memset_s
#endif

#if __NW_SECURE_ZEROMEM
#   define zeromem_s(P,S) memset_s((P), (S), 0, (S))
#endif

#endif /* __NW_STDLIB_EXT_SECURE__ */

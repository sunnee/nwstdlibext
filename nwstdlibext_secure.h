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

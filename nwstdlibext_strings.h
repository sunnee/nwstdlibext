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

#ifndef __NW_STDLIB_EXT_STRINGS__
#define __NW_STDLIB_EXT_STRINGS__

/*
 #if NW_SYSTEM_WINDOWS
 //#define __NW_STRPBRK 1
 //EXTERN_C char* strpbrk(const char *string, const char *brkset);
 #endif
 */

#if  !defined(memmem) && !NW_SYSTEM_UNIX
    #define __NW_MEMMEM  1
    EXTERN_C const void* memmem(const void* array, size_t array_len, const void* needle, size_t needle_len);
#endif

#if !NW_SYSTEM_WINDOWS
#define __NW_ITOA 1
    EXTERN_C char* itoa(int value, char* result, int base);
#endif

EXTERN_C const char* sscandigit(const char* str, long long* i, double* d, bool* is_double);

#if NW_SYSTEM_WINDOWS
#   define strncasecmp(x,y,z) _strnicmp(x,y,z)
#endif

EXTERN_C const char* strbracketpair(const char* str);

//EXTERN_C unsigned long strcount (const char *string, const char *countset);
//EXTERN_C unsigned long strncount (const char *string, const char *countset, size_t n);
EXTERN_C size_t strcount( const char* str, const char* set,           char* (*set_fun)(const char*, const char*));
EXTERN_C size_t strncount(const char* str, const char* set, size_t n, char* (*set_fun)(const char*, const char*));

EXTERN_C char* strpskip (const char *string, const char *skipset);
EXTERN_C char* strpskip_count(const char *string, const char *skipset, const char* countset, size_t* count);
EXTERN_C char* strpskip_r (const char *string, const char *skipset, const char* st_string);

EXTERN_C char* strpbrk_r(const char *string, const char *brkset, const char* st_string);

EXTERN_C char* strlchr(const char* string, char chr);

EXTERN_C size_t strncount_strpbrk(const char* str, const char* set, size_t n);
EXTERN_C size_t strncount_strpskip(const char* str, const char* set, size_t n);

#endif /* __NW_STDLIB_EXT_STRINGS__ */

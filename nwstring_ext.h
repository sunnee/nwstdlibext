//
//  NW STRING EXT
//
//  Copyright (c) 2006-2014 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#ifndef __NW_STRING_EXT__
#define __NW_STRING_EXT__

#include "nwstdlibext.h"

EXTERN_C const void* arritem(const void* array, size_t array_len, const void* needle, size_t needle_len);
EXTERN_C const char* strbracketpair(const char* str);

//EXTERN_C unsigned long strcount (const char *string, const char *countset);
//EXTERN_C unsigned long strncount (const char *string, const char *countset, size_t n);
EXTERN_C size_t strcount(const char* str, const char* set, char* (__cdecl *set_fun)(const char*, const char*));
EXTERN_C size_t strncount(const char* str, const char* set, size_t n, char* (*set_fun)(const char*, const char*));

EXTERN_C char* strpskip (const char *string, const char *skipset);
EXTERN_C char* strpskip_count(const char *string, const char *skipset, const char* countset, size_t* count);
EXTERN_C char* strpskip_r (const char *string, const char *skipset, const char* st_string);

EXTERN_C char* strpbrk_r(const char *string, const char *brkset, const char* st_string);

EXTERN_C char* strlchr(const char* string, char chr);

EXTERN_C size_t strncount_strpbrk(const char* str, const char* set, size_t n);
EXTERN_C size_t strncount_strpskip(const char* str, const char* set, size_t n);


EXTERN_C INLINE_FORCE bool is_quote(char chr)
{
    return ((chr == '"') || (chr == '\''));
}

EXTERN_C INLINE_FORCE int is_bracket(char chr)
{
    if ((chr == '(') || (chr == '[') || (chr == '{') || (chr == '<')) return -1;
    if ((chr == ')') || (chr == ']') || (chr == '}') || (chr == '>')) return 1;
    
    return 0;
}

EXTERN_C INLINE_FORCE bool is_char(char chr)
{
    return ((chr >= 'a') && (chr <= 'z')) ||
    ((chr >= 'A') && (chr <= 'Z'));
}

EXTERN_C INLINE_FORCE bool is_digit(char chr)
{
    return ((chr >= '0') && (chr <= '9'));
}

EXTERN_C INLINE_FORCE bool is_hex(char chr)
{
    return ((chr >= 'a') && (chr <= 'f')) || ((chr >= 'A') && (chr <= 'F')) || ((chr >= '0') && (chr <= '9'));
}

EXTERN_C INLINE_FORCE bool is_space(char chr)
{
    //\s == \x20, [\t = \x09, \n = \x0A, \v = \x0B, \f = \x0C, \r = \x0D]
    return (chr == '\x20') || ((chr >= '\t') && (chr <= '\r'));
}



#endif /* __NW_STRING_EXT__ */

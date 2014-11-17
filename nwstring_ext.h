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

EXTERN_C const char* strpskip (const char *string, const char *skipset);
EXTERN_C const char* strpskip_r (const char *string, const char *skipset, const char* st_string);

EXTERN_C const char* strpbrk_r(const char *string, const char *brkset, const char* st_string);

EXTERN_C const char* strlchr(const char* string, char chr);

EXTERN_C inline bool is_quote(char chr)
{
    return ((chr == '"') || (chr == '\''));
}

EXTERN_C inline int is_bracket(char chr)
{
    if ((chr == '(') || (chr == '[') || (chr == '{') || (chr == '<')) return -1;
    if ((chr == ')') || (chr == ']') || (chr == '}') || (chr == '>')) return 1;
    
    return 0;
}

EXTERN_C inline bool is_char(char chr)
{
    return ((chr >= 'a') && (chr <= 'z')) ||
    ((chr >= 'A') && (chr <= 'Z'));
}

EXTERN_C inline bool is_digit(char chr)
{
    return ((chr >= '0') && (chr <= '9'));
}

EXTERN_C inline bool is_space(char chr)
{
    //\s == \x20, [\t = \x09, \n = \x0A, \v = \x0B, \f = \x0C, \r = \x0D]
    return (chr == '\x20') || ((chr >= '\t') && (chr <= '\r'));
}



#endif /* __NW_STRING_EXT__ */

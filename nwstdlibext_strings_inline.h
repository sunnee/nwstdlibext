//
//  NW STDLIB EXTENSIONS
//
//  Copyright (c) 2006-2018 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#ifndef __NW_STDLIB_EXT_STRINGS_INLINE__
#define __NW_STDLIB_EXT_STRINGS_INLINE__

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

#endif /* __NW_STDLIB_EXT_STRINGS_INLINE__ */

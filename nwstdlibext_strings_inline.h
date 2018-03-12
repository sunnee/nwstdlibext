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

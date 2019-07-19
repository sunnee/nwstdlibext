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

#ifndef __NW_STDLIB_EXT_LOG__
#define __NW_STDLIB_EXT_LOG__

EXTERN_C void string_format_free(char** str);
EXTERN_C char* string_format_make(const char* format, ...);
EXTERN_C char* string_vformat_make(const char* format, va_list ap);

EXTERN_C void debug_out(const char* str);
EXTERN_C void debug_out_vformat(const char* format, va_list ap);
EXTERN_C void debug_out_format(const char* format, ...);

#endif //#ifndef __NW_STDLIB_EXT_LOG__

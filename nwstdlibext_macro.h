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

#ifndef __NW_STDLIB_EXT_MACRO__
#define __NW_STDLIB_EXT_MACRO__

#define IS_VALUE_AT_RANGE  (value, min, max) (((value) >= (min)) && ((value) <= (max)))
#define VALUE_CLIP_TO_RANGE(value, min, max) MAX((min), MIN((max), (value)))

#define VALUE_IN_ARRAY(value, type, array)  memmem(array, sizeof(array), &value, sizeof(value))

#define VALUE_IN_LIST(value, type, ...)     (VALUE_IN_ARRAY((value),type,ARRAY_WITH_TYPE(type,__VA_ARGS__)) != NULL)
#define VALUE_NOT_IN_LIST(value, type, ...) (VALUE_IN_ARRAY((value),type,ARRAY_WITH_TYPE(type,__VA_ARGS__)) == NULL)

#endif /* __NW_STDLIB_EXT_MACRO__ */

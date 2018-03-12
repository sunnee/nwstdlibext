//
//  NW STDLIB EXTENSIONS
//
//  Copyright (c) 2006-2018 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#ifndef __NW_STDLIB_EXT_MACRO__
#define __NW_STDLIB_EXT_MACRO__

#define IS_VALUE_AT_RANGE  (value, min, max) (((value) >= (min)) && ((value) <= (max)))
#define VALUE_CLIP_TO_RANGE(value, min, max) MAX((min), MIN((max), (value)))

#define VALUE_IN_ARRAY(value, type, array)  memmem(array, sizeof(array), &value, sizeof(value))

#define VALUE_IN_LIST(value, type, ...)     (VALUE_IN_ARRAY((value),type,ARRAY_WITH_TYPE(type,__VA_ARGS__)) != NULL)
#define VALUE_NOT_IN_LIST(value, type, ...) (VALUE_IN_ARRAY((value),type,ARRAY_WITH_TYPE(type,__VA_ARGS__)) == NULL)

#endif /* __NW_STDLIB_EXT_MACRO__ */

//
//  NW STDLIB EXTENSIONS
//
//  Copyright (c) 2006-2018 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#ifndef __NW_STDLIB_EXT_BASE64__
#define __NW_STDLIB_EXT_BASE64__

EXTERN_C void* base64_decode(const char *data, size_t length, size_t *out_length);
EXTERN_C char* base64_encode(const void *data, size_t length, size_t *out_length, bool separate_lines);

#endif /* __NW_STDLIB_EXT_BASE64__ */

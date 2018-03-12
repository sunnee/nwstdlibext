//
//  NW STDLIB EXTENSIONS
//
//  Copyright (c) 2006-2018 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#include "nwstdlibext.h"

#ifndef __NW_STDLIB_EXT_IMPLEMENTATION
#error Use only "nwstdlibext.h" and "nwstdlibext.h". Don't compile/include other files directly!
#endif

#ifndef __NW_STDLIB_EXT_SECURE_IMPLEMENTATION__
#define __NW_STDLIB_EXT_SECURE_IMPLEMENTATION__

#if __NW_SECURE_MEMSET
EXTERN_C void* nw_memset_s(void *s, rsize_t smax, int c, rsize_t n)
{
    volatile unsigned char *p = s;
    
    if (p == NULL)
    {
        errno = EINVAL;
        return (void*)-1;
    }
    else if (n > smax)
    {
        errno = EOVERFLOW;
        return (void*)-1;
    }
    else if ((n > RSIZE_MAX) || (smax > RSIZE_MAX))
    {
        errno = E2BIG;
        return (void*)-1;
    }
    
    while (n--)
    {
        *p++ = c;
    }
    
    return s;
}
#endif

#endif //#ifndef __NW_STDLIB_EXT_SECURE_IMPLEMENTATION__

//
//  NW SECURE
//
//  Created by Alexandr Kavalchuk on 14.11.14.
//  Copyright (c) 2006-2015 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#include "nwunstd.h"

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
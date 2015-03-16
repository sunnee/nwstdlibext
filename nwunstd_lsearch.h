//
//  nwunstd_lsearch.c
//  DataTransfer
//
//  Created by Alexandr Kavalchuk on 12.03.15.
//  Copyright (c) 2015 nwaves. All rights reserved.
//

#ifndef __NW_UNSTD_LSEARCH__
#define __NW_UNSTD_LSEARCH__

/*
EXTERN_C INLINE_FORCE void* lsearch(const void* key, const void* base, size_t num, size_t size, int (* comparator) (const void*, const void*))
{
    const void* item = base;
    
    while (num != 0)
    {
        if (comparator(key, item) == 0)
        {
            return (void*)item;
        }
        
        item = item + size;
        num  = num - 1;
    }
    
    return NULL;
}
*/

#endif //__NW_UNSTD_LSEARCH__
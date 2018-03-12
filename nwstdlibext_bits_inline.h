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

#ifndef __NW_STDLIB_EXT_BITS_INLINE__
#define __NW_STDLIB_EXT_BITS_INLINE__

#if NW_COMPILER_MSVC
    #include <intrin.h>
    #define MS_BIT_MANIPULATIONS 1
#endif

#if NW_SYSTEM_APPLE || NW_SYSTEM_BSD
    #include <strings.h>
    #define BSD_BIT_MANIPULATIONS 1
#endif


EXTERN_C INLINE_FORCE int lowerBit8(uint8_t x)
{
    if (x == 0) {return 8;};
    
    int n = 0;
    if ((x & 0x0F) == 0)  {n +=  4; x >>= 4; }
    if ((x & 0x03) == 0)  {n +=  2; x >>= 2; }
    if ((x & 0x01) == 0)  {n +=  1; /*x >>= 1;*/ }
    
    return n;
}

EXTERN_C INLINE_FORCE int lowerBit16(uint16_t x)
{
    if (x == 0) {return 16;};
    
    int n = 0;
    if ((x & 0x00FF) == 0)  {n +=  8; x >>= 8; }
    if ((x & 0x000F) == 0)  {n +=  4; x >>= 4; }
    if ((x & 0x0003) == 0)  {n +=  2; x >>= 2; }
    if ((x & 0x0001) == 0)  {n +=  1; /*x >>= 1;*/ }
    
    return n;
}


#if BSD_BIT_MANIPULATIONS

	EXTERN_C INLINE_FORCE int lowerBit32(uint32_t x)
    {
        int n = 33;
        if (x != 0) { n = ffsl(x); }
        return (n-1);
    };

#elif MS_BIT_MANIPULATIONS

	EXTERN_C INLINE_FORCE int lowerBit32(uint32_t x)
    {
        unsigned long n = 32;
        if (_BitScanForward(&n,x) == 0) { n = 32; }
        return (int)n;
    };

#else

	EXTERN_C INLINE_FORCE int lowerBit32(uint32_t x)
    {
        if (x == 0) {return 32;};
        
        int n = 0;
        if ((x & 0x0000FFFF) == 0)  {n += 16; x >>= 16;}
        if ((x & 0x000000FF) == 0)  {n +=  8; x >>= 8; }
        if ((x & 0x0000000F) == 0)  {n +=  4; x >>= 4; }
        if ((x & 0x00000003) == 0)  {n +=  2; x >>= 2; }
        if ((x & 0x00000001) == 0)  {n +=  1; /*x >>= 1;*/ }
        
        return n;
    }

#endif

EXTERN_C INLINE_FORCE int lowerBit64(uint64_t x)
{
    if (x == 0) {return 64;};
    
    int n = 0;
    if ((x & 0x00000000FFFFFFFF) == 0)  {n += 32; x >>= 32;}
    if ((x & 0x000000000000FFFF) == 0)  {n += 16; x >>= 16;}
    if ((x & 0x00000000000000FF) == 0)  {n +=  8; x >>= 8; }
    if ((x & 0x000000000000000F) == 0)  {n +=  4; x >>= 4; }
    if ((x & 0x0000000000000003) == 0)  {n +=  2; x >>= 2; }
    if ((x & 0x0000000000000001) == 0)  {n +=  1; /*x >>= 1;*/ }
    
    return n;
}

EXTERN_C INLINE_FORCE int higherBit8(uint8_t x)
{
    int n = 8;
    if (x == 0) {return n;};
    
    if ((x & 0xF0) == 0)  {n -=  4; x <<= 4; }
    if ((x & 0xC0) == 0)  {n -=  2; x <<= 2; }
    if ((x & 0x80) == 0)  {n -=  1; /*x <<= 1;*/ }
    
    return n;
}

EXTERN_C INLINE_FORCE int higherBit16(uint16_t x)
{
    int n = 16;
    if (x == 0) {return n;};
    
    if ((x & 0xFF00) == 0)  {n -=  8; x <<= 8; }
    if ((x & 0xF000) == 0)  {n -=  4; x <<= 4; }
    if ((x & 0xC000) == 0)  {n -=  2; x <<= 2; }
    if ((x & 0x8000) == 0)  {n -=  1; /*x <<= 1;*/ }
    
    return n;
}

#if BSD_BIT_MANIPULATIONS

	EXTERN_C INLINE_FORCE int higherBit32(uint32_t x)
    {
        int n = 33;
        if (x != 0) { n = flsl(x); };
        return (n-1);
    };

#elif MS_BIT_MANIPULATIONS

    EXTERN_C INLINE_FORCE int higherBit32(uint32_t x)
    {
        unsigned long n = 32;
        if (_BitScanReverse(&n,x) == 0) { n = 32; }
        return n;
    };

#else

	EXTERN_C INLINE_FORCE int higherBit32(uint32_t x)
    {
        int n = 32;
        if (x == 0) {return n;};
        
        if ((x & 0xFFFF0000) == 0)  {n -= 16; x <<= 16;}
        if ((x & 0xFF000000) == 0)  {n -=  8; x <<= 8; }
        if ((x & 0xF0000000) == 0)  {n -=  4; x <<= 4; }
        if ((x & 0xC0000000) == 0)  {n -=  2; x <<= 2; }
        if ((x & 0x80000000) == 0)  {n -=  1; /*x <<= 1;*/ }
        
        return n;
    }

#endif

EXTERN_C INLINE_FORCE int higherBit64(uint64_t x)
{
    int n = 64;
    if (x == 0) {return n;};
    
    if ((x & 0xFFFFFFFF00000000) == 0)  {n -= 32; x <<= 32;}
    if ((x & 0xFFFF000000000000) == 0)  {n -= 16; x <<= 16;}
    if ((x & 0xFF00000000000000) == 0)  {n -=  8; x <<= 8; }
    if ((x & 0xF000000000000000) == 0)  {n -=  4; x <<= 4; }
    if ((x & 0xC000000000000000) == 0)  {n -=  2; x <<= 2; }
    if ((x & 0x8000000000000000) == 0)  {n -=  1; /*x <<= 1;*/ }
    
    return n;
}

/*
#define TWO(c)  (1u << (c))

#define MASK(c) (((unsigned int)(-1)) / (TWO(TWO(c)) + 1u))

#define COUNT(x,c) ((x) & MASK(c)) + (((x) >> (TWO(c))) & MASK(c))

int bitcount (unsigned int n)
{
    n = COUNT(n, 0) ;
    n = COUNT(n, 1) ;
    n = COUNT(n, 2) ;
    n = COUNT(n, 3) ;
    n = COUNT(n, 4) ;
    // n = COUNT(n, 5) ;    for 64-bit integers
    return n ;
}

EXTERN_C INLINE int count32(uint32_t x)
{
   // count bits of each 2-bit chunk
   x  = x - ((x >> 1) & 0x55555555);
    
   // count bits of each 4-bit chunk
   x  = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    
   // count bits of each 8-bit chunk
   x  = x + (x >> 4);
    
   // mask out junk
   x &= 0xF0F0F0F;
    
   // add all four 8-bit chunks
   return (x * 0x01010101) >> 24;
}
*/

#endif //__NW_STDLIB_EXT_BITS_INLINE__

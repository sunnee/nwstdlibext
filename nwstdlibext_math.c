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

#include "nwstdlibext.h"

#if __NW_STDLIB_EXT_IMPLEMENTATION
//#error Use only "nwstdlibext.h" and "nwstdlibext.h". Don't compile/include other files directly!

#ifndef __NW_STDLIB_EXT_MATH_IMPLEMENTATION__
#define __NW_STDLIB_EXT_MATH_IMPLEMENTATION__

EXTERN_C double accuratemeand(double v1, double v2)
{
    double result = 0.0;
    
    if ((v1 != 0) && (v2 != 0))
    {
        result = (v1 + v2)/2.0;
    }
    else if (v1 != 0)
    {
        result = v1;
    }
    else if (v2 != 0)
    {
        result = v2;
    }
    
    return result;
}

EXTERN_C float accuratemeanf(float v1, float v2)
{
    float result = 0.0;
    
    if ((v1 != 0) && (v2 != 0))
    {
        result = (v1 + v2)/2.0;
    }
    else if (v1 != 0)
    {
        result = v1;
    }
    else if (v2 != 0)
    {
        result = v2;
    }
    
    return result;
}

/*Accuracy about 20 sec*/
EXTERN_C double asincosd(double dx, double dy)
{
    double ax = acos(dx);
    double ay = asin(dy);
    double a = 0.0;
    
    if (dy < 0)
    {
        ax = (M_PI*2.0) - ax;
    }
    
    if (dx < 0)
    {
        ay = M_PI - ay;
    }
    
    ay = loopvalued(ay, 0.0, M_PI*2.0);
    ax = loopvalued(ax, 0.0, M_PI*2.0);
    
    a = accuratemeand(ax, ay);
    
    return a;
}


/*Accuracy about 20 sec*/
EXTERN_C float  asincosf(float dx, float  dy)
{
    float ax = acosf(dx);
    float ay = asinf(dy);
    float a = 0.0f;
    
    if (dy < 0)
    {
        ax = (M_PI*2.0) - ax;
    }
    
    if (dx < 0)
    {
        ay = M_PI - ay;
    }
    
    ay = loopvaluef(ay, 0.0, M_PI*2.0);
    ax = loopvaluef(ax, 0.0, M_PI*2.0);
    
    a = accuratemeanf(ax, ay);
    
    return a;
}

EXTERN_C float loopvaluef(float value, float min, float max)
{
    while (value > max)
    {
        value = value - max;
    }
    
    while (value < min)
    {
        value = value + max;
    }
    
    return value;
}

EXTERN_C double loopvalued(double value, double min, double max)
{
    while (value > max)
    {
        value = value - max;
    }
    
    while (value < min)
    {
        value = value + max;
    }
    
    return value;
}

EXTERN_C bool comparef(float v1, float v2)
{
    bool equal = false;
    float v1a, v1b, v2a, v2b;
    
    v1a = v1b = v1;
    v2a = v2b = v2;
    
    if (v1 != FLT_MAX) {v1a = nextafterf(v1, FLT_MAX);}
    if (v1 != FLT_MIN) {v1b = nextafterf(v1, FLT_MIN);}
    
    if (v2 != FLT_MAX) {v2a = nextafterf(v2, FLT_MAX);}
    if (v2 != FLT_MIN) {v2b = nextafterf(v2, FLT_MIN);}
    
    equal = (v1a >= v2b) && (v1b <= v2a);
    
    return equal;
}

EXTERN_C bool compared(double v1, double v2)
{
    bool equal = false;
    double v1a, v1b, v2a, v2b;
    
    v1a = v1b = v1;
    v2a = v2b = v2;
    
    if (v1 != DBL_MAX) {v1a = nextafter(v1, DBL_MAX);}
    if (v1 != DBL_MIN) {v1b = nextafter(v1, DBL_MIN);}
    
    if (v2 != DBL_MAX) {v2a = nextafter(v2, DBL_MAX);}
    if (v2 != DBL_MIN) {v2b = nextafter(v2, DBL_MIN);}
    
    equal = (v1a >= v2b) && (v1b <= v2a);
    return equal;
}

#pragma mark Ranges
EXTERN_C float valuefromrangef(float min, float max, float pos)
{
    float range = max - min;
    float value = range*pos + min;
    
    return value;
}

EXTERN_C double valuefromranged(double min, double max, double pos)
{
    double range = max - min;
    double value = range*pos + min;
    
    return value;
}

EXTERN_C float limitrangef(float min, float max, float value)
{
    if (value < min) value = min;
    if (value > max) value = max;
    
    return value;
}

EXTERN_C double limitranged(double min, double max, double value)
{
    if (value < min) value = min;
    if (value > max) value = max;
    
    return value;
}

EXTERN_C float  posinrangef(float min, float max, float value)
{
    float range = max - min;
    float pos = 0.0f;
    
    if (range != 0)
    {
        pos = (value - min)/range;
        pos = limitrangef(0.0f, 1.0f, pos);
    }
    
    return pos;
}

EXTERN_C double posinranged(double min, double max, double value)
{
    double range = max - min;
    double pos = 0.0f;
    
    if (range != 0)
    {
        pos = (value - min)/range;
        pos = limitranged(0.0f, 1.0f, pos);
    }
    
    return pos;
}

EXTERN_C float rad2deg(float rad)
{
    rad = loopvaluef(rad, 0.0f, M_PI*2.0f);
    
    float deg = rad*(180.0f/M_PI);
    
    return deg;
}

EXTERN_C float deg2rad(float deg)
{
    deg = loopvaluef(deg, 0.0f, 360.0f);
    
    float rad = (deg/180.0f)*M_PI;
    
    return rad;
}

EXTERN_C float logxf(float v, float x)
{
    float result = log10f(v)/log10f(x);
    return result;
}

EXTERN_C double logxd(double v, double x)
{
    double result = log10(v)/log10(x);
    return result;
}

EXTERN_C float fixf(float v)
{
    if (v >= 0)
    {
        v = ceilf(v);
    }
    else
    {
        v = floorf(v);
    }
    
    return v;
}

EXTERN_C double fixd(double v)
{
    if (v >= 0)
    {
        v = ceil(v);
    }
    else
    {
        v = floor(v);
    }
    
    return v;
}

EXTERN_C unsigned long long int randllu(unsigned long long int range)
{
    unsigned long long result = 1;
    
    if (range < RAND_MAX)
    {
        result = rand();
    }
    else
    {
        float nf = logxf(range, RAND_MAX);
        nf = fixf(nf);
        
        int n = nf;
        
        for (int i = 0; i < n; i++)
        {
            result = result*rand();
        }
    }
    
    result = result%range;
    
    return result;
}

EXTERN_C unsigned long int  randlu(unsigned long int range)
{
    unsigned long int result = 1;
    
    if (range < RAND_MAX)
    {
        result = rand();
    }
    else
    {
        float nf = logxf(range, RAND_MAX);
        nf = fixf(nf);
        
        int n = nf;
        
        for (int i = 0; i < n; i++)
        {
            result = result*rand();
        }
    }
    
    result = result%range;
    
    return result;
}

#endif //#ifndef __NW_STDLIB_EXT_MATH_IMPLEMENTATION__

#endif //#if __NW_STDLIB_EXT_IMPLEMENTATION

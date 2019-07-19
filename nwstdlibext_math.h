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

#ifndef __NW_STDLIB_EXT_MATH__
#define __NW_STDLIB_EXT_MATH__

EXTERN_C float  asincosf(float  dx, float  dy);
EXTERN_C double asincosd(double dx, double dy);

EXTERN_C bool comparef(float  v1, float  v2);
EXTERN_C bool compared(double v1, double v2);

EXTERN_C float  loopvaluef(float  value, float  min, float  max);
EXTERN_C double loopvalued(double value, double min, double max);

EXTERN_C float  accuratemeanf(float  v1, float  v2);
EXTERN_C double accuratemeand(double v1, double v2);

EXTERN_C float limitrangef(float min, float max, float value);
EXTERN_C double limitranged(double min, double max, double value);

EXTERN_C float  valuefromrangef(float min, float max, float pos);
EXTERN_C double valuefromranged(double min, double max, double pos);

EXTERN_C float  posinrangef(float min, float max, float value);
EXTERN_C double posinranged(double min, double max, double value);

EXTERN_C float rad2deg(float rad);
EXTERN_C float deg2rad(float deg);

EXTERN_C unsigned long long int randllu(unsigned long long int range);
EXTERN_C unsigned long int      randlu(unsigned long int range);

#define isnotnormal(x) (isnan(x) || isinf(x) || ((x) == NAN) || ((x) == HUGE_VALF) || ((x) == HUGE_VALL))

#define FLOAT_COMPARE(value1, value2) comparef(value1, value2)
#define FLOAT_COMPARE_ABSOLUTE(value1, value2, precision) ( ((value1) >= (value2)-precision) && ((value1) <= (value2)+precision) )
#define FLOAT_COMPARE_RELATIVE(value1, value2, precision) FLOAT_COMPARE_ABSOLUTE(value1, value2, (value2)*precision)

#endif //__NW_STDLIB_EXT_MATH__

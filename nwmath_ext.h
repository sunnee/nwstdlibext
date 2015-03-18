//
//  NW MATH EXT
//
//  Copyright (c) 2006-2014 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#ifndef __NW_MATH_EXT__
#define __NW_MATH_EXT__

#include "nwstdlibext.h"

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


#endif //__NW_MATH_EXT__

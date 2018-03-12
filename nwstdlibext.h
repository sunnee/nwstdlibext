//
//  NW STDLIB EXTENSIONS
//
//  Copyright (c) 2006-2018 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#include "nwplatform.h"

#ifndef __NW_STDLIB_EXT__
#define __NW_STDLIB_EXT__

#define NW_STDLIBEXT_MAKE_VERSION(MAJOR,MINOR,PATCH)       ((MAJOR*1000*1000) + (MINOR*1000) + PATCH)

#define NW_STDLIBEXT_VERSION_1_0_0    NW_STDLIBEXT_MAKE_VERSION(1,0,0)
#define NW_STDLIBEXT_VERSION_1_1_0    NW_STDLIBEXT_MAKE_VERSION(1,1,0)

#define NW_STDLIBEXT_CURRENT_VERSION  NW_STDLIBEXT_VERSION_1_1_0

#include "nwstdlibext_macro.h"
#include "nwstdlibext_secure.h"
#include "nwstdlibext_strings.h"
#include "nwstdlibext_strings_inline.h"
#include "nwstdlibext_bits_inline.h"
#include "nwstdlibext_math.h"
#include "nwstdlibext_base64.h"
#include "nwstdlibext_log.h"

#endif /* __NW_STDLIB_EXT__ */

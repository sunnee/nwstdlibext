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

/*
 * gfx_common.h
 *
 *  Created on: Oct 21, 2016
 *      Author: Cody
 */

#ifndef GFX_COMMON_H_
#define GFX_COMMON_H_

#include "types.h"

void inject_palette(vu16* ram, const u16* palette);
void clear_palette(vu16* ram);

void VBLANK();


#endif /* GFX_COMMON_H_ */

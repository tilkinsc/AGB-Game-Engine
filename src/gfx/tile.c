/*
 * gfx_tile.c
 *
 *  Created on: Oct 14, 2016
 *      Author: Cody
 */

#include "tile.h"

#include "../gba.h"
#include "../types.h"

vu16* char_block(u32 block) {
	return (vu16*) (0x6000000 + (block * 0x4000));
}

vu16* screen_block(u32 block) {
	return (vu16*) (0x6000000 + (block * 0x800));
}

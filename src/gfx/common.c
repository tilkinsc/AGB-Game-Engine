/*
 * gfx_common.c
 *
 *  Created on: Oct 21, 2016
 *      Author: Cody
 */

#include "common.h"

#include "../gba.h"
#include "../types.h"

void inject_palette(vu16* ram, const u16* palette) {
	dma16((u16*) palette, (u16*) ram, 256);
}

// we can't use DMA???
void clear_palette(vu16* ram) {
	u32 colors;
	for (colors=0; colors<256; colors++)
		ram[colors] = 0x0;
}

void VBLANK() {
	while (*SLC >= 160);
	while (*SLC < 160);
}

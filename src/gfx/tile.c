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

void load_charblock(vu16* block, const u16* data, u32 width, u32 height) {
	dma16((u16*) data, (u16*) block, (width * height)/2);
}

// TODO: reimplement
void clear_charblock(vu16* block) {
	//dma16static((u16) 0x0, (u16*) block, 16384);
}

void load_screenblock(vu16* block, const u16* map, u32 width, u32 height) {
	dma16((u16*) map, (u16*) block, width * height);
}

// TODO: reimplement
void clear_screenblock(vu16* block) {
	//dma16static((u16) 0x0, (u16*) block, 2048);
}

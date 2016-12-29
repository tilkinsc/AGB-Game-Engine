/*
 * gfx.h
 *
 *  Created on: Oct 14, 2016
 *      Author: Cody
 */

#ifndef GFX_H_
#define GFX_H_

#include "types.h"

vu16* char_block(byte block);
vu16* screen_block(byte block);

void load_charblock(vu16* block, const u16* data, u24 width, u24 height);
void clear_charblock(vu16* block);

void load_screenblock(vu16* block, const u16* map, u24 width, u24 height);
void clear_screenblock(vu16* block);

#endif /* GFX_H_ */

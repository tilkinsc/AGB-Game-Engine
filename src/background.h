/*
 * Background.h
 *
 *  Created on: Nov 3, 2016
 *      Author: Cody
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "types.h"

typedef struct Background {
	vu16* bgc;
	vs16* bgsx;
	vs16* bgsy;
	s16 x; // is this 32 or 16?
	s16 y;
	u32 priority;
	u32 charblock;
	u32 mosaic;
	u32 color_mode;
	u32 screenblock;
	u32 wrapping;
	u32 size;
} Background;

// Background registers
vu16* bg0c;
vu16* bg1c;
vu16* bg2c;
vu16* bg3c;

// Background scroll registers
vs16* bg0xs;
vs16* bg0ys;
vs16* bg1xs;
vs16* bg1ys;
vs16* bg2xs;
vs16* bg2ys;
vs16* bg3xs;
vs16* bg3ys;

void init_background(Background* bg, vu16* bgc, vs16* bgsx, vs16* bgsy, u32 priority, u32 charblock, u32 mosaic, u32 color_mode, u32 screenblock, u32 wrapping, u32 size);

void update_background(Background* bg);
void move_background(Background* bg, s32 x, s32 y);

#endif /* BACKGROUND_H_ */

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
	s24 x;
	s24 y;
	byte priority;
	byte charblock;
	byte mosaic;
	byte color_mode;
	byte screenblock;
	byte wrapping;
	byte size;
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

void init_background(Background* bg, vu16* bgc, vs16* bgsx, vs16* bgsy, byte priority, byte charblock, byte mosaic, byte color_mode, byte screenblock, byte wrapping, byte size);

void update_background(Background* bg);
void move_background(Background* bg, s24 x, s24 y);

#endif /* BACKGROUND_H_ */

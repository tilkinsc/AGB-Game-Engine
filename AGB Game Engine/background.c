/*
 * Background.c
 *
 *  Created on: Nov 3, 2016
 *      Author: Cody
 */

#include "background.h"

#include "types.h"

// Background registers
vu16* bg0c = (vu16*) 0x4000008;
vu16* bg1c = (vu16*) 0x400000a;
vu16* bg2c = (vu16*) 0x400000c;
vu16* bg3c = (vu16*) 0x400000e;

// Background scroll registers
vs16* bg0xs = (vs16*) 0x4000010;
vs16* bg0ys = (vs16*) 0x4000012;
vs16* bg1xs = (vs16*) 0x4000014;
vs16* bg1ys = (vs16*) 0x4000016;
vs16* bg2xs = (vs16*) 0x4000018;
vs16* bg2ys = (vs16*) 0x400001a;
vs16* bg3xs = (vs16*) 0x400001c;
vs16* bg3ys = (vs16*) 0x400001e;

void init_background(Background* bg,
		vu16* bgc, vs16* bgsx, vs16* bgsy,
		byte priority, byte charblock, byte mosaic, byte color_mode, byte screenblock, byte wrapping, byte size) {
	bg->bgc = bgc;
	bg->x = 0;
	bg->y = 0;
	bg->priority = priority;
	bg->charblock = charblock;
	bg->mosaic = mosaic;
	bg->color_mode = color_mode;
	bg->screenblock = screenblock;
	bg->wrapping = wrapping;
	bg->size = size;
}

void update_background(Background* bg) {
	*bg->bgc =
			 bg->priority			| /* priority, 0 highest, 3 lowest		*/
			(bg->charblock << 2)	| /* image data character block			*/
			(bg->mosaic << 6)		| /* mosaic flag						*/
			(bg->color_mode << 7)	| /* color mode, 0 = 16, 1 = 256		*/
			(bg->screenblock << 8)	| /* screen block tile starting index	*/
			(bg->wrapping << 13)	| /* wrapping flag 						*/
			(bg->size << 14);	 	  /* background size, 0 is 256			*/
}

void move_background(Background* bg, s24 x, s24 y) {
	bg->x = x;
	bg->y = y;
	*bg->bgsx = bg->x;
	*bg->bgsy = bg->y;
}

/*
 * gfx.h
 *
 *  Created on: Oct 14, 2016
 *      Author: Cody
 */

#ifndef GFX_H_
#define GFX_H_

#include "types.h"

typedef struct Image {
	u24 width;
	u24 height;
	const u16 *pixels;
} ALIGN(4) Image;

void draw_pixel(vu16* buffer, int x, int y, byte color);
void draw_image(vu16* buffer, Image *image, int x, int y);

void clear_buffer(vu16* buffer, byte color);
vu16* flip_buffer(vu16* buffer);

#endif /* GFX_H_ */

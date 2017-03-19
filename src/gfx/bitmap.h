/*
 * gfx.h
 *
 *  Created on: Oct 14, 2016
 *      Author: Cody
 */

#ifndef GFX_H_
#define GFX_H_

#include "../types.h"

typedef struct Image {
	u32 width;
	u32 height;
	const u16 *pixels;
} ALIGN(4) Image;

void draw_pixel(vu16* buffer, u32 x, u32 y, u16 color);
void draw_image(vu16* buffer, Image *image, u32 x, u32 y);

void clear_buffer(vu16* buffer, u16 color);
vu16* flip_buffer(vu16* buffer);

#endif /* GFX_H_ */

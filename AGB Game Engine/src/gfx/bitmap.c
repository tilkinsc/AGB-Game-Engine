/*
 * gfx_bitmap.c
 *
 *  Created on: Oct 14, 2016
 *      Author: Cody
 */

#include "bitmap.h"

#include "../gba.h"

void draw_pixel(vu16* buffer, s24 x, s24 y, byte color) {
	u16 offset = (x + y * 240) >> 1;
	u16 pixel = buffer[offset];
	if(x & 1) buffer[offset] = (color << 8) | (pixel & 0x00FF);
	else buffer[offset] = (pixel & 0xFF00) | color;
}

void draw_image(vu16* buffer, Image *image, s24 x, s24 y) {
	s24 sx;
	s24 sy;
	for (sx=0; sx<image->width; sx++)
		for(sy=0; sy<image->height; sy++)
			draw_pixel(buffer, x+sx, y+sy, image->pixels[sy * 128 + sx]);
}

void clear_buffer(vu16* buffer, byte color) {
	dma16static((u16) 0x0, (u16*) buffer, 38400);
}

vu16* flip_buffer(vu16* buffer) {
	if(buffer == VRAMf) {
		*Display &= ~VRAM_BUFFER;
		return VRAMb;
	}
	*Display |= VRAM_BUFFER;
	return VRAMf;
}

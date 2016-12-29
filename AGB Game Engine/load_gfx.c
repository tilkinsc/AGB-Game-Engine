/*
 * load.c
 *
 *  Created on: Dec 17, 2016
 *      Author: Bud
 */

#include "load_gfx.h"
#include "gfx_common.h"
#include "gfx_tile.h"
#include "gfx_bitmap.h"

#include "background/a.bmp.h"

const CACHE_GFX A_bmp;

void init_gfx_list() {
	init_gfx_cache(A_bmp, (const unsigned int*) width_A_bmp, (const unsigned int*) height_A_bmp,
			(const unsigned short*) pixel_A_bmp, (const unsigned short*) palette_A_bmp);
	gfx_cache[0] = &A_bmp;

}

void init_gfx_cache(CACHE_GFX cache, const unsigned int* sx, const unsigned int* sy,
		const unsigned short* pixels, const unsigned short* palette) {
	cache.sx = (unsigned int*) sx;
	cache.sy = (unsigned int*) sy;
	cache.pixels = (unsigned short*) pixels;
	cache.palette = (unsigned short*) palette;
}


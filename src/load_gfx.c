/*
 * load.c
 *
 *  Created on: Dec 17, 2016
 *      Author: Bud
 */

#include "types.h"

#include "load_gfx.h"

#include "gfx/common.h"
#include "gfx/tile.h"
#include "gfx/bitmap.h"

#include "background/a.bmp.h"

CACHE_GFX A_bmp;

void init_gfx_list() {
	gfx_cache[0] = &A_bmp;
	init_gfx_cache(&A_bmp, (u24*)&width_A_bmp, (u24*)&height_A_bmp, (u16*)&pixel_A_bmp, (u16*)&palette_A_bmp);
}

void init_gfx_cache(
		CACHE_GFX* cache,
		u24* sx, u24* sy,
		u16* pixels, u16* palette) {
	cache->sx = (u24*) sx;
	cache->sy = (u24*) sy;
	cache->pixels = (u16*) pixels;
	cache->palette = (u16*) palette;
}


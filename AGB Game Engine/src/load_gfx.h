/*
 * load.h
 *
 *  Created on: Dec 17, 2016
 *      Author: Bud
 */

#ifndef LOAD_H_
#define LOAD_H_

#include "types.h"

typedef struct CACHE_GFX {
	u24* sx;
	u24* sy;
	u16* pixels;
	u16* palette;
} CACHE_GFX;

const CACHE_GFX* gfx_cache[1];

void init_gfx_list();

void init_gfx_cache(
		CACHE_GFX* cache,
		u24* sx, u24* sy,
		u16* pixels, u16* palette);

#endif /* LOAD_H_ */

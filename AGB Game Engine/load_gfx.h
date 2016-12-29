/*
 * load.h
 *
 *  Created on: Dec 17, 2016
 *      Author: Bud
 */

#ifndef LOAD_H_
#define LOAD_H_

typedef struct CACHE_GFX {
	unsigned int* sx;
	unsigned int* sy;
	unsigned short* pixels;
	unsigned short* palette;
} CACHE_GFX;

const CACHE_GFX* gfx_cache[1];

void init_gfx_list();

void init_gfx_cache(const CACHE_GFX cache, const unsigned int* sx, const unsigned int* sy,
		const unsigned short* pixels, const unsigned short* palette);

#endif /* LOAD_H_ */

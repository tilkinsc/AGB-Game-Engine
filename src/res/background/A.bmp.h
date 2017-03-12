/*
 * tileset.bmp.h
 *
 *  Created on: Oct 25, 2016
 *      Author: Cody
 */

#ifndef TILESET_BMP_H_
#define TILESET_BMP_H_

#include "../types.h"

const u24 width_A_bmp;
const u24 height_A_bmp;

const u16 palette_A_bmp[256] __attribute__((aligned(4)));
const u16 pixel_A_bmp[2112] __attribute__((aligned(4)));

#endif /* TILESET_BMP_H_ */

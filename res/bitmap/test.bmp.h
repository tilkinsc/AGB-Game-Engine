/*
 * test.bmp.h
 *
 *  Created on: Oct 25, 2016
 *      Author: Cody
 */

#ifndef TEST_BMP_H_
#define TEST_BMP_H_

#include "../../src/types.h"

const u24 width_test_bmp;
const u24 height_test_bmp;

const u16 palette_test_bmp[256] __attribute__((aligned(4)));
const byte pixel_test_bmp[16384] __attribute__((aligned(4)));

#endif /* TEST_BMP_H_ */

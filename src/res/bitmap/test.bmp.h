/*
 * test.bmp.h
 *
 *  Created on: Oct 25, 2016
 *      Author: Cody
 */

#ifndef TEST_BMP_H_
#define TEST_BMP_H_

const unsigned int width_test_bmp;
const unsigned int height_test_bmp;

const unsigned short int palette_test_bmp[256] __attribute__((aligned(4)));
const unsigned char pixel_test_bmp[16384] __attribute__((aligned(4)));

#endif /* TEST_BMP_H_ */

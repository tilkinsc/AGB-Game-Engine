/*
 * koopa_orig.h
 *
 *  Created on: Oct 25, 2016
 *      Author: Cody
 */

#ifndef KOOPA_ORIG_H_
#define KOOPA_ORIG_H_

#include "../../src/types.h"

const u32 koopa_width;
const u32 koopa_height;

const u16 koopa_palette[256] __attribute__((aligned(4)));
const u8 koopa_data[1024] __attribute__((aligned(4)));

#endif /* KOOPA_ORIG_H_ */

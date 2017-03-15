/*
 * string.h
 *
 *  Created on: Mar 15, 2017
 *      Author: Bud
 */

#ifndef STRING_H_
#define STRING_H_

#include "types.h"

void strset(u8* data, u8 init, u32 len);

void itoa(s32 num, s32 len, s8* str, s32 base);

#endif

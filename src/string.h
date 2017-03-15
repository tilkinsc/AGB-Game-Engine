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

void uitoa(u32 num, u32 len, u8* str, u32 base);
void sitoa(s32 num, u32 len, s8* str, u32 base);

#endif

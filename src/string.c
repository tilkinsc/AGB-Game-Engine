/*
 * string.c
 *
 *  Created on: Mar 15, 2017
 *      Author: Bud
 */

#include "types.h"

#include "string.h"

void strset(u8* data, u8 init, u32 len) {
	while(len-- > 0)
		data[len] = init;
}

void itoa(s32 num, s32 len, s8* str, s32 base) {
	len--;
	/* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (num == 0) {
		str[len--] = '0';
		return;
	}
	
	// Negative numbers are handled only with 
	// base 10. Otherwise numbers are considered unsigned.
	if (num < 0 && base == 10) {
		str[0] = '-';
		num = -num;
	}
	
	// Process individual digits
	while (num != 0)
	{
		const s32 rem = num % base;
		str[len--] = (rem > 9) ? (rem-10) + 'a' : rem + '0';
		num = num/base;
	}
}

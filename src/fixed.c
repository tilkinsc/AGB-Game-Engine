/*
 * fixed.c
 *
 *  Created on: Dec 9, 2016
 *      Author: Bud
 */

#include "fixed.h"
#include "string.h"

#include "stdio.h"

void fixed_set(Fixed* fixed, unsigned long long num) {
	*fixed = num << FIXED_PRECISION;
}

unsigned long long fixed_unset(Fixed* fixed) {
	return *fixed >> FIXED_PRECISION;
}

void fixed_md(Fixed* fixed, unsigned long long num) {
	*fixed *= num;
	*fixed >>= FIXED_OPERATION_PRECISION;
}

void fixed_floor(Fixed* fixed) {
	*fixed &= FIXED_UPPER_MASK;
}

void fixed_ceil(Fixed* fixed) {
	*fixed = ((*fixed - 1) | FIXED_LOWER_MASK) + 1; 
}

void fixed_round(Fixed* fixed, Fixed px, Fixed py) {
	fixed_md(fixed, px);
	*fixed += FIXED_MAGIC_0_5;
	fixed_floor(fixed);
	fixed_md(fixed, py);
}

void fixed_snprint(char* out, Fixed* fixed, unsigned int size) {
	Fixed temp = *fixed;
	temp &= FIXED_LOWER_MASK;
	fixed_md(&temp, FIXED_MAGIC_MUL_1000);
	snprintf(out, size+size, "%u.%u", (unsigned int)*fixed >> 16, (unsigned int)temp >> 16);
}


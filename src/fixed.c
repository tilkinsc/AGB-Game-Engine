/*
 * fixed.c
 *
 *  Created on: Dec 9, 2016
 *      Author: Bud
 */

#include "fixed.h"

void fixed_init(Fixed* fixed, unsigned int data, char resolution, char suffix) {
	*fixed = (data << resolution) | suffix;
}

void fixed_add(Fixed* fixed, Fixed* fixed2) {
	*fixed += *fixed2;
}

void fixed_sub(Fixed* fixed, Fixed* fixed2) {
	*fixed -= *fixed2;
}

void fixed_mul(Fixed* fixed, Fixed* fixed2) {
	*fixed *= *fixed2;
}

void fixed_div(Fixed* fixed, Fixed* fixed2) {
	*fixed /= *fixed2;
}

// TODO: not implemented or tested
void fixed_floor(Fixed* fixed, char resolution) {
	*fixed = (*fixed >> resolution) << resolution;
}

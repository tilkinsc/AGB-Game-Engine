/*
 * fixed.h
 *
 *  Created on: Dec 9, 2016
 *      Author: Bud
 */

#ifndef FIXED_H_
#define FIXED_H_

typedef unsigned int Fixed;

void fixed_init(Fixed* fixed, unsigned int data, char resolution, char suffix);

void fixed_add(Fixed* fixed, Fixed* fixed2);
void fixed_sub(Fixed* fixed, Fixed* fixed2);
void fixed_mul(Fixed* fixed, Fixed* fixed2);
void fixed_div(Fixed* fixed, Fixed* fixed2);

#endif /* FIXED_H_ */

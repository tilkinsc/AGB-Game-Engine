/*
 * fixed.h
 *
 *  Created on: Dec 9, 2016
 *      Author: Bud
 */

#ifndef FIXED_H_
#define FIXED_H_

#define FIXED_PRECISION 16
#define FIXED_OPERATION_PRECISION 35

#define FIXED_ONE 0x10000 // 1 << 16

#define FIXED_MAGIC_MUL_0_001 0x20C49BA // 0.001 << 35
#define FIXED_MAGIC_MUL_0_01 0x147AE148 // 0.01 << 35
#define FIXED_MAGIC_MUL_0_1 0xCCCCCCCD // 0.1 << 35
#define FIXED_MAGIC_MUL_10 0x5000000000 // 10 << 35
#define FIXED_MAGIC_MUL_100 0x32000000000 // 100 << 35
#define FIXED_MAGIC_MUL_1000 0x1F4000000000 // 1000 << 35

#define FIXED_MAGIC_0_5 0x8000 // 0.5 << 16
#define FIXED_MAGIC_0_05 0xCCD // 0.05 << 16
#define FIXED_MAGIC_0_005 0x148 // 0.005 << 16

#define FIXED_LOWER_MASK 0x0000FFFF // cuts off decimals in 16.16 fixed point
#define FIXED_UPPER_MASK 0xFFFF0000 // cuts off integers in 16.16 fixed point

typedef unsigned long long Fixed;

void fixed_set(Fixed* fixed, unsigned long long num);
unsigned long long fixed_unset(Fixed* fixed);

// Used to multiply, divide
void fixed_md(Fixed* fixed, unsigned long long num);

void fixed_floor(Fixed* fixed);
void fixed_ceil(Fixed* fixed);

// px = multiply
// py = divide
// Formula: floor(num*px + 0.5)/py
// px should be the 'opposite' of py in that...
// px = 10 should be py = 0.1
void fixed_round(Fixed* fixed, Fixed px, Fixed py);

void fixed_snprint(char* out, Fixed* fixed, unsigned int size);

#endif /* FIXED_H_ */

/*
 * types.h
 *
 *  Created on: Oct 27, 2016
 *      Author: Cody
 */

#ifndef TYPES_H_
#define TYPES_H_

#define ALIGN(n) __attribute__((aligned(n)))
#define PACKED __attribute__((packed))

typedef unsigned char byte;
typedef unsigned short u16;
typedef unsigned int u24;
typedef unsigned long u32;

typedef signed char sbyte;
typedef signed short s16;
typedef signed int s24;
typedef signed long s32;

typedef volatile unsigned char vbyte;
typedef volatile unsigned short vu16;
typedef volatile unsigned int vu24;
typedef volatile unsigned long vu32;

typedef volatile signed char vsbyte;
typedef volatile signed short vs16;
typedef volatile signed int vs24;
typedef volatile signed long vs32;

#endif

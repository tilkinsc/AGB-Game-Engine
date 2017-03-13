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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long s64;

typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned int vu32;
typedef volatile unsigned long vu64;

typedef volatile signed char vs8;
typedef volatile signed short vs16;
typedef volatile signed int vs32;
typedef volatile signed long vs64;

#endif

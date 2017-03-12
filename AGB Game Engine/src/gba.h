/*
 * gba.h
 *
 *  Created on: Oct 14, 2016
 *      Author: Cody
 */

#ifndef GBA_H_
#define GBA_H_

#include "types.h"

// Screen resolution
#define WIDTH 240
#define HEIGHT 160

// Option numbers
#define VRAM_BUFFER 0x10;

// DMA
#define DMA_ENABLE 0x80000000
#define DMA16 0x0
#define DMA32 0x4000000

// Tile Modes
#define MODE_0 0x0
#define MODE_1 0x1
#define MODE_2 0x2

// Bitmap Modes
#define MODE_3 0x3
#define MODE_4 0x4
#define MODE_5 0x5

// Backgrounds
#define BG0 0x100
#define BG1 0x200
#define BG2 0x400
#define BG3 0x800

// Sprites
#define SP_ENABLE 0x1000
#define SP_MAP_2D 0x0
#define SP_MAP_1D 0x40

// Display registers
vu32* Display;
vu16* SLC;

// DMA registers
vu24* DMAs;
vu24* DMAd;
vu24* DMAc;

// RAM
vu16* BG_PRAM;
vu16* SP_PRAM;

vu16* VRAMf;
vu16* VRAMb;

vu16* SIM;
vu16* OAM;

void dma16(u16* source, u16* dest, u24 len);
void dma16static(u16* source, u16* dest, u24 len);
void dma32(u32* source, u32* dest, u24 len);

void delay(u24 time);

#endif /* GBA_H_ */

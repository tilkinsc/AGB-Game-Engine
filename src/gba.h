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
#define GBA_WIDTH 240
#define GBA_HEIGHT 160

// Option numbers
#define VRAM_BUFFER 0x10;

// DMA
#define DMA_ENABLE 0x80000000
#define DMA_16 0x0
#define DMA_32 0x1

// Tile Modes
#define MODE_0 0x0
#define MODE_1 0x1
#define MODE_2 0x2

// Bitmap Modes
#define MODE_3 0x3
#define MODE_4 0x4
#define MODE_5 0x5

// Backgrounds
#define BG_0 0x100
#define BG_1 0x200
#define BG_2 0x400
#define BG_3 0x800

// Sprites
#define SP_ENABLE 0x1000
#define SP_MAP_2D 0x0
#define SP_MAP_1D 0x40

// Display registers
vu64* DISPLAY;
vu16* SLC;

// DMA registers
vu32* DMA3s;
vu32* DMA3d;
vu32* DMA3c;

// RAM
vu16* PRAM_BG;
vu16* PRAM_SP;

vu16* VRAMf;
vu16* VRAMb;

vu16* SIM;
vu16* OAM;

void cpuset8(vu16* a, u8* b, u32 length, u32 offset);
void cpuset16(vu16* a, u16* b, u32 length, u32 offset);

void dma3_16(void* source, void* dest, u32 len);
void dma3_32(void* source, void* dest, u32 len);

void delay(u32 time);

#endif /* GBA_H_ */

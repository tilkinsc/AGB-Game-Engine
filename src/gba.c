
#include "gba.h"

#include "types.h"

// Display registers
vu64* Display = (vu64*) 0x4000000;
vu16* SLC = (vu16*) 0x4000006;

// DMA registers
vu32* DMA3s = (vu32*) 0x40000d4;
vu32* DMA3d = (vu32*) 0x40000d8;
vu32* DMA3c = (vu32*) 0x40000dc;

// RAM
vu16* BG_PRAM = (vu16*) 0x5000000;
vu16* SP_PRAM = (vu16*) 0x5000200;

vu16* VRAMf = (vu16*) 0x6000000;
vu16* VRAMb = (vu16*) 0x600A000;

vu16* SIM = (vu16*) 0x6010000;
vu16* OAM = (vu16*) 0x7000000;

void cpuset8(vu16* a, u8* b, u32 length, u32 offset) {
	u32 len;
	for (len=0; len<length; len++)
		*a++ = *b++ - offset;
}

void cpuset16(vu16* a, u16* b, u32 length, u32 offset) {
	u32 len;
	for (len=0; len<length; len++)
		*a++ = *b++ - offset;
}

void dma3_16(void* source, void* dest, u32 len) {
	*DMA3s = (u32) source;
	*DMA3d = (u32) dest;
	*DMA3c = len | DMA16 | DMA_ENABLE;
}

void dma3_32(void* source, void* dest, u32 len) {
	*DMA3s = (u32) source;
	*DMA3d = (u32) dest;
	*DMA3c = len | DMA32 | DMA_ENABLE;
}

void delay(u32 time) {
	int i;
	for (i=0; i<time*10; i++);
}

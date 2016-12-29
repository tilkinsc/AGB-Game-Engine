
#include "gba.h"

#include "types.h"

// Display registers
vu32* Display = (vu32*) 0x4000000;
vu16* SLC = (vu16*) 0x4000006;

// DMA registers
vu24* DMAs = (vu24*) 0x40000d4;
vu24* DMAd = (vu24*) 0x40000d8;
vu24* DMAc = (vu24*) 0x40000dc;

// RAM
vu16* BG_PRAM = (vu16*) 0x5000000;
vu16* SP_PRAM = (vu16*) 0x5000200;

vu16* VRAMf = (vu16*) 0x6000000;
vu16* VRAMb = (vu16*) 0x600A000;

vu16* SIM = (vu16*) 0x6010000;
vu16* OAM = (vu16*) 0x7000000;

void dma16(u16* source, u16* dest, u24 len) {
	*DMAs = (u24) source;
	*DMAd = (u24) dest;
	*DMAc = len | DMA16 | DMA_ENABLE;
}

void dma16static(u16* source, u16* dest, u24 len) {
	*DMAs = (u24) source;
	*DMAd = (u24) dest;
	*DMAc = len | (2<<23) | DMA16 | DMA_ENABLE;
}

void dma32(u32* source, u32* dest, u24 len) {
	*DMAs = (u24) source;
	*DMAd = (u24) dest;
	*DMAc = len | DMA32 | DMA_ENABLE;
}

void delay(u24 time) {
	int i;
	for (i=0; i<time*10; i++);
}


#include "gba.h"

#include "types.h"

// Display registers
vu64* Display = (vu64*) 0x4000000;
vu16* SLC = (vu16*) 0x4000006;

// DMA registers
vu32* DMAs = (vu32*) 0x40000d4;
vu32* DMAd = (vu32*) 0x40000d8;
vu32* DMAc = (vu32*) 0x40000dc;

// RAM
vu16* BG_PRAM = (vu16*) 0x5000000;
vu16* SP_PRAM = (vu16*) 0x5000200;

vu16* VRAMf = (vu16*) 0x6000000;
vu16* VRAMb = (vu16*) 0x600A000;

vu16* SIM = (vu16*) 0x6010000;
vu16* OAM = (vu16*) 0x7000000;

void dma16(void* source, void* dest, u32 len) {
	*DMAs = (u32) source;
	*DMAd = (u32) dest;
	*DMAc = len | DMA16 | DMA_ENABLE;
}

void delay(u32 time) {
	int i;
	for (i=0; i<time*10; i++);
}

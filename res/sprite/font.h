
//{{BLOCK(font)

//======================================================================
//
//	font, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 1024 tiles Metatiled by 2x2 not compressed
//	Total size: 512 + 65536 = 66048
//
//	Time-stamp: 2016-12-09, 00:50:02
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FONT_H
#define GRIT_FONT_H

#include "../src/types.h"

const u24 font_width;
const u24 font_height;

const u16 font_palette[256] __attribute__((aligned(4)));
const byte font_data[65536] __attribute__((aligned(4)));

#endif // GRIT_FONT_H

//}}BLOCK(font)

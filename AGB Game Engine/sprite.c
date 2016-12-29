/*
 * sprite.c
 *
 *  Created on: Oct 20, 2016
 *      Author: Cody
 */

#include "sprite.h"

#include "gba.h"


Sprite* init_sprite(u24 x, u24 y, u24 sizex, u24 sizey, byte hflip, byte vflip, int tindex, int priority) {
	sprites[sprite_index].att0 =
			 y			|
			(0 << 8)	|
			(0 << 10)	|
			(0 << 12)	|
			(1 << 13)	|
			(sizex << 14);
	sprites[sprite_index].att1 =
			 x			|
			 (0 << 9)	|
			 (hflip << 12)	|
			 (vflip << 13)	|
			 (sizey << 14);
	sprites[sprite_index].att2 =
			 tindex			|
			(priority << 10)|
			(0 << 12);
	return &sprites[sprite_index++];
}

void draw_sprites() {
	dma16((u16*) sprites, (u16*) OAM, 128 * 4);
}

void sprite_move(Sprite* sp, s24 x, s24 y) {
	sp->att0 &= 0xFF00;
	sp->att0 |= (y & 0xFF);
	sp->att1 &= 0xFe00;
	sp->att1 |= (x & 0x1FF);
}

void sprite_animate(Sprite* sp, u24 track) {
	sp->att2 &= 0xFc00;
	sp->att2 |= track & 0x03FF;
}

void sprite_flipx(Sprite* sp, byte option) {
	if(option) sp->att1 |= 0x2000;
	else sp->att1 &= 0xdFFF;
}

void sprite_flipy(Sprite* sp, byte option) {
	if(option) sp->att1 |= 0x1000;
	else sp->att1 &= 0xEFFF;
}

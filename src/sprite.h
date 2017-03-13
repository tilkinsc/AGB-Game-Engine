/*
 * sprite.h
 *
 *  Created on: Oct 20, 2016
 *      Author: Cody
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "types.h"

typedef struct Sprite {
	u16 att0;
	u16 att1;
	u16 att2;
	u16 att3;
} Sprite;

Sprite sprites[128];

u32 sprite_index;

Sprite* init_sprite(u32 x, u32 y, u32 sizex, u32 sizey, u32 hflip, u32 vflip, u32 tindex, u32 priority);

void draw_sprites();

void sprite_move(Sprite* sp, s32 x, s32 y);
void sprite_animate(Sprite* sp, u32 track);
void sprite_flipx(Sprite* sp, u32 option);
void sprite_flipy(Sprite* sp, u32 option);

#endif /* SPRITE_H_ */

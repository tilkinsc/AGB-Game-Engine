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
	u16 att0, att1, att2, att3;
} Sprite;

Sprite sprites[128];

int sprite_index;

Sprite* init_sprite(u24 x, u24 y, u24 sizex, u24 sizey, byte hflip, byte vflip, int tindex, int priority);

void draw_sprites();

void sprite_move(Sprite* sp, s24 x, s24 y);
void sprite_animate(Sprite* sp, u24 track);
void sprite_flipx(Sprite* sp, byte option);
void sprite_flipy(Sprite* sp, byte option);

#endif /* SPRITE_H_ */

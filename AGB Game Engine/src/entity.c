/*
 * entity.c
 *
 *  Created on: Oct 22, 2016
 *      Author: Cody
 */

#include "entity.h"

void init_entity(Entity* entity, s24 x, s24 y, byte xflip, byte yflip, byte step, u24 frame, u24 fflip, Sprite* sprite) {
	entity->x = x;
	entity->y = y;
	entity->xflip = xflip;
	entity->yflip = yflip;
	entity->step = step;
	entity->frame = frame;
	entity->fflip = fflip;
	entity->sp = (Sprite*) sprite;
}

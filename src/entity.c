/*
 * entity.c
 *
 *  Created on: Oct 22, 2016
 *      Author: Cody
 */

#include "entity.h"

void init_entity(Entity* entity, s32 x, s32 y, u32 xflip, u32 yflip, u32 step, u32 frame, u32 fflip, Sprite* sprite) {
	entity->x = x;
	entity->y = y;
	entity->xflip = xflip;
	entity->yflip = yflip;
	entity->step = step;
	entity->frame = frame;
	entity->fflip = fflip;
	entity->sp = (Sprite*) sprite;
}

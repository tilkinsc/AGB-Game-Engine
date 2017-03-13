/*
 * entity.h
 *
 *  Created on: Oct 22, 2016
 *      Author: Cody
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "sprite.h"
#include "types.h"

typedef struct Entity {
	s32 x;
	s32 y;
	u32 xflip;
	u32 yflip;
	u32 step;
	u32 frame;
	u32 fcount;
	u32 fflip;
	Sprite* sp;
} Entity;

void init_entity(Entity* entity, s32 x, s32 y, u32 xflip, u32 yflip, u32 step, u32 frame, u32 fflip, Sprite* sprite);

#endif /* ENTITY_H_ */

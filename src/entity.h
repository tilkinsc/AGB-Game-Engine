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
	s24 x;
	s24 y;
	byte xflip;
	byte yflip;
	byte step;
	u24 frame;
	u24 fcount;
	u24 fflip;
	Sprite* sp;
} Entity;

void init_entity(Entity* entity, s24 x, s24 y, byte xflip, byte yflip, byte step, u24 frame, u24 fflip, Sprite* sprite);

#endif /* ENTITY_H_ */

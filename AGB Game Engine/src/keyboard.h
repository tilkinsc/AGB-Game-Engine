/*
 * keyboard.h
 *
 *  Created on: Oct 17, 2016
 *      Author: Cody
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "types.h"

typedef void (*KeyEvent)();

#define KEY_A		0x001
#define KEY_B		0x002
#define KEY_SELECT	0x004
#define KEY_START	0x008
#define KEY_RIGHT	0x010
#define KEY_LEFT	0x020
#define KEY_UP		0x040
#define KEY_DOWN	0x080
#define KEY_R		0x100
#define KEY_L		0x200

u16* KEYS;

KeyEvent key_events[10];

void poll_key_events();

byte keydown(short key);

#endif /* KEYBOARD_H_ */

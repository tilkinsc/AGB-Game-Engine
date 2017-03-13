/*
 * keyboard.c
 *
 *  Created on: Oct 17, 2016
 *      Author: Cody
 */

#include "keyboard.h"

u32 current;

u32* KEYS = (u32*) 0x04000130;

void nothing() {}

KeyEvent key_events[10] = {
	&nothing, &nothing, &nothing, &nothing, &nothing, &nothing, &nothing, &nothing, &nothing, &nothing
};

u32 keydown(u32 key) {
	return current & key;
}

void poll_key_events() {
	current = ~*KEYS;
	if(keydown(KEY_A))		key_events[0]();
	if(keydown(KEY_B))		key_events[1]();
	if(keydown(KEY_SELECT))	key_events[2]();
	if(keydown(KEY_START))	key_events[3]();
	if(keydown(KEY_RIGHT))	key_events[4]();
	if(keydown(KEY_LEFT))	key_events[5]();
	if(keydown(KEY_UP))		key_events[6]();
	if(keydown(KEY_DOWN))	key_events[7]();
	if(keydown(KEY_R))		key_events[8]();
	if(keydown(KEY_L))		key_events[9]();
}

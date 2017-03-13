/*
 * main.c
 *
 *  Created on: Oct 12, 2016
 *      Author: Cody
 */

#include "gba.h"
#include "types.h"
#include "keyboard.h"

#include "sprite.h"
#include "entity.h"
#include "background.h"

#include "gfx/common.h"
#include "gfx/tile.h"

// images
#include "../res/background/A.bmp.h"

// maps
#include "../res/map/example_map.h"
#include "../res/map/font_map.h"

// sprites
#include "../res/sprite/koopa_orig.h"
#include "../res/sprite/font.h"

Background background0;
Background background1;

Entity kupo;

void test0() {
	kupo.x++;
	sprite_move(kupo.sp, kupo.x, kupo.y);
}

void test1() {
	kupo.y++;
	sprite_move(kupo.sp, kupo.x, kupo.y);
}

void test2() {
	kupo.x--;
	sprite_move(kupo.sp, kupo.x, kupo.y);
}

void test3() {
	kupo.y--;
	sprite_move(kupo.sp, kupo.x, kupo.y);
}

void ccb() {
	clear_charblock(screen_block(16));
}

int main(void) {
	
	*Display = (MODE_0 | BG0 | SP_ENABLE | SP_MAP_1D);
	
	init_background(&background0, bg0c, bg0xs, bg0ys, 0, 0, 0, 1, 8, 0, 0);
//	init_background(&background1, bg1c, bg1xs, bg1ys, 0, 2, 0, 1, 24, 0, 0);
	update_background(&background0);
//	update_background(&background1);
	
	// background/map
	//1
	inject_palette(BG_PRAM, palette_A_bmp);
	load_charblock(char_block(0), (u16*) pixel_A_bmp, width_A_bmp, height_A_bmp);
	load_screenblock(screen_block(8), asd_map, asd_map_width, asd_map_height);
	//2
//	inject_palette(BG_PRAM, font_palette);
//	load_charblock(char_block(2), (u16*) font_data, font_width, font_height);
//	load_screenblock(screen_block(24), font_map, font_map_width, font_map_height);
	
	// sprite
	inject_palette(SP_PRAM, koopa_palette);
	load_charblock(SIM, (u16*) koopa_data, koopa_width, koopa_height);
	init_entity(&kupo, 0,0,0,0,0,0,0, init_sprite(0, 0, 2, 2, 0, 0, 16, 0));
	
	// keyboard
	key_events[4] = &test0;
	key_events[5] = &test2;
	key_events[6] = &test3;
	key_events[7] = &test1;
	
	u32 x = 0;
	u32 y = 0;
	
	while(1) {

		VBLANK();

		poll_key_events();

		draw_sprites();

		move_background(&background0, x, y);
//		move_background(&background1, x, y);
	}

	return 0;
}

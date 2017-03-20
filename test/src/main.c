/*
 * main.c
 *
 *  Created on: Oct 12, 2016
 *      Author: Cody
 */

#include <stdio.h>

#include "gbage/gba.h"
#include "gbage/types.h"
#include "gbage/fixed.h"
#include "gbage/string.h"

#include "gbage/keyboard.h"
#include "gbage/sprite.h"
#include "gbage/entity.h"
#include "gbage/background.h"

#include "gbage/gfx/common.h"
#include "gbage/gfx/tile.h"

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

Sprite* kupo_sp;
Entity kupo_ent;

void test0() {
	kupo_ent.x++;
}

void test1() {
	kupo_ent.y++;
}

void test2() {
	kupo_ent.x--;
}

void test3() {
	kupo_ent.y--;
}

void ccb() {
	u32 size = 20;
	
	s32 test = -21;
	
	// "testing string"
	u8 string[14] = {
	        52,69,83,84,73,78,71,0,83,84,82,73,78,71,
	};
	
	u8 str2[3];
	uitoa(size, 3, str2, 10);
//	uitoa(size, 2, str2, 10); // unsigned test
//	strset(str2, 33, 3); // strset test
	
	Fixed f = (2 << FIXED_PRECISION) | 0x7D71;
	
	u8 buffer[11];
	fixed_snprint(buffer, &f, 11);
	
	cpuset8((void*)screen_block(24), (u8*)string, 14, 0);
	cpuset8((void*)screen_block(24)+30, (u8*)buffer, 11, 32);
	// cpuset8((void*)screen_block(24)+30, (u8*)str2, 2, 32); // unsigned test
}

int main(void) {
	
	*Display = (MODE_0 | BG0 | BG1 | SP_ENABLE | SP_MAP_1D);
	
	init_background(&background0, bg0c, bg0xs, bg0ys, 1, 0, 0, 1, 8, 0, 0);
	init_background(&background1, bg1c, bg1xs, bg1ys, 0, 2, 0, 1, 24, 0, 0);
	update_background(&background0);
	update_background(&background1);
	
	// background/map
	// bg 1
	dma3_16((u16*)palette_A_bmp, (u16*)BG_PRAM, 256);
	dma3_16((u16*)pixel_A_bmp, (u16*)char_block(0), width_A_bmp * height_A_bmp);
	dma3_16((u16*)asd_map, (u16*)screen_block(8), asd_map_width * asd_map_height);
	// bg 2
	dma3_16((u16*)font_data, (u16*)char_block(2), font_width * font_height);
	dma3_16((u16*)font_map, (u16*)screen_block(24), font_map_width * font_map_height);
	
	// sprite
	dma3_16((u16*)koopa_palette, (u16*)SP_PRAM, 256);
	dma3_16((u16*)koopa_data, (u16*)SIM, koopa_width * koopa_height);
	
	kupo_sp = init_sprite(0, 0, 0, 2, 2, 0, 0, 16, 0);
	init_entity(&kupo_ent, 0,0,0,0,0,0,0, kupo_sp);
	
	// keyboard
	key_events[3] = &ccb;
	key_events[4] = &test0;
	key_events[5] = &test2;
	key_events[6] = &test3;
	key_events[7] = &test1;
	
	s16 bg1x = -32;
	s16 bg1y = -32;
	
	s16 bg2x = 0;
	s16 bg2y = 0;
	
	while(1) {
		
		VBLANK();
		
		poll_key_events();
		
		sprite_move(kupo_ent.sp, kupo_ent.x, kupo_ent.y);
		draw_sprites();
		
		move_background(&background0, bg1x, bg1y);
		move_background(&background1, bg2x, bg2y);
	}
	
	return 0;
}

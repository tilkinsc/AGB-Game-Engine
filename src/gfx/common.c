/*
 * gfx_common.c
 *
 *  Created on: Oct 21, 2016
 *      Author: Cody
 */

#include "common.h"

#include "../gba.h"
#include "../types.h"

void VBLANK() {
	while (*SLC >= 160);
	while (*SLC < 160);
}

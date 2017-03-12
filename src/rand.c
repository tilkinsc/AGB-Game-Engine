/*
 * rand.c
 *
 *  Created on: Jan 1, 2017
 *      Author: Bud
 */

#include "rand.h"

static int rng_seed = 0x4B3D9;

int rseed(int seed) {
	int old = seed;
	rng_seed = seed;
	rand();
	return old;
}

int rand() {
	rng_seed = 1664525 * rng_seed+1013904223;
	return (rng_seed >> 16) & 0x7FFF;
}

int rand_range(int min, int max) {
	return (rand() * (max-min)>>15)+min;
}

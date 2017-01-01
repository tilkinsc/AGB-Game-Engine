/*
 * rand.c
 *
 *  Created on: Jan 1, 2017
 *      Author: Bud
 */

#include "rand.h"

int rng_seed = 0x4B3D9;

int seed(int seed) {
	int old = seed;
	rng_seed = seed;
	return old;
}

int rand() {
	rng_seed = 1664525 * rng_seed+1013904223;
	return (rng_seed >> 16) & 0x7FFF;
}

int rand(int seed) {
	rng_seed = 1664525 * seed+1013904223;
	return (rng_seed >> 16) & 0x7FFF;
}

int rand_range(int min, int max) {
	return (rand() * (max-min)>>15)+min;
}

int rand_range(int seed, int min, int max) {
	return (rand(seed) * (max-min)>>15)+min;
}


#ifndef BLOCK_H_
#define BLOCK_H_

// Basic definitions about blocks.

#include "glm.h"

typedef unsigned char TypeBlock;
const vec2 SIZE_BLOCK(80.0f, 80.0f);

enum
{
	NONE,
	AIR = 0,
	DIRT,
	GRASS
};

#endif
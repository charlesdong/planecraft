#include "blockmanager.h"
#include "blockrenderer.h"

BlockManager::BlockManager()
{
}

void BlockManager::init()
{
	for (int j = 0; j < HEIGHT; j++)
		for (int i = 0; i < WIDTH; i++)
		{
			TypeBlock & b = blocks[j][i];
			if (j == 0)
				b = DIRT;
			if (j >= 1 && j <= 2)
				b = DIRT;
			if (j == 3)
				b = GRASS;
		}
	br.init();
}

void BlockManager::render(const vec2 & posView) const
{
	for (int j = 0; j < HEIGHT; j++)
		for (int i = 0; i < WIDTH; i++)
			br.render(blocks[j][i], vec2(i, j), posView);
}
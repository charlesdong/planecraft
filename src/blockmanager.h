#ifndef BLOCKMANAGER_H_
#define BLOCKMANAGER_H_

#include "block.h"
#include "glm.h"
#include "blockrenderer.h"

class BlockManager
{
private:
	static const int WIDTH = 40;
	static const int HEIGHT = 4;
	TypeBlock blocks[HEIGHT][WIDTH];
	BlockRenderer br;
public:
	BlockManager();
	void init();
	void render(const vec2 & posView) const;
};

#endif
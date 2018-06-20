#ifndef BLOCKRENDERER_H_
#define BLOCKRENDERER_H_

#include "glm.h"
#include "block.h"
#include "blockregistry.h"

class BlockRenderer
{
private:
	BlockRegistry br;
	bool isVisible(const vec2 & posBlock, const vec2 & posView) const;
	vec2 getScreenPos(const vec2 & posBlock, const vec2 & posView) const { return (posBlock - posView) * SIZE_BLOCK; }
public:
	void init();
	void render(TypeBlock idBlock, const vec2 & posBlock, const vec2 & posView) const;
};

#endif
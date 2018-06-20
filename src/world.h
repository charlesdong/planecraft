#ifndef WORLD_H_
#define WORLD_H_

#include "blockmanager.h"
#include "glm.h"

class World
{
private:
	BlockManager bm;
	vec2 posView;
public:
	void init();
	void update();
	void render() const;
};

#endif
#include "blockregistry.h"
#include "resourcemanager.h"

BlockRegistry::BlockRegistry()
{
}

void BlockRegistry::load(const char * imagePath, bool alpha)
{
	int id = ResourceManager::loadTexture(imagePath, alpha);
	blockTexIds.push_back(id);
}

int BlockRegistry::getBlockTexId(TypeBlock b) const
{
	return blockTexIds[(int)b - 1];
}
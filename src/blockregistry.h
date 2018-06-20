#ifndef BLOCKREGISTRY_H_
#define BLOCKREGISTRY_H_

#include <vector>
#include "block.h"

class BlockRegistry
{
private:
	std::vector<int> blockTexIds;
public:
	BlockRegistry();
	void load(const char * imagePath, bool alpha = false);
	int getBlockTexId(TypeBlock b) const;
};

#endif
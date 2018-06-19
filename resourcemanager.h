#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <vector>
#include "shader.h"
#include "texture.h"

class ResourceManager
{
private:
	static std::vector<Shader> shaders;
	static std::vector<Texture> textures;

	static const char * read(const char * file);
public:
	static int loadShader(const char * vFile, const char * fFile);
	static int loadTexture(const char * file, bool alpha = false);
	static Shader & getShader(int index);
	static Texture & getTexture(int index);
	static void clear();
};

#endif
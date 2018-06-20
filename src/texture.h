#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

class Texture
{
private:
	GLuint tex;
public:
	Texture();
	void load(const unsigned char * image, int width, int height, bool alpha = false);
	void use() const;
	void clear();
};

#endif
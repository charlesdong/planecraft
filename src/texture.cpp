#include "texture.h"
#include <stb_image.h>

Texture::Texture()
{
}

void Texture::load(const unsigned char * image, int width, int height, bool alpha)
{
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// NOTE: to pixel textues, GL_NEAREST should be chosen
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// TODO: In PNG files every pixel is 32-bit even though it's completely opaque
	// (oh, maybe not like this... I'm not sure then. Sorry!)
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, alpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::use() const
{
	glBindTexture(GL_TEXTURE_2D, tex);
}

void Texture::clear()
{
	glDeleteTextures(1, &tex);
}
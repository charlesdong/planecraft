#include "resourcemanager.h"
#include <iostream>
#include <fstream>
using std::ifstream;
#define STB_IMAGE_IMPLEMENTATION	// Very important
#include <stb_image.h>

std::vector<Shader> ResourceManager::shaders;
std::vector<Texture> ResourceManager::textures;

int ResourceManager::loadShader(const char * vFile, const char * fFile)
{
	const char * vSrc = read(vFile);
	const char * fSrc = read(fFile);
	Shader shader;
	shader.load(vSrc, fSrc);
	shaders.push_back(shader);
	delete[] vSrc;
	delete[] fSrc;
	return shaders.size() - 1;
}

int ResourceManager::loadTexture(const char * file, bool alpha)
{
	int width, height;
	unsigned char * image = stbi_load(file, &width, &height, nullptr, 0);		// Can nrChannels be nullptr?
	Texture texture;
	texture.load(image, width, height, alpha);
	textures.push_back(texture);
	stbi_image_free(image);
	return textures.size() - 1;
}

Shader & ResourceManager::getShader(int index)
{
	return shaders[index];
}

Texture & ResourceManager::getTexture(int index)
{
	return textures[index];
}

void ResourceManager::clear()
{
	for (auto s : shaders)
		s.clear();
	for (auto t : textures)
		t.clear();
}

const char * ResourceManager::read(const char * file)
{
	int size;
	ifstream fin;
	fin.open(file);
	if (!fin.is_open())
	{
		std::cout << "ERROR: Failed to open file!\n";
		return nullptr;
	}
	fin.seekg(0, std::ios_base::end);
	size = fin.tellg();		// Maybe not real size (I'm not sure)
	char * content = new char[size + 1]{ '\0' };
	fin.seekg(0, std::ios_base::beg);
	fin.read(content, size);
	return content;
}
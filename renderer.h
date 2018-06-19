#ifndef RENDERER_H_
#define RENDERER_H_

#include <glm/glm.hpp>
#include <GL/glew.h>

class Renderer
{
private:
	static GLuint vao;
	static GLuint ebo, vbo;		// PROBLEM: Does vbo only need to exist during initialization?
	static int idTexture;
	static int idShader;
	static glm::vec2 size;
public:
	static void init();
	static void setTexture(int tex);
	static void setSize(const glm::vec2 & size);
	static void render(const glm::vec2 & pos);
	static void clear();
};

#endif
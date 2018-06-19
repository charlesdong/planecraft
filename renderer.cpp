#include "renderer.h"
#include "resourcemanager.h"
#include <glm/gtc/matrix_transform.hpp>

GLuint Renderer::vbo;
GLuint Renderer::ebo;
GLuint Renderer::vao;
int Renderer::idTexture;
int Renderer::idShader;
glm::vec2 Renderer::size;

void Renderer::init()
{
	float vertexes[] =
	{
		1.0f, 1.0f,	1.0f, 1.0f,
		1.0f, -1.0f,	1.0f, 0.0f,
		-1.0f, -1.0f,	0.0f, 0.0f,
		-1.0f, 1.0f,	0.0f, 1.0f
	};
	unsigned int indexes[] =
	{
		0, 1, 3,
		1, 2, 3
	};
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glm::mat4 proj;
	Shader & s = ResourceManager::getShader(idShader);
	s.use();
	s.setmat4f("proj", proj);
}

void Renderer::setTexture(int tex)
{
	idTexture = tex;
}

void Renderer::setSize(const glm::vec2 & s)
{
	size = s;
}

void Renderer::render(const glm::vec2 & pos)
{
	glm::mat4 model;
	glm::translate(model, glm::vec3(pos, 0.0f));
	glm::scale(model, glm::vec3(size, 0.0f));

	Shader & s = ResourceManager::getShader(idShader);
	s.use();
	s.setmat4f("model", model);

	ResourceManager::getTexture(idTexture).use();

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}

void Renderer::clear()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
}
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
		1.0f, 1.0f, //1.0f, 1.0f,
		1.0f, 0.0f, //1.0f, 0.0f,
		0.0f, 0.0f, //0.0f, 0.0f,
		0.0f, 1.0f, //0.0f, 1.0f
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

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(0);

	idShader = ResourceManager::loadShader("shaders/shader.vert", "shaders/shader.frag");

	glm::mat4 proj = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
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
	// translate() and scale() returns the new matrix instead of modifying the old one,
	// so the return value should be assigned to model
	model = glm::translate(model, glm::vec3(pos, 0.0f));
	model = glm::scale(model, glm::vec3(size, 0.0f));

	Shader & s = ResourceManager::getShader(idShader);
	s.use();
	s.setmat4f("model", model);

	// check if the current texture is the same as the last one,
	// only bound texture if different, in order to speed up
	static int idTextureLast = -1;
	if (idTexture != idTextureLast)
	{
		ResourceManager::getTexture(idTexture).use();
		idTextureLast = idTexture;
	}

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
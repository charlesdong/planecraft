#include "game.h"
#include <GL/glew.h>
#include "renderer.h"
#include "resourcemanager.h"

Game::Game()
{
}

void Game::run()
{
	init();
	while (!glfwWindowShouldClose(window))
		loop();
	clear();
}

void Game::init()
{
	glfwInit();

	// GLFW hints set

	window = glfwCreateWindow(800, 600, "Planecraft 0.1", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// GLFW set callbacks

	glewExperimental = GL_TRUE;
	glewInit();

	glViewport(0, 0, 800, 600);

	shaderId = ResourceManager::loadShader("shader.vert", "shader.frag");
	textureId = ResourceManager::loadTexture("example.jpg");
	Renderer::init();
}

void Game::loop()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	Renderer::setTexture(textureId);
	Renderer::setSize(glm::vec2(0.5f, 0.5f));
	Renderer::render(glm::vec2(0.0f, 0.0f));

	glfwPollEvents();
	glfwSwapBuffers(window);
}

void Game::clear()
{
	Renderer::clear();
	ResourceManager::clear();
}
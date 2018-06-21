#include "game.h"
#include <GL/glew.h>
#include "renderer.h"
#include "resourcemanager.h"
#include <iostream>
using std::cout;
using std::endl;

GLFWwindow * Game::window;

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
	if (!glfwInit())
		cout << "ERROR: Failed to init GLFW!\n";

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);		// It's not allowed to resize, currently

	window = glfwCreateWindow(800, 600, "Planecraft 0.1", nullptr, nullptr);
	if (window == nullptr)
		cout << "ERROR: Failed to create window using GLFW!\n";
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		cout << "ERROR: Failed to init GLEW!\n";

	glViewport(0, 0, 800, 600);
	glClearColor(0.51f, 0.68f, 1.0f, 1.0f);	// R:129, G:173, B:255, Minecraft standard sky color (in my opinion)

	Renderer::init();
	world.init();
}

void Game::loop()
{
	processInput();
	update();
	render();

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Game::clear()
{
	Renderer::clear();
	ResourceManager::clear();
}

void Game::processInput()
{
	if (isKeyDown(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(window, GLFW_KEY_ESCAPE);
}

void Game::update()
{
	world.update();
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	Renderer::setSize(SIZE_BLOCK);
	world.render();
}
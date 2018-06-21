#ifndef GAME_H_
#define GAME_H_

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "world.h"

class Game
{
private:
	void init();
	void loop();
	void clear();

	void processInput();
	void update();
	void render();

	static GLFWwindow * window;

	World world;
public:
	Game();
	void run();

	static bool isKeyDown(int key) { return glfwGetKey(window, key) != GLFW_RELEASE; }
};

#endif
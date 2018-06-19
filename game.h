#ifndef GAME_H_
#define GAME_H_

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Game
{
private:
	GLFWwindow * window;
	void init();
	void loop();
	void clear();
	int shaderId;
	int textureId;
public:
	Game();
	void run();
};

#endif
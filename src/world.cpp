#include "world.h"
#include "game.h"		// TODO/FIXME: is this really a good idea?

void World::init()
{
	bm.init();
}

void World::update()
{
	static const float VELOCITY_X = 2.5f;
	static const float VELOCITY_Y = 2.5f;

	static float timeLast = 0.0f;
	float timeCur = (float)glfwGetTime();
	float dt = timeCur - timeLast;

	if (Game::isKeyDown(GLFW_KEY_A))
		posView.x -= VELOCITY_X * dt;
	if (Game::isKeyDown(GLFW_KEY_D))
		posView.x += VELOCITY_X * dt;
	if (Game::isKeyDown(GLFW_KEY_S))
		posView.y -= VELOCITY_Y * dt;
	if (Game::isKeyDown(GLFW_KEY_W))
		posView.y += VELOCITY_Y * dt;
}

void World::render() const
{
	bm.render(posView);
}
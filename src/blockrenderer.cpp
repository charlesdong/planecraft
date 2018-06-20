#include "blockrenderer.h"
#include "renderer.h"
#include "mathutil.h"

void BlockRenderer::init()
{
	br.load("textures/dirt.png", true);
	br.load("textures/grass.png", true);
}

void BlockRenderer::render(TypeBlock idBlock, const vec2 & posBlock, const vec2 & posView) const
{
	// discard the air blocks
	if (idBlock == AIR)
		return;
	Renderer::setTexture(br.getBlockTexId(idBlock));
	Renderer::render(getScreenPos(posBlock, posView));
}

bool BlockRenderer::isVisible(const vec2 & posBlock, const vec2 & posView) const
{
	vec2 screenPos1 = getScreenPos(posBlock, posView);
	vec2 screenPos2 = screenPos1 + SIZE_BLOCK;
	// TODO: replace the magic numbers with constants
	return isBetween(screenPos1.x, 0.0f, 800.0f) && isBetween(screenPos1.y, 0.0f, 600.0f)
		&& isBetween(screenPos2.x, 0.0f, 800.0f) && isBetween(screenPos2.y, 0.0f, 600.0f);
}
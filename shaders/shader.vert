#version 330 core

layout (location = 0) in vec4 position;

out vec2 o_tex_coord;

uniform mat4 model;
uniform mat4 proj;

void main()
{
	gl_Position = proj * model * position;
	o_tex_coord = vec2(1.0-position.x, 1.0-position.y);
}
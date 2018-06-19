#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec2 tex_coord;

out vec2 o_tex_coord;

uniform mat4 model;
uniform mat4 proj;

void main()
{
	gl_Position = proj * model * position;
	o_tex_coord = tex_coord;
}
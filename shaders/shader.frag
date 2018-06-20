#version 330 core

in vec2 o_tex_coord;

uniform sampler2D tex;

out vec4 color;

void main()
{
	color = texture(tex, o_tex_coord);
}
#include "shader.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader()
{
}

void Shader::load(const char * vSrc, const char * fSrc)
{
	GLuint vShader = loadShader(vSrc, GL_VERTEX_SHADER);
	GLuint fShader = loadShader(fSrc, GL_FRAGMENT_SHADER);
	loadProgram(vShader, fShader);
}

void Shader::use() const
{
	glUseProgram(prog);
}

void Shader::clear() const
{
	glDeleteProgram(prog);
}

GLuint Shader::loadShader(const char * src, GLenum type)
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);
	checkErrors(shader, true);
	return shader;
}

void Shader::loadProgram(GLuint vShader, GLuint fShader)
{
	prog = glCreateProgram();
	glAttachShader(prog, vShader);
	glAttachShader(prog, fShader);
	glLinkProgram(prog);
	checkErrors(prog, false);
	
	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

void Shader::checkErrors(GLuint id, GLenum type) const
{
	bool status = _getStatus(id, type);
	if (!status)
	{
		GLchar * log = _getLog(id, type);
		std::cout << "ERROR: Shader compilation failed, type: " << typeName(type) << ", info log:\n" << log << std::endl;
		delete[] log;
	}
}

#define _ifElseByIsShader(s1, s2) if (type != PROGRAM) (s1); else (s2)

bool Shader::_getStatus(GLuint id, GLenum type) const
{
	GLint status;
	_ifElseByIsShader(
		glGetShaderiv(id, GL_COMPILE_STATUS, &status), 
		glGetProgramiv(id, GL_LINK_STATUS, &status)
	);
	return status == GL_TRUE;
}

GLchar * Shader::_getLog(GLuint id, GLenum type) const
{
	GLint len;
	_ifElseByIsShader(
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len),
		glGetProgramiv(id, GL_INFO_LOG_LENGTH, &len)
	);
	GLchar * log = new GLchar[len + 1];
	_ifElseByIsShader(
		glGetShaderInfoLog(id, len + 1, nullptr, log),
		glGetProgramInfoLog(id, len + 1, nullptr, log)
	);
	return log;
}

const char * Shader::typeName(GLenum type) const
{
	switch (type)
	{
	case GL_VERTEX_SHADER:
		return "VERTEX";
	case GL_FRAGMENT_SHADER:
		return "FRAGMENT";
	case PROGRAM:
		return "PROGRAM";
	default:
		return "<UNKNOWN>";
	}
}

void Shader::setmat4f(const char * name, const glm::mat4 & m)
{
	glUniformMatrix4fv(glGetUniformLocation(prog, name), 1, GL_FALSE, glm::value_ptr(m));
}
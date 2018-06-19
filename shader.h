#ifndef SHADER_H_
#define SHADER_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

const GLenum PROGRAM = 0;

class Shader
{
private:
	GLuint prog;

	GLuint loadShader(const char * src, GLenum type);
	void loadProgram(GLuint vShader, GLuint fShader);

	void checkErrors(GLuint id, GLenum type) const;

	const char * typeName(GLenum type) const;

	bool _getStatus(GLuint id, GLenum type) const;
	GLchar * _getLog(GLuint id, GLenum type) const;
public:
	Shader();
	void load(const char * vSrc, const char * fSrc);
	void use() const;
	void clear() const;

	void setmat4f(const char * name, const glm::mat4 & m);
};

#endif
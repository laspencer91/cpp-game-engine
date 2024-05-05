#include "Renderer.hpp"
#include <iostream>

// RENDERING
float triangle_vertices[] =
{
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

Renderer* Renderer::Initialize()
{
	_defaultShaderProgram = new Shader("default.vshader", "default.fshader");
	_currentShaderProgram = _defaultShaderProgram;
	_UpdateVertexBuffers();

	return this;
}

void Renderer::RenderFrame()
{
	glClearColor(0.2f, 0.2f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(_currentShaderProgram->ID);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::SetShader(Shader& _shader)
{
	_currentShaderProgram = &_shader;
}

void Renderer::_UpdateVertexBuffers()
{
	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// The call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
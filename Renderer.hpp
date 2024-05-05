#pragma once
#include <glad/glad.h> 
#include <glfw3.h>
#include "Shader.hpp"

class Renderer
{
public:
	Renderer* Initialize();

	void RenderFrame();

	void SetShader(Shader& _shader);

private:
	Shader* _currentShaderProgram;

	Shader* _defaultShaderProgram;

	void _UpdateVertexBuffers();
};


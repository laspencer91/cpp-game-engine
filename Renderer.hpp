#pragma once
#include <glad/glad.h> 
#include <glfw3.h>
#include <vector>
#include "Renderable.hpp"
#include "Shader.hpp"

class Renderer
{
public:
	Renderer* Initialize();

	void RenderFrame();

	void SetShader(Shader& _shader);

private:
	std::vector<Renderable*> _renderables;

	Shader* _currentShaderProgram;
};


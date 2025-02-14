#include <vector>
#include "glad/glad.h"
#include "Shader.hpp"
#include "EngineDefaults.hpp"

#pragma once
class Renderable
{
public:
	Renderable(std::vector<float> verts);
	Shader* GetShader();
	void SetShader(Shader* shader);
	void Bind();
	void Draw();

private:
	unsigned int VAO, VBO;
	std::vector<float> vertices;
	Shader* shader;

	void _Initialize();

	~Renderable()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
};


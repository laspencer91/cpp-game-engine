#include "Renderable.hpp"

Renderable::Renderable(std::vector<float> verts) : vertices(std::move(verts))
{
	shader = EngineDefaults::GetDefaultShader();
	_Initialize();
}

Shader* Renderable::GetShader()
{
	return shader;
}

void Renderable::SetShader(Shader* _shader)
{
	shader = _shader;
}

void Renderable::Bind()
{
	glBindVertexArray(VAO);
}

void Renderable::Draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderable::_Initialize()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
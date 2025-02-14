#include "Renderer.hpp"
#include "ShaderSource.hpp"
#include <iostream>

// RENDERING


Renderer* Renderer::Initialize()
{
	_renderables.push_back(new Renderable({
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	}));

	Renderable* r = new Renderable({
		-1.0f, -0.5f, 0.0f,
		-0.6f, -0.5f, 0.0f,
		-0.6f,  0.5f, 0.0f
	});
	r->SetShader(new Shader(Shaders::VERTEX_DEFAULT, Shaders::FRAG_BLUE));

	_renderables.push_back(r);

	return this;
}

void Renderer::RenderFrame()
{
	glClearColor(0.2f, 0.2f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < _renderables.size(); i++)
	{
		Renderable* renderable = _renderables[i];

		Shader* newShader = renderable->GetShader();

		// Updating shader for each object may be a bit much.
		glUseProgram(renderable->GetShader()->ID);

		renderable->Bind();
		renderable->Draw();
	}
}
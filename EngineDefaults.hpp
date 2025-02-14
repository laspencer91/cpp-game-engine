#pragma once
#include "Shader.hpp"

class EngineDefaults
{
public:
	static Shader* GetDefaultShader();

private:
	static Shader DEFAULT_SHADER;
};


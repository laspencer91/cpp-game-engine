#pragma once
#include "Shader.hpp"

class EngineDefaults
{
public:
	static Shader* GetDefaultShader();

    static constexpr const char* SHADER_DIR = "./shaders/";

private:
	static Shader DEFAULT_SHADER;
};


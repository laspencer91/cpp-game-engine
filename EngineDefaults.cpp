#include "EngineDefaults.hpp"

Shader* EngineDefaults::GetDefaultShader()
{
	static Shader DEFAULT_SHADER("default.vshader", "default.fshader");
	return &DEFAULT_SHADER;
}

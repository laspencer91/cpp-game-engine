#include "EngineDefaults.hpp"
#include "ShaderSource.hpp"

Shader* EngineDefaults::GetDefaultShader()
{
	static Shader DEFAULT_SHADER(Shaders::VERTEX_DEFAULT, Shaders::FRAG_DEFAULT);
	return &DEFAULT_SHADER;
}

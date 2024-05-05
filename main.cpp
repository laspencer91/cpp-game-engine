#include <glad/glad.h> 
#include <glfw3.h>
#include <iostream>
#include "Game.hpp"
#include "Shader.hpp"

int main() 
{
	Game* game = (new Game())->Initialize("Test Game", 1920, 1080);

	game->GetRenderer().SetShader(*_blueShader);

	while (game->IsRunning())
	{
		game->Play();
	}

	return 0;
}
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include "Game.hpp"
#include "Shader.hpp"

int main() 
{
	Game* game = (new Game())->Initialize("Test Game", 1920, 1080);

	while (game->IsRunning())
	{
		game->Play();
	}

	return 0;
}
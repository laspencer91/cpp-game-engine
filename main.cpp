#include <glad/glad.h> 
#include <glfw3.h>
#include <iostream>
#include "Game.hpp"
#include "Shader.hpp"
#include "Array.hpp"


int main() 
{
	auto testArray = new Array<std::string>({ "Logan"});
	std::cout << *testArray << std::endl;
	testArray->Stack("Spencer");
	std::cout << *testArray << std::endl;
	auto val = testArray->Pop();
	std::cout << *val << std::endl;
	std::cout << *testArray << std::endl;
	//Game* game = (new Game())->Initialize("Test Game", 1920, 1080);

	//while (game->IsRunning())
	//{
	//	game->Play();
	//}

	return 0;
}
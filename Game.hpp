#include <glad/glad.h> 
#include <glfw3.h>
#include <iostream>
#include "Renderer.hpp"

enum GameState
{
	NotInitialized,
	Initialized,
	Terminated
};

#pragma once
class Game
{
public:
	const bool IsRunning();

	const GLFWwindow& GetWindow();

	Game* Initialize(std::string windowTitle, int width, int height);

	Renderer& GetRenderer();

	void Play();

private:
	GLFWwindow* _window;

	Renderer* _renderer;

	GameState _state = GameState::NotInitialized;

	void _ProcessInput();

	~Game()
	{
		glfwTerminate();
	}
};


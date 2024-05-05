#include "Game.hpp"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

const bool Game::IsRunning()
{
	return _state != GameState::Terminated;
}

const GLFWwindow& Game::GetWindow()
{
	return *_window;
}

Game* Game::Initialize(std::string windowTitle, int width, int height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	const char* titleCString = windowTitle.c_str();
	_window = glfwCreateWindow(width, height, titleCString, NULL, NULL);
	if (_window == NULL)
	{
		std::cout << "Failed to initialize window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::exception("Failed to initialize GLAD. Is GLAD properly linked for this project?");
	}

	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

	_renderer = (new Renderer())->Initialize();

	_state = GameState::Initialized;

	return this;
}

Renderer& Game::GetRenderer()
{
	return *_renderer;
}

void Game::Play()
{
	if (_state == GameState::NotInitialized)
	{
		std::cout << "Game must be initialized with Game->Initialize() before calling Play()" << std::endl;
		_state = GameState::Terminated;
		return;
	}

	if (glfwWindowShouldClose(_window))
	{
		_state = GameState::Terminated;
		return;
	};

	_ProcessInput();

	_renderer->RenderFrame();

	glfwSwapBuffers(_window);
	glfwPollEvents();
}

void Game::_ProcessInput()
{
	if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(_window, true);
}

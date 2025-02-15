#include "Shader.hpp"
#include "EngineDefaults.hpp"
#include "Constants.hpp"

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>

Shader::Shader(const char* vertexCode, const char* fragmentCode)
{
    // This was functionality to read shader from the file. It worked properly, but was not easy to bundle shader files with CMAKE.
    // May come back to it later, so leaving this here.
    // std::string vertexCode;
    // std::string fragmentCode;
    // std::ifstream vertexShaderFile;
    // std::ifstream fragmentShaderFile;
    // vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    // fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    // try
    // {
    //     // vertexShaderFile.open(vertexPath);
    //     // fragmentShaderFile.open(fragmentPath);

    //     // std::stringstream vertShaderStream, fragShaderStream;
    //     // vertShaderStream << vertexShaderFile.rdbuf();
    //     // fragShaderStream << fragmentShaderFile.rdbuf();

    //     // vertexShaderFile.close();
    //     // fragmentShaderFile.close();

    //     // vertexCode = vertShaderStream.str();
    //     // fragmentCode = fragShaderStream.str();
    // }
    // catch (std::ifstream::failure e)
    // {
    //     std::cout << Console::C_RED << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl << "DO NOT INCLUDE SHADER DIRECTORY IN YOUR PATH" << std::endl << vertexPath << std::endl << fragmentPath << Console::C_RESET << std::endl;
    // }
    const char* vertexShaderCode = vertexCode;
    const char* fragmetShaderCode = fragmentCode;

    int success;
    char infoLog[512];

    // Vertex Shader
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexShaderCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Fragment Shader
    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmetShaderCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Initialize Shader Program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

cmake_minimum_required(VERSION 3.16)
project(LogansGameEngine)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(thirdparty/glfw-3.3.2)			#window oppener
add_subdirectory(thirdparty/glad)				#opengl loader

add_executable(${PROJECT_NAME} 
    main.cpp
    Game.cpp
    EngineDefaults.cpp
    Renderable.cpp
    Renderer.cpp
    Shader.cpp
    ShaderSource.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/thirdparty/glfw-3.3.2/include/GLFW
    ${CMAKE_SOURCE_DIR}/thirdparty/glad/include
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
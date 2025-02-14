# cpp-game-engine
Custom game engine built in C++ using glfw. 

## Prerequisites

- CMake (3.16 or higher)
- C++ compiler with C++11 support
- GLFW and GLAD (included in project)

## Building the Project

### Windows Users (Quick Start)
Simply run the batch file at the project root:
```batch
.\build.bat
```

### Manual Build
1. Create a build directory:
```bash
mkdir build
cd build
```

2. Generate build files:
```bash
cmake ..
```

3. Build the project:
```bash
cmake --build .
```

## Project Structure

```
cpp-game-engine/
├── include/          # Header files
├── src/             # Source files
├── thirdparty/      # External dependencies
│   ├── glad/        # OpenGL loader
│   └── glfw-3.3.2/  # Window management
├── CMakeLists.txt   # Build configuration
└── build.bat        # Windows build script
```

## Troubleshooting

If you encounter any issues:
1. Make sure all prerequisites are installed
2. Clean the build directory and rebuild
3. Check that your graphics drivers are up to date

## License

[Your license information here]

Would you like me to add any additional sections or details?
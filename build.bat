@echo off
cd build
cmake ..
cmake --build .
"./Debug/LogansGameEngine.exe"
cd ../..
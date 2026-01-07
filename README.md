# Snake (C++ / SDL3)

A minimal version of Conway's Game Of Life written in C++ using SDL3 for rendering.



## Features
- **C++20 Standard**
- **SDL3** for graphics and input handling.
- **CMake FetchContent**: Automatic dependency management (no manual SDL installation required).

## Build & Run

### Prerequisites
- C++20 compatible compiler
- CMake 3.20+

### Instructions (Terminal)
```bash
git clone https://github.com/zekgio/ConwayGameOfLifeSDL3.git
cd SimpleSnakeSDL3
cmake --preset x64-debug
cmake --build --preset x64-debug
./out/build/x64-debug/ConwayGameOfLifeSDL3.exe  (or .\out\build\x64-debug\ConwayGameOfLifeSDL3.exe if on Windows)

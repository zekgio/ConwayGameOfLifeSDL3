# Game Of Life (C++ / SDL3)

A minimal version of Conway's Game Of Life written in C++ using SDL3 for rendering.

![gameoflife](https://github.com/user-attachments/assets/6abb9594-2f3c-44dd-81c3-948f80a45370)

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
cd ConwayGameOfLifeSDL3
cmake --preset x64-debug
cmake --build --preset x64-debug
./out/build/x64-debug/ConwayGameOfLifeSDL3.exe  (or .\out\build\x64-debug\ConwayGameOfLifeSDL3.exe if on Windows)

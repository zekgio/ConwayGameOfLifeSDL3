#pragma once 

#include <SDL3/SDL.h>
#include <vector>

class G {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<SDL_FPoint> points;
    std::vector<SDL_Color> colors;
    SDL_Event event;

public:
    G();
    ~G();

    void drawpixel(double xm, double ym, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255, uint8_t a = 255);
    void clearpixels();
    void update();
    void input();
};
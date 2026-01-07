#include "screen.h"
#include <cstdlib>

using namespace std;

G::G()
{
    // initialize SDL, window and renderer
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Error Init SDL: %s", SDL_GetError());
        return;
    }
    if (!SDL_CreateWindowAndRenderer("Game of life", 640, 480, 0, &window, &renderer)) {
        SDL_Log("Errore Creazione Finestra: %s", SDL_GetError());
        return;
    }
    SDL_SetRenderScale(renderer, 1.0f, 1.0f);
}

G::~G()
{
    // destroy object
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void G::drawpixel(double xm, double ym, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    points.emplace_back(SDL_FPoint{ (float)xm, (float)ym });
    colors.emplace_back(SDL_Color{ r, g, b, a });
}

void G::clearpixels()
{
    points.clear();
    colors.clear();
}

void G::update()
{
    // clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    // draw alive cells
    for (size_t i = 0; i < points.size(); i++)
    {
        SDL_SetRenderDrawColor(renderer, colors[i].r, colors[i].g, colors[i].b, colors[i].a);
        SDL_RenderPoint(renderer, points[i].x, points[i].y);
    }
    SDL_RenderPresent(renderer);
}

void G::input() {
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            exit(0);
            break;
        default:
            break;
        }
    }
}
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "sdl_stuff.h"
#include "px.h"
#include "triangle.h"
#include "line.h"
#include "graph.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> dimensions = {500, 500};
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(dimensions[0], dimensions[1], 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    vector<px> pxls = {};
    // triangle_filled({ 50, 100 }, { 50, -100 }, { -70, 50 }, { 100, 100, 100, 255 }, &pxls);
    triangle_wire({55, 105}, {50, -105}, {-75, 50}, {255, 255, 255, 255}, &pxls);
    // graph(dimensions, {64, 153, 153, 255}, -0.005, 0, 50, &pxls);

    triangle_shaded(
        {{255, 0, 0, 255},
         {50, 100}},
        {{0, 0, 255, 255},
         {50, -100}},
        {{0, 255, 0, 255},
         {-70, 50}},
        &pxls);

    show_px(pxls, renderer, dimensions);

    bool running = true;
    SDL_Event ev;
    while (running)
    {

        while (SDL_PollEvent(&ev) != 0)
        {
            if (ev.type == SDL_QUIT)
                running = false;
        }
        SDL_UpdateWindowSurface(window);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
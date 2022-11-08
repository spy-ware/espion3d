#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "sdl_stuff.h"
#include "px.h"
#include "triangle.h"
#include "line.h"
#include "misc.h"
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
    // triangle_wire({55, 105}, {50, -105}, {-75, 50}, {255, 255, 255, 255}, &pxls);
    // graph(dimensions, {64, 153, 153, 255}, -0.005, 0, 50, &pxls);

    vector<int> ascending;
    vector<int> descending;
    for (int i = 255; i >= 0; i--)
    {
        descending.push_back(i);
    }
    for (int i = 0; i <= 255; i++)
    {
        ascending.push_back(i);
    }

    int t = 0;
    int phase = 0;

    bool running = true;
    SDL_Event ev;
    while (running)
    {

        while (SDL_PollEvent(&ev) != 0)
        {
            if (ev.type == SDL_QUIT)
                running = false;
        }

        if (phase == 0)
        {
            triangle_shaded(
                {{ascending[t], 0, descending[t], 255},
                 {50, 100}},
                {{0, descending[t], ascending[t], 255},
                 {-70, 50}},
                {{descending[t], ascending[t], 0, 255},
                 {50, -100}},
                &pxls);
        }
        else if (phase == 1)
        {
            triangle_shaded(
                {{descending[t], ascending[t], 0, 255},
                 {50, 100}},
                {{ascending[t], 0, descending[t], 255},
                 {-70, 50}},
                {{0, descending[t], ascending[t], 255},
                 {50, -100}},
                &pxls);
        }
        else if (phase == 2)
        {
            triangle_shaded(
                {{0, descending[t], ascending[t], 255},
                 {50, 100}},
                {{descending[t], ascending[t], 0, 255},
                 {-70, 50}},
                {{ascending[t], 0, descending[t], 255},
                 {50, -100}},
                &pxls);
        }

        show_px(pxls, renderer, dimensions);
        SDL_UpdateWindowSurface(window);
        pxls = {};
        t += 15;
        if (t >= 255)
        {
            cout << phase << endl;
            t = 0;
            phase++;
            if (phase == 3)
            {
                phase = 0;
            }
        };
    }

    SDL_Quit();
    return 0;
}

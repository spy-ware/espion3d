#include <SDL2/SDL.h>
#include <vector>
#include "sdl_stuff.h"
#include "square.h"
#include "tetris.h"
#include "esp_structs.h"

using namespace std;

int main(int argc, char *argv[])
{
    int mode = 2;
    int resolution = 16;
    coord2_s grid = {10, 20};
    scene_info_s scene = {mode, resolution, {grid.x * resolution, grid.y * resolution}, {10, 20}};
    coord2_s dimensions = {grid.x * resolution, grid.y * resolution};
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(dimensions.x, dimensions.y, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    vector<point_s> pxls = {};
    draw_piece({3, 2}, {0, 255, 0, 255}, 3, &pxls, scene);
    show_px(pxls, renderer, dimensions, mode);
    SDL_UpdateWindowSurface(window);
    bool running = true;
    SDL_Event ev;
    while (running)
    {

        while (SDL_PollEvent(&ev) != 0)
        {
            if (ev.type == SDL_QUIT)
            {
                running = false;
            }
            if (ev.type == SDL_KEYDOWN)
            {
                if (ev.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }
        }
    }

    SDL_Quit();
    return 0;
}

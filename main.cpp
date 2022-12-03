#include <SDL2/SDL.h>
#include <vector>
#include "sdl_stuff.h"
#include "tetris.h"
#include "wave.h"
#include <cmath>
#include "esp_structs.h"
#include "tetris_structs.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Define scene properties
    int mode = 2;
    int resolution = 32;
    coord2_s grid = {10, 20};
    coord2_s dimensions = {400, 400};
    float increment = 0.1;
    scene_info_s scene = {mode, resolution, dimensions, grid, increment, 1, dimensions.x / increment};

    // Define scene properties

    // Set up SDL window
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    vector<wave_point_s> points_wave = {};
    vector<wave_point_s> points_wave_cos = {};
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(dimensions.x, dimensions.y, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    // Set up SDL window

    // piece_s piece = {L_spaces, {0, 255, 0, 2}, {2, 2}};
    vector<point_s> pxls = {};
    // draw_piece(piece, scene, &pxls);
    show_px(pxls, renderer, dimensions, mode);
    SDL_UpdateWindowSurface(window);
    bool running = true;
    SDL_Event ev;
    float time;
    while (running)
    {
        clear_px(&pxls, renderer);
        points_wave.push_back({{scene.dimensions.x, (scene.dimensions.x / 2) + ((dimensions.y / 2) * 0.85 * sin(time))},
                               0,
                               {50, 80, 255, 255}});
        points_wave = progress_all_points(points_wave, scene);
        draw_wave_point(&pxls, scene, points_wave);
        show_px(pxls, renderer, dimensions, mode);
        SDL_UpdateWindowSurface(window);
        time += 0.001;
        while (SDL_PollEvent(&ev) != 0)
        {
            if (ev.type == SDL_QUIT)
            {
                running = false;
            }
            switch (ev.key.keysym.sym)
            {
            case (SDLK_ESCAPE):
                running = false;
                break;
            }
        }
    }

    SDL_Quit();
    return 0;
}

#include <SDL2/SDL.h>
#include <vector>
#include "sdl_stuff.h"
#include "tetris.h"
#include "esp_structs.h"
#include "tetris_structs.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Define scene properties
    int mode = 2;
    int resolution = 32;
    coord2_s grid = {10, 20};
    scene_info_s scene = {mode, resolution, {grid.x * resolution, grid.y * resolution}, {10, 20}};
    coord2_s dimensions = {grid.x * resolution, grid.y * resolution};
    // Define scene properties

    // Set up SDL window
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(dimensions.x, dimensions.y, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    // Set up SDL window

    piece_s piece = {L_spaces, {0, 255, 0, 2}, {2, 2}};
    vector<point_s> pxls = {};
    draw_piece(piece, scene, &pxls);
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
                switch (ev.key.keysym.sym)
                {
                case (SDLK_ESCAPE):
                    running = false;
                    break;

                case (SDLK_r):

                    piece = rotate_piece(piece);
                    break;
                case (SDLK_a):

                    piece.pos.x -= 1;
                    break;

                case (SDLK_w):

                    piece.pos.y -= 1;
                    break;
                case (SDLK_s):

                    piece.pos.y += 1;
                    break;

                case (SDLK_d):

                    piece.pos.x += 1;
                    break;
                }
            }
            clear_px(&pxls, renderer);
            draw_piece(piece, scene, &pxls);
            show_px(pxls, renderer, dimensions, mode);
            SDL_UpdateWindowSurface(window);
        }
    }

    SDL_Quit();
    return 0;
}

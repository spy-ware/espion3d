#include "esp_structs.h"
#include <vector>
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
#pragma once

void place_px(color_s rgba, coord2_s xy, vector<point_s> *pixels)
{
	pixels->push_back({xy, rgba});
}

void clear_px(vector<point_s> *pixels, SDL_Renderer *renderer)
{
	pixels->clear();
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void show_px(vector<point_s> pixels, SDL_Renderer *renderer, coord2_s screen, int mode)
{
	// screen: {width, height}
	for (point_s pixel : pixels)
	{

		SDL_SetRenderDrawColor(renderer, pixel.clr.r, pixel.clr.g, pixel.clr.b, pixel.clr.a);

		if (mode == 1)
		{
			SDL_RenderDrawPoint(renderer, (screen.x / 2) + pixel.coord.x, (screen.y / 2) - pixel.coord.y);
		}
		else if (mode == 2)
		{
			SDL_RenderDrawPoint(renderer, pixel.coord.x, pixel.coord.y);
		}
	}
	SDL_RenderPresent(renderer);
}

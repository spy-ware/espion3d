#include <vector>
#include <iostream>
#include "esp_structs.h"
#pragma once
using namespace std;

void square(coord2_s point1, coord2_s point2, color_s color, vector<point_s> *pixels)
{
    // interp for each y
    //      interp for each x

    // ensure point1 is higher than point 2
    if (point1.y < point2.y)
    {
        coord2_s temp;
        temp = point1;
        point1 = point2;
        point2 = temp;
    }
    {
        for (int y = point2.y; y <= point1.y; y++)
        {
            if (point1.x > point2.x)
            {
                for (int x = point2.x; x <= point1.x; x++)
                {
                    pixels->push_back(
                        {{x, y},
                         {color.r, color.g, color.b, color.a}});
                }
            }
            else
            {
                for (int x = point1.x; x <= point2.x; x++)
                {
                    pixels->push_back(
                        {{x, y},
                         {color.r, color.g, color.b, color.a}});
                }
            }
            cout << "line completed\n\n";
        }
    }
}

void draw_square_grid(coord2_s coord, color_s color, scene_info_s scene, vector<point_s> *pixels)
{
    /*
    coord: coordinates of the square
    color: color of the square
    screen dimensions: screen's width / height
    grid_numbers: how many squares fit in the width/how many squares fit in the height
    */
    coord2_s unit = {scene.dimensions.x / scene.grid.x, scene.dimensions.y / scene.grid.y};

    square({unit.x * (coord.x - 1), unit.y * (coord.y - 1)}, {unit.x * coord.x, unit.y * coord.y}, color, pixels);
}
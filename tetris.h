#include "tetris_structs.h"
#include "square.h"
#include "esp_structs.h"
#pragma once
#include <vector>
using namespace std;

void draw_piece(coord2_s origin, color_s color, int type_piece, vector<point_s> *pixels, scene_info_s scene)
{
    piece_s piece;
    switch (type_piece)
    {
    case 1:
        piece.piece_type = L_spaces;
        break;
    case 2:
        piece.piece_type = SQUARE_spaces;
        break;
    case 3:
        piece.piece_type = T_spaces;
        break;
    case 4:
        piece.piece_type = ZIGZAG_spaces;
        break;
    case 5:
        piece.piece_type = LINE_spaces;
        break;
    }
    piece.pos = origin;

    for (int y = 0; y < piece.piece_type.size(); y++)
    {
        for (int x = 0; x < piece.piece_type[y].size(); x++)
        {
            if (piece.piece_type[y][x] == true)
            {
                draw_square_grid({x + origin.x, y + origin.y}, color, scene, pixels);
            }
        }
    }
}
#pragma once
struct color_s
{
	int r, g, b, a;
};
struct coord2_s
{
	float x, y;
};
struct coord3_s
{
	int x, y, z;
};
struct point_s
{
	struct coord2_s coord;
	struct color_s clr;
};
struct rectangle_s
{
	struct point_s point1, point2;
};
struct triangle_s
{
	int type;
	// 0: line
	// 1: filled
	// 2: shaded
	struct point_s point1, point2, point3;
};
struct scene_info_s
{
	int coord_mode;
	int resolution;
	struct coord2_s dimensions;
	struct coord2_s grid;
	float wave_move_inc;
	float wave_age_inc;
	float max_age;
};
struct wave_point_s
{
	coord2_s pos;
	float age;
	color_s clr;
};
#include <vector>
#include "esp_structs.h"
#include "sdl_stuff.h"
#pragma once
using namespace std;

vector<int> interpolate(float i0, float d0, float i1, float d1)
{
	vector<int> points;
	if (i0 == i1)
	{
		points.push_back(d0);
		return points;
	}

	// calculate slope
	float a = (d1 - d0) / (i1 - i0);
	float d = d0;
	for (int i = i0; i <= i1; i++)
	{
		points.push_back(d);
		d = d + a;
	}
	return points;
}

vector<float> interpolate_float(float i0, float d0, float i1, float d1)
{
	vector<float> points;
	if (i0 == i1)
	{
		points.push_back(d0);
		return points;
	}

	float a = (d1 - d0) / (i1 - i0);
	float d = d0;
	for (int i = i0; i <= i1; i++)
	{
		points.push_back(d);
		d = d + a;
	}
	return points;
}

void line(coord2_s point1, coord2_s point2, color_s color, vector<point_s> *pixels)
{
	/*
			   [0] [1]
	   point: { x,  y }
	*/

	coord2_s temp;
	// difference of the 2 points' x values is bigger than difference in y values; line is more horizontal
	if (abs(point2.x - point1.x) > abs(point2.y - point1.y))
	{
		if (point1.x > point2.x)
		{
			temp = point1;
			point1 = point2;
			point2 = temp;
		}

		vector<int> y_values = interpolate(point1.x, point1.y, point2.x, point2.y);

		for (int i = point1.x; i < point2.x; i++)
		{
			pixels->push_back(
				{{i, y_values[i - point1.x]},
				 {color.r, color.g, color.b, color.a}});
		}
	}
	else
	{
		if (point1.y > point2.y)
		{
			temp = point1;
			point1 = point2;
			point2 = temp;
		}

		vector<int> x_values = interpolate(point1.y, point1.x, point2.y, point2.x);

		for (int i = point1.y; i < point2.y; i++)
		{
			pixels->push_back(
				{{x_values[i - point1.y], i},
				 {color.r, color.g, color.b, color.a}});
		}
	}
}

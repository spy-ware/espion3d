#include <vector>
#include <cmath>
#include "esp_structs.h"
using namespace std;
#pragma once

float distance2D(coord2_s point1, coord2_s point2)
{
	// point1, point2 = {x, y};

	float distance = sqrt(
		pow(
			abs(point1.x - point2.x), 2)

		+

		pow(
			abs(point1.y - point2.y), 2));

	return distance;
}

float distance3D(coord3_s point1, coord3_s point2)
{
	// point1, point2 = {x, y, z};

	float distance = sqrt(
		pow(
			abs(point1.x - point2.x), 2)

		+

		pow(
			abs(point1.y - point2.y), 2)

		+

		pow(
			abs(point1.z - point2.z), 2));

	return distance;
}
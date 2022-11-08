#include <vector>
using namespace std;
#pragma once
struct px
{
	vector<int> rgba;
	vector<int> xy;
};
struct rectangle
{
	px point1, point2;
};
struct triangle
{
	int type;
	// 0: line
	// 1: filled
	// 2: shaded
	px point1, point2, point3;
};
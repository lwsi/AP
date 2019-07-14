#pragma once
//
struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

//prototypes
polar rect_to_polar(const rect &xypos);
void show_polar(polar &dapos);

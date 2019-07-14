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

/* prototypes */
polar rect_to_polar(const rect &xypos);
void show_polar(polar &dapos);
// 输出斐波那契数列的第n个数 f(1) = 0, f(2) = 1, f(3) = 1
long long fibonacci(const int &n);

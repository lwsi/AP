#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "Self_Build_Lib.h"

using namespace std;

polar rect_to_polar(const rect &xypos)
{
	polar answer;

	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer;
}

void show_polar(polar &dapos)
{
	const double Rad_to_deg = 57.29577951;

	cout << "distance = " << dapos.distance;
	cout << ", angle = " << dapos.angle * Rad_to_deg;
	cout << " degrees\n";
}

long long fibonacci(const int &n)
{
	const long long fibarray[3] = { 0, 1, n };

	if (n <= 2)
		return fibarray[n - 1];
	for (int i = 2; i < n; ++i)
	{
		fibarray[2] = fibarray[0] + fibarray[1];
		fibarray[0] = fibarray[1];
		fibarray[1] = fibarray[2];
	}
	return fibarray[2];
}

int MaxBits(int *ptr, int length)
{
	int Bits = 0;
	// 计算数组ptr的最大值MAX
	int i, MAX = ptr[0];
	for (i = 1; i < length; ++i)
		if (MAX < ptr[i])
			MAX = ptr[i];
	// 计算最大值的位数
	while (MAX > 0)
	{
		MAX = MAX / 10;
		++Bits;
	}
	return Bits;
}

int FindPos(int i, int number)
{
	int value = 0;
	value = (number / (int)pow(10, (i - 1))) % 10;
	return value;
}
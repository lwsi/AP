// EarlyTandLateT.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

class Solution
{
private:
	std::vector<int> array1, array2, earlyTime, lateTime;
public:
	static void print(const int& a) { std::cout << a; }
	void Times(std::vector<int>& ar)
	{
		int num5 = 0;
		array1 = array2 = ar;
		sort(array1.begin(), array1.end(), std::less<int>());
		sort(array1.begin(), array1.end(), std::greater<int>());
		std::vector<int>::iterator it = ar.begin();
		for (; it != ar.end(); ++it) if (*it <= 5) ++num5;
		if (num5 <= 2) return;
		if (num5 == 3)
		{
			if (array1[0] > 1) return;
			for (int i = 0; i < 3; ++i)
			{
				earlyTime.push_back(array1[i]);
				earlyTime.push_back(array1[i+3]);
			}
			lateTime.push_back(array1[0]); lateTime.push_back(array2[0]);
			lateTime.push_back(array1[2]); lateTime.push_back(array2[1]);
			lateTime.push_back(array1[1]); lateTime.push_back(array2[2]);
			std::for_each(earlyTime.begin(), earlyTime.end(), print); std::cout << std::endl;
			std::for_each(lateTime.begin(), lateTime.end(), print); std::cout << std::endl;
		}
		if (num5 >= 4)
		{
			if ((array1[0] <= 1) || ((array1[0] == 2) && (array1[1] <= 3)))
			{
				if (num5 == 5 || num5 == 6) for (int i = 0; i < 6; ++i) earlyTime.push_back(array1[i]);
				else
				{
					for (int i = 0; i < 3; ++i) earlyTime.push_back(array1[i]);
					earlyTime.push_back(array1[4]);
					earlyTime.push_back(array1[3]);
					earlyTime.push_back(array1[5]);
				}
			}
			else return;
			for (int i = 0; i < 6; ++i) lateTime.push_back(0);
			bool have2 = false, have3 = false;
			for (int i = 0; i < 6; ++i)
			{
				if (array1[i] == 2)
			}
			if (have2 && have3) 
		}
	}
};

int main()
{
	int n, ans; std::vector<int> num; std::cin >> n;
	for (int i = 0; i < n; ++i) { std::cin >> ans; num.push_back(ans); }
	Solution Siqi; Siqi.Times(num);
	system("pause");
    return 0;
}


// FavorArray.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <fstream>

int times = 0;

class AmyKing
{
public:
	void favorArray(int count, int last, const int& n, const int& k)
	{
		int lastcurrent;
		if (count == n) { ++times; return; }
		for (int i = 1; i <= k; ++i)
		{
			if ((i >= last) || (last % i != 0))
			{ 
				++count; lastcurrent = i;
				favorArray(count, lastcurrent, n, k);
				--count;
			}
		}
	}
	void favorArray(const int& n, const int& k)
	{
		int last, count = 1;
		for (int i = 1; i <= k; ++i){ last = i; favorArray(count, last, n, k); }
	}
};

int main()
{
	int n, k; std::cin >> n >> k;
	AmyKing Siqi; Siqi.favorArray(n, k); std::cout << times << std::endl;
	system("pause");
    return 0;
}


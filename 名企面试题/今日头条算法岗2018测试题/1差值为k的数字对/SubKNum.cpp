// SubKNum.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int times = 0;

class AmyKing
{
public:
	void Knumchain(std::vector<int>& number, const int& k)
	{
		int lastnumber = 0;
		sort(number.begin(), number.end(), std::less<int>());
		for (int i = 0; i != number.size() - 1; ++i)
		{
			if (number[i] == lastnumber) continue;
			for (int j = i + 1; j != number.size(); ++j)
			{
				if (abs(number[i] - number[j]) == k) { ++times; break; }
			}
			lastnumber = number[i];
		}
	}
};

int main()
{
	int n, k, ans; std::vector<int> number; std::cin >> n >> k;
	for (int i = 0; i < n; ++i) { std::cin >> ans; number.push_back(ans); }
	AmyKing Siqi; Siqi.Knumchain(number, k); std::cout << times;
	system("pause");
    return 0;
}


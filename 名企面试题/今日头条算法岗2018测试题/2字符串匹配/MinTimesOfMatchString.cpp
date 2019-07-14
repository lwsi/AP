// MinTimesOfMatchString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <climits>

int times = INT_MAX;

class Solution
{
public:
	void leastMatch(int& n, int m, int s, int ans)
	{
		if (s == n){ if (ans < times) times = ans; }
		if (s < n)
		{
			s += m; ++ans;
			leastMatch(n, m, s, ans);
			s -= m; m = s; s += s;
			leastMatch(n, m, s, ans);
		}
	}
};

int main()
{
	int n, m = 1, s = 1; Solution Siqi;
	std::cin >> n; if (n <= 0 || n >= 1e4) return 0;
	if (n == 1 || n == 2) { times = 1; std::cout << times << std::endl; system("pause"); return 0; }
	Siqi.leastMatch(n, m, s, 0); std::cout << times << std::endl;
	system("pause");
    return 0;
}


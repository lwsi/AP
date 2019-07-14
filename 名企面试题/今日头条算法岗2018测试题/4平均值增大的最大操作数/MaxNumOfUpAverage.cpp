// MaxNumOfUpAverage.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

int times = 0;

class AmyKing
{
private:
	double aMean, bMean;
public:
	void MaxTimes(std::vector<int>& a, std::vector<int>& b)
	{
		aMean = std::accumulate(std::begin(a), std::end(a), 0.0) / a.size();
		bMean = std::accumulate(std::begin(b), std::end(b), 0.0) / b.size();
		
		if (aMean < bMean)
		{
			sort(b.begin(), b.end(), std::less<int>());
			std::vector<int>::iterator itb = b.begin();
			for (; itb != b.end(); ++itb)
			{
				std::vector<int>::iterator ita = find(a.begin(), a.end(), *itb);
				if (*itb > aMean && *itb < bMean && ita == a.end() && b.size() > 1)
				{
					 a.push_back(*itb); b.erase(itb);
					++times; MaxTimes(a, b); return;
				}
			}
		}
		else if (aMean > bMean)
		{
			sort(a.begin(), a.end(), std::less<int>());
			std::vector<int>::iterator ita = a.begin();
			for (; ita != a.end(); ++ita)
			{
				std::vector<int>::iterator itb = find(b.begin(), b.end(), *ita);
				if (*ita > bMean && *ita < aMean && itb == b.end() && a.size() > 1)
				{
					b.push_back(*ita); a.erase(ita);
					++times; MaxTimes(a, b); return;
				}
			}
		}
	}
};

int main()
{
	int n, m, ans; std::vector<int> a, b; AmyKing Siqi; std::cin >> n >> m;
	for (int i = 0; i < n; ++i) { std::cin >> ans; a.push_back(ans); }
	for (int i = 0; i < m; ++i){ std::cin >> ans; b.push_back(ans); }
	Siqi.MaxTimes(a, b); std::cout << times;
	system("pause");
    return 0;
}

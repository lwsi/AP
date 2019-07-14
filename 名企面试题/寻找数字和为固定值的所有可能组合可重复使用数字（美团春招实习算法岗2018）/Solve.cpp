// Solve.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <vector>

int count = 0;

class Solution {
private:
	std::vector<int> result;
public:
	void BackTracking(std::vector<int>& C, const int T)
	{
		static int sum = 0, flag = C[0];
		std::vector<int>::iterator iterC = C.begin();
		for (; *iterC != flag; ++iterC);
		for (; iterC < C.end(); ++iterC)
		{
			result.push_back(*iterC); sum += *iterC;
			if (sum == T)
			{
				std::vector<int>::iterator iterR = result.begin(); count++;
				for (; iterR < result.end(); ++iterR) std::cout << *iterR << " "; std::cout << "\n";
			}
			if (sum >= T) { result.pop_back(); sum -= *iterC; continue; }
			flag = *iterC; BackTracking(C, T);
			result.pop_back(); sum -= *iterC;
		}
	}
};

int main()
{
	Solution Siqi;
	Siqi.BackTracking(std::vector<int>{7, 3, 6, 2}, 10);
	std::cout << "总共：" << count << "种\n";
	system("pause");
	return 0;
}
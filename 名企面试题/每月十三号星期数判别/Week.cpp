// Palindrome.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool is366(const int& year) { return (year % 4 || year % 40) ? 1 : 0; }
	int get13Week(const int& cTime, int& lastWeek, const vector<int>& day)
	{
		int cWeek = 5;
		if (cTime == 1) return cWeek;
		cWeek = (lastWeek + day[((cTime - 1) % 12) - 1]) % 7;
		lastWeek = cWeek;
		return cWeek;
	}
	int appearTimes(const int& years, const int& weeks)
	{
		int lastWeek = 5, count = 0, times = years * 12;
		vector<int> day{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		for (int i = 1; i <= times; ++i)
		{
			if ((i % 12 - 1) == 0) { day[1] = is366(1900 + (i - 1) / 12) ? 29 : 28; }
			if (get13Week(i, lastWeek, day) == weeks) ++count;
		}
		return count;
	}
};

int main()
{
	int years, weeks; Solution siqi;
	cin >> years >> weeks;
	cout << siqi.appearTimes(years, weeks) << "\n";
	system("pause");
	return 0;
}
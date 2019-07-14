// Next Permutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	void nextPermutation1(vector<int>& nums) {
		if (nums.size() <= 1) return;
		bool havNexPer = false;
		vector<int>::reverse_iterator p1 = nums.rbegin(), p2 = nums.rbegin();
		for (int i = 1; i < nums.size(); ++i)
		{
			++p1;
			while (p1 - p2 > 0)
			{
				if (*p1 < *p2) { iter_swap(p1, p2); havNexPer = true; break; }
				else ++p2;
			}
			if (havNexPer) break;
			p2 = nums.rbegin();
		}
		if (havNexPer)
		{
			--p1; p2 = nums.rbegin();
			while (p1 - p2 >= 1) { iter_swap(p2, p1); ++p2; --p1; }
		}
		else sort(nums.begin(), nums.end());
	}
	void nextPermutation2(vector<int>& nums) {
		next_permutation(nums.begin(), nums.end());
	}
};

int main()
{
    return 0;
}


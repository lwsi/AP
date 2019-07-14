// 3SumClosest.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int closest = nums[0] + nums[1] + nums[2];
		if (nums.size() < 3) return 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			if (i > 0 && nums[i - 1] == nums[i]) continue;
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int curSum = nums[i] + nums[left] + nums[right];
				if (curSum == target) return curSum;
				if (abs(target - curSum) < abs(target - closest)) closest = curSum;
				if (curSum < target) ++left; else --right;
			}
		}
		return closest;
	}
};

int main()
{
	vector<int> nums{ -1, 2, 1, -4 };
	int target = 1;
	Solution siqi;
	cout << siqi.threeSumClosest(nums, target) << "\n";
	system("pause");
    return 0;
}


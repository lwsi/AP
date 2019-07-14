// 4Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> set;
		if (nums.size() < 4) return set;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; ++i)
		{
			if (i > 0 && nums[i - 1] == nums[i]) continue;
			if ((nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]) > target) break;
			if ((nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3]) < target) continue;
			for (int j = i + 1; j < nums.size() - 2; ++j)
			{
				if (j > i + 1 && nums[j - 1] == nums[j]) continue;
				if ((nums[i] + nums[j] + nums[j + 1] + nums[j + 2]) > target) break;
				if ((nums[i] + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2]) < target) continue;
				int left = j + 1;
				int right = nums.size() - 1;
				while (left < right)
				{
					int sum = nums[left] + nums[right] + nums[i] + nums[j];
					if (sum < target) ++left; else if (sum > target) --right;
					else
					{
						set.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						while ((left + 1) < nums.size() && nums[left + 1] == nums[left]) ++left; ++left;
						while ((right - 1) > j && nums[right - 1] == nums[right]) --right; --right;
					}
				}
			}
		}
		return set;
	}
};

int main()
{
    return 0;
}


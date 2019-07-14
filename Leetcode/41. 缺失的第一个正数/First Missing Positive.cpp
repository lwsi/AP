// First Missing Positive.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
		{
			if ((i + 1) == nums[i]) continue;
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);
		}
		for (int i = 0; i < nums.size(); ++i)
			if ((i + 1) != nums[i]) return i + 1;
		return nums.size() + 1;
	}
};

int main()
{
    return 0;
}


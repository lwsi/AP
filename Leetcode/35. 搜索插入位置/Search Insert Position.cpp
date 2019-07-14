// Search Insert Position.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		int i = 0, j = nums.size() - 1;
		while (i <= j)
		{
			int mid = (i + j) >> 1;
			if (nums[mid] < target) i = mid + 1;
			else j = mid - 1;
		}
		return i;
	}
};

int main()
{
    return 0;
}


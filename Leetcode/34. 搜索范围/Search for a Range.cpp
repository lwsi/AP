// Search for a Range.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1;
		vector<int> res{ -1, -1 };
		// 找到左点
		while (start < end)
		{
			int mid = (start + end) >> 1;
			if (nums[mid] < target) start = mid + 1;
			else if (nums[mid] > target) end = mid - 1;
			else end = mid;
		}
		if (nums[start] != target) return res;
		else res[0] = start;
		// 找到右点
		end = nums.size() - 1;
		target = target + 1;
		while (start < end)
		{
			int mid = (start + end) >> 1;
			if (nums[mid] > target) end = mid - 1;
			else start = mid;
		}
		if (nums[start] >= target)
			res[1] = start - 1;
		else res[1] = end;
		return res;
	}
};

int main()
{
    return 0;
}


// Remove Duplicates from Sorted Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		int len = 1;
		for (int i = 0, j = 1, k = 1; j < nums.size(); ++j)
		{
			if (nums[i] != nums[j])
			{
				++len;
				i = j;
				nums[k++] = nums[j];
			}
		}
		return len;
	}
};

int main()
{
    return 0;
}


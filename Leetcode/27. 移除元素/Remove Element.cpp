// Remove Element.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = 0;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != val)
				nums[len++] = nums[i];
		return len;
	}
};

int main()
{
    return 0;
}


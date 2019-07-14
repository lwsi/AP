// Trapping Rain Water.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

static auto x = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();
class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int res = 0, maxleft = 0, maxright = 0;
		while (left <= right) {
			if (height[left] <= height[right]) {
				if (height[left] >= maxleft) maxleft = height[left];
				else res += maxleft - height[left];
				++left;
			}
			else {
				if (height[right] >= maxright) maxright = height[right];
				else res += maxright - height[right];
				--right;
			}
		}
		return res;
	}
};

int main()
{
    return 0;
}


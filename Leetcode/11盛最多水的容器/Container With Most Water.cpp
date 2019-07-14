// Container With Most Water.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxV = 0, i = 0, j = height.size() - 1;
		while (i < j)
		{
			maxV = max(maxV, min(height[i], height[j]) * (j - i));
			if (height[i] < height[j]) ++i;
			else --j;
		}
		return maxV;
	}
};

int main()
{
	

    return 0;
}


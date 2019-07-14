// Search in Rotated Sorted Array.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] > nums[right]) left = mid + 1;
			else right = mid;
		}
		int min = left;
		left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) >> 1;
			int realmid = (mid + min) % nums.size();
			if (nums[realmid] == target) return realmid;
			else if (nums[realmid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
	}
};

int main()
{
    return 0;
}


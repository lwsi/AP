// Median of Two Sorted Arrays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int N1 = nums1.size(), N2 = nums2.size();
		if (N1 < N2) return findMedianSortedArrays(nums2, nums1);
		int l2 = 0, h2 = N2 << 1;
		while (l2 <= h2)
		{
			int mid2 = (l2 + h2) >> 1;
			int mid1 = N1 + N2 - mid2;

			double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) >> 1];
			double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) >> 1];
			double R1 = (mid1 == N1 << 1) ? INT_MAX : nums1[mid1 >> 1];
			double R2 = (mid2 == N2 << 1) ? INT_MAX : nums2[mid2 >> 1];

			if (L1 > R2) l2 = mid2 + 1;
			else if (L2 > R1) h2 = mid2 - 1;
			else return (max(L1, L2) + min(R1, R2)) / 2;
		}
		return -1;
	}
};

int main()
{
    return 0;
}


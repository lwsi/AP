// Combination Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef vector<vector<int>> vec2;
class Solution {
public:
	void backTracking(vector<int> &candidates, vector<int> &ans, vec2 &res, int target, int begin) {
		if (target == 0)
		{
			res.push_back(ans);
			return;
		}
		for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i)
		{
			ans.push_back(candidates[i]);
			backTracking(candidates, ans, res, target - candidates[i], i);
			ans.pop_back();
		}
	}
	vec2 combinationSum(vector<int>& candidates, int target) {
		vector<int> ans;
		vec2 res;
		sort(candidates.begin(), candidates.end());
		backTracking(candidates, ans, res, target, 0);
		return res;
	}
};

int main()
{
	vector<int> candidates(5);
	int k = 1;
	for (int i = 0; i < 5; ++i) {
		candidates[i] += k;
		++k;
	}
	for (int i = 0; i < 5; ++i)
		cout << candidates[i] << " ";
	system("pause");
    return 0;
}


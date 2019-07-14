// Combination Sum II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

typedef vector<int>::iterator vec_iter;
class Solution {
public:
	vec2 combinationSum2(vector<int>& candidates, int target) {
		vector<int> ans;
		vec2 res;
		sort(candidates.begin(), candidates.end());
		backTracking(candidates, ans, res, target, 0);
		return res;
	}
private:
	void backTracking(vector<int> &candidates, vector<int> &ans, vec2 &res, int target, int begin) {
		if (target == 0)
		{
			res.push_back(ans);
			return;
		}
		for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i)
		{
			if (i == begin || candidates[i] != candidates[i - 1]) {
				ans.push_back(candidates[i]);
				backTracking(candidates, ans, res, target - candidates[i], i + 1);
				ans.pop_back();
			}
		}
	}
};

int main()
{
    return 0;
}


// Letter Combinations of a Phone Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> set;
		if (digits.empty() || (digits.size() == 1 && digits[0] == '1')) return set;
		static const vector<string> v = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		set.push_back("");
		for (int i = 0; i < digits.size(); ++i)
		{
			int nums = digits[i] - '0';
			if (nums > 9 || nums < 0) break;
			const string& candidate = v[nums];
			if (candidate.empty()) continue;
			vector<string> tmp;
			for (int j = 0; j < candidate.size(); ++j)
			{
				for (int k = 0; k < set.size(); ++k)
				{
					tmp.push_back(set[k] + candidate[j]);
				}
			}
			set = tmp;
		}
		return set;
	}
};

int main()
{
	system("pause");
    return 0;
}


// ZigzagConvert.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		if (s.empty()) return "";
		string result;
		int len = s.size();
		int step1, step2;
		for (int i = 0; i < numRows; ++i)
		{
			step1 = (numRows - 1 - i) << 1;
			step2 = i << 1;
			int pos = i;
			if (pos < len) result.push_back(s[pos]);
			while (1)
			{
				pos += step1;
				if (pos >= len) break;
				if (step1) result.push_back(s[pos]);
				pos += step2;
				if (pos >= len) break;
				if (step2) result.push_back(s[pos]);
			}
		}
		return result;
	}
};

int main()
{
    return 0;
}


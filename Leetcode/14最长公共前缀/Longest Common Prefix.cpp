// Longest Common Prefix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		string s1 = strs[0];
		for (int i = 1; i < strs.size(); ++i)
		{
			string s2 = strs[i];
			if (s1.size() > s2.size()) s1 = s1.substr(0, s2.size());
			int ind = 0;
			while (ind != s1.size() && s1[ind] == s2[ind]) ++ind;
			s1 = s1.substr(0, ind);
		}
		return s1;
	}
};

int main()
{
	vector<string> strs;
	string s;
	for (int i = 0; i < 3; ++i)
	{
		cin >> s;
		strs.push_back(s);
	}
	Solution siqi;
	cout << siqi.longestCommonPrefix(strs) << "\n";
	system("pause");
    return 0;
}


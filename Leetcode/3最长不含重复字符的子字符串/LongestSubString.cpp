// LongestSubString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>

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
	int soulution1(string s) {
		int maxLen = 0, start = -1;
		vector<int> hash(256, -1);
		for (int i = 0; i != s.size(); ++i)
		{
			if (hash[s[i]] > start) start = hash[s[i]];
			hash[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}
		return maxLen;
	}
	int soulution2(string s) {
		int maxLen = 0, start = -1;
		unordered_map<char, int> hash;
		for (int i = 0; i != s.size(); ++i)
		{
			if (hash.find(s[i]) != hash.end()) start = max(start, hash[s[i]]);
			hash[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}
		return maxLen;
	}
};
int main()
{
	string s1 = "abcdaefacd";
	Solution AmyKing;
	cout << "solution1: " << AmyKing.soulution1(s1) << "\n";
	cout << "solution2: " << AmyKing.soulution2(s1) << "\n";
	system("pause");
    return 0;
}


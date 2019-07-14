// Longest Palindromic Substring.cpp : 定义控制台应用程序的入口点。
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
	string longestPalindrome(string s) {
		int len = s.size();
		if (len == 0) return "";
		if (len == 1) return s;
		int sPos = 0, maxLen = 1;
		for (int i = 0; i < len;)
		{
			if (maxLen >= (len - i) << 1) break;
			int j = i, k = i;
			while (k < len - 1 && s[k + 1] == s[k]) ++k; //skip duplicate characters.
			i = k + 1;
			while (k < len - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; }
			int newLen = k - j + 1;
			if (newLen > maxLen) { sPos = j; maxLen = newLen; }
		}
		return s.substr(sPos, maxLen);
	}
};

int main()
{
    return 0;
}


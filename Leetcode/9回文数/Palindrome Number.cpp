// Palindrome Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

class Solution {
public:
	inline bool isPalindrome(const char* start, const char* end)
	{
		return (start < end) ? ((*start == *end) ? isPalindrome(++start, --end) : false) : true;
	}
	bool isPalindrome(int x) {
		string s = to_string(x);
		const char* start = s.data();
		const char* end = start + s.size() - 1;
		return isPalindrome(start, end);
	}
};

int main()
{
    return 0;
}


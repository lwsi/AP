// Palindrome.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>

using namespace std;

inline bool isPalindrome1(char* start, char* end)
{
	return (start < end) ? ((*start == *end) ? isPalindrome1(++start, --end) : false) : true;
}

inline bool isPalindrome2(string& s) 
{ 
	string ans(s); reverse(s.begin(), s.end()); return s.find(ans, 0) ? 0 : 1; 
}

int main()
{
	string s1 = "abcba";
	char s2[] = "abcba";
	char* pStart = s2; char* pEnd = s2 + strlen(s2) - 1;
	
	cout << (isPalindrome1(pStart, pEnd) ? "是回文" : "不是回文") << "\n";
	cout << (isPalindrome2(s1) ? "是回文" : "不是回文") << "\n";
	cin.get(); return 0;
}
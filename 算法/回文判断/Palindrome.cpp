// Palindrome.cpp : �������̨Ӧ�ó������ڵ㡣

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
	
	cout << (isPalindrome1(pStart, pEnd) ? "�ǻ���" : "���ǻ���") << "\n";
	cout << (isPalindrome2(s1) ? "�ǻ���" : "���ǻ���") << "\n";
	cin.get(); return 0;
}
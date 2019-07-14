// ReverseInteger.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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
	int reverse1(int x) {
		string s = to_string(x); reverse(s.begin(), s.end());
		//	string::reverse_iterator it = tmp.rbegin();
		//	for (; it != tmp.rend(); ++it) s.push_back(*it);
		int flag = 0;
		if (s.back() == '-') { flag = 1; s.erase(s.size() - 1); }
		string range = flag ? "2147483648" : "2147483647";
		int len = range.size();
		if (len < s.size() || (len == s.size() && s > range)) return 0;
		if (flag == 1) s.insert(s.begin(), '-');
		return stoi(s);
	}
	int reverse2(int x) {
		long long res = 0;
		while (x) {
			res = res * 10 + x % 10;
			x /= 10;
		}
		return (res<INT_MIN || res>INT_MAX) ? 0 : res;
	}
};

int main()
{
	Solution AmyKing;
	//cout << AmyKing.reverse1(-2147483413) << "\n";
	cout << AmyKing.reverse2(-2147483412) << "\n";
	system("pause");
	return 0;
}


// Count and Say.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	string countAndSay(int n) {
		if (n <= 0) return "";
		string res = "1";
		while (--n) {
			string cur;
			for (int i = 0; i != res.size(); ++i) {
				int count = 1;
				while ((i + 1) < res.size() && res[i] == res[i + 1]) {
					++i; ++count;
				}
				cur += to_string(count) + res[i];
			}
			res = cur;
		}
		return res;
	}
};

int main()
{
    return 0;
}


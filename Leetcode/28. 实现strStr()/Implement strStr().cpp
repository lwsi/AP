// Implement strStr().cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		return haystack.find(needle, 0);
	}
};

int main()
{
	system("pause");
    return 0;
}


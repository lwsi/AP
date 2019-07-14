// Integer to Roman.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<string> Roman{ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M", "MM", "MMM" };

class Solution {
public:
	string intToRoman(int num) {
		string s; int k = 0;
		if (num < 1 || num > 3999) exit(0);
		while (num)
		{
			if (num % 10 == 0) { num /= 10; k++; continue; }
			s = Roman[9 * k++ + num % 10 - 1] + s;
			num /= 10;
		}
		return s;
	}
};

int main()
{
	Solution siqi; int num = 0;
	cin >> num;
	cout << siqi.intToRoman(num) << "\n";
	system("pause");
    return 0;
}


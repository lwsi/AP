// Myatoi.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <climits>

class Solution {
public:
	int myAtoi(string str) {
		long long result = 0;
		int indicator = 1, i = str.find_first_not_of(' ');
		if (str[i] == '-' || str[i] == '+') indicator = (str[i++] == '-') ? -1 : 1;
		while (i != str.size() && isdigit(str[i]))
		{
			result = result * 10 + (str[i++] - '0');
			if (result*indicator >= INT_MAX) return INT_MAX;
			if (result*indicator <= INT_MIN) return INT_MIN;
		}
		return result*indicator;
	}
};

int main()
{
    return 0;
}


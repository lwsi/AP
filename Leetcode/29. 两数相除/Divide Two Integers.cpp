// Divide Two Integers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
		long long div1 = labs(dividend), div2 = labs(divisor);
		int res = 0;
		while (div1 - div2 >= 0)
		{
			long long ans = div2;
			int product = 1;
			while (div1 >= (ans << 1))
			{
				ans <<= 1;
				product <<= 1;
			}
			div1 -= ans;
			res += product;
		}
		return ((dividend ^ divisor) < 0) ? -res : res;
	}
};

int main()
{
    return 0;
}


// Multiply Strings.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	string multiply(string num1, string num2) {
		string res;
		vector<int> ans(num1.size() + num2.size() - 1);
		for (int i = num1.size() - 1; i >= 0; --i) {
			int k = num1.size() - 1 - i;
			for (int j = num2.size() - 1; j >= 0; --j) {
				ans[k++] += (num1[i] - '0') * (num2[j] - '0');
			}
		}
		for (int i = 0; i < ans.size(); ++i) {
			if (ans[i] > 9) {
				if (i != ans.size() - 1) {
					ans[i + 1] += ans[i] / 10;
					ans[i] %= 10;
				}
				else {
					int tmp = ans[i] / 10;
					ans[i] %= 10;
					ans.push_back(tmp);
				}
			}
		}
		if (ans[ans.size() - 1] == 0) return "0";
		for (int i = ans.size() - 1; i >= 0; --i) res.push_back('0' + ans[i]);
		return res;
	}
};

int main()
{
    return 0;
}


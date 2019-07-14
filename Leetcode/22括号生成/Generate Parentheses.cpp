// Generate Parentheses.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void add(vector<string>& result, int left, int right, string s)
	{
		if (left == 0 && right == 0) { result.push_back(s); return; }
		if (left > 0) add(result, left - 1, right, s + '(');
		if (left < right) add(result, left, right - 1, s + ')');
	}
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		add(result, n, n, "");
		return result;
	}
};

int main()
{
    return 0;
}


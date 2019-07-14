// Valid Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		unordered_map<char, int> hash;
		unordered_map<char, int>::iterator it;
		hash['('] = 0; hash[')'] = 1; hash['['] = 2; hash[']'] = 3; hash['{'] = 4; hash['}'] = 5;
		vector<int> value;
		for (int i = 0; i < s.size(); ++i)
		{
			it = hash.find(s[i]);
			if (it != hash.end()) value.push_back((*it).second);
		}
		if (value.size() & 1 != 0) return false;
		int len = value.size();
		for (int i = 0; i < len - 1; ++i)
		{
			if ((value[i + 1] - value[i]) == 1)
			{
				value.erase((value.begin()+i));
				value.erase((value.begin()+i));
				--i;
				len = len - 2;
			}
		}
		int left = 0, right = value.size() - 1;
		while (left < right)
		{
			if ((value[right] - value[left]) != 1) return false;
			++left; --right;
		}
		return true;
	}
};


int main()
{
	string s{"([{()[]({[]})}])"};
	Solution siqi;
	cout << (siqi.isValid(s) ? "有效!" : "无效") << "\n";
	system("pause");
    return 0;
}


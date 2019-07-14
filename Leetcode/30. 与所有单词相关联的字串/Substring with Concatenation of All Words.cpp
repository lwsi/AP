// Substring with Concatenation of All Words.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (s.empty() || words.empty()) return res;
		unordered_map<string, int> hash;
		for (auto word : words) hash[word]++;
		int sL = s.size(), wN = words.size(), wL = words[0].size();
		for (int i = 0; i < wL; ++i)
		{
			int start = i, cnt = 0;
			unordered_map<string, int> tmp;
			while (start + wL * wN - 1 < sL)
			{
				string cur = s.substr(start + cnt * wL, wL);
				if (hash[cur] == 0)
				{
					start += (cnt + 1) * wL;
					cnt = 0; tmp.clear(); continue;
				}
				++cnt; ++tmp[cur];
				while (tmp[cur] > hash[cur])
				{
					--cnt;
					--tmp[s.substr(start, wL)];
					start += wL;
				}
				if (cnt == wN) res.push_back(start);
			}
		}
		return res;
	}
};

int main()
{
    return 0;
}


// 3Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isDuplicate(vector<vector<int>>& set, vector<int> element)
	{
		vector<vector<int>>::iterator it = set.begin();
		for (; it != set.end(); ++it)
		{
			vector<int>::iterator i1 = find((*it).begin(), (*it).end(), element[0]);
			vector<int>::iterator i2 = find((*it).begin(), (*it).end(), element[1]);
			vector<int>::iterator i3 = find((*it).begin(), (*it).end(), element[2]);
			if (i1 != (*it).end() && i2 != (*it).end() && i3 != (*it).end())
			{
				if (element[0] == element[1] && element[1] == element[2])
				{
					if ((*it)[0] == (*it)[1] && (*it)[1] == (*it)[2]) return true;
					else continue;
				}
				else return true;
			}
		}
		return false;
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) return{};
		unordered_map<int, int> hash;
		vector<vector<int>> set;
		vector<int>::iterator i1 = nums.begin();
		vector<int>::iterator i1End = nums.begin() + nums.size() - 2;
		for (; i1 != i1End; ++i1)
		{
			vector<int>::iterator i2 = i1 + 1;
			for (; i2 != nums.end(); ++i2)
			{
				if (hash.find((-1)*(*i1) - (*i2)) != hash.end())
				{
					vector<int> ans = { *i1, hash[(-1)*(*i1) - (*i2)], *i2 };
					if (set.empty()) { set.push_back(ans); continue; }
					else if (isDuplicate(set, ans)) continue; else set.push_back(ans); continue;
				}
				hash[*i2] = *i2;
			}
			hash.clear();
		}
		return set;
	}
};

int main()
{
	vector<int> nums{ 0, 0, 0, 0 };
	vector<vector<int>> set; Solution siqi; set = siqi.threeSum(nums);
	for (int i = 0; i != set.size(); ++i)
	{
		copy(set[i].begin(), set[i].end(), ostream_iterator<int>(cout, " "));
		cout << "\n";
	}
	system("pause");
    return 0;
}


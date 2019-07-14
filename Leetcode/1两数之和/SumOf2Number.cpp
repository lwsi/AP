// SumOf2Number.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();

void print(const int& element) { std::cout << element; }

class solution
{
public:
	vector<int> twosum1(vector<int>& nums, int target)
	{
		unordered_map<int,int> hash;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (hash.find(target - nums[i]) != hash.end())
			{
				return vector<int>{hash[target - nums[i]], i};
			}
			hash[nums[i]] = i;
		}
	}
	vector<int> twosum2(vector<int>& nums, int target)
	{
		map<int, int> hash;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (hash.find(target - nums[i]) != hash.end())
			{
				return vector<int>{hash[target - nums[i]], i};
			}
			hash.insert(pair<int, int>(nums[i], i));
		}
	}
	vector<int> twosum3(vector<int>& nums, int target)
	{
		multimap<int, int> hash;
		for (int i = 0; i != nums.size(); ++i)
		{
			multimap<int, int>::const_iterator it = hash.find(target - nums[i]);
			if (it != hash.end())
			{
				return vector<int>{it->second, i};
			}
			hash.insert(pair<int, int>(nums[i], i));
		}
	}
};

int main()
{
	vector<int> nums{ 11, 2, 7, 15 }; int target = 9;
	solution AmyKing; vector<int> result;
	result = AmyKing.twosum1(nums, target);
	for_each(result.begin(), result.end(), print); cout << "\n";
	result = AmyKing.twosum2(nums, target);
	for_each(result.begin(), result.end(), print); cout << "\n";
	result = AmyKing.twosum3(nums, target);
	for_each(result.begin(), result.end(), print); cout << "\n";

	system("pause");
    return 0;
}


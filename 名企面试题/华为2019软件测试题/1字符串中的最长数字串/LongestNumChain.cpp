// 2ArrayConvert.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <string>

#define isNumber(c) ((c) >= '0' && (c) <= '9')

class Solution
{
public:
	void longestNumberChain(std::string& s, std::string& maxNumChain)
	{
		std::string tmpChain;
		std::string::iterator it = s.begin();
		for (; it < s.end(); ++it)
		{
			if (isNumber(*it))
			{
				tmpChain.push_back(*it);
				if (it == (s.end() - 1))
				{
					if (maxNumChain.size() <= tmpChain.size())
					{
						maxNumChain.clear(); maxNumChain = tmpChain; tmpChain.clear();
					}
				}
			}
			else
			{
				if (maxNumChain.size() <= tmpChain.size())
				{
					maxNumChain.clear(); maxNumChain = tmpChain; tmpChain.clear();
				}
			}
		}
	}
};

int main()
{
	Solution Siqi;
	std::string s, maxNumChain;
	getline(std::cin, s);

	Siqi.longestNumberChain(s, maxNumChain);

	std::cout << maxNumChain << "," << maxNumChain.size();

	system("pause");
	return 0;
}
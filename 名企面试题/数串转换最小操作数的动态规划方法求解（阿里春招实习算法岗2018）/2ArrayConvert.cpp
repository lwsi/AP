// 2ArrayConvert.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

template <typename Exc> inline void Swap(Exc& a, Exc& b) { Exc temp = a; a = b; b = temp; }

template <class T> 
class Solution
{
private:
	std::vector<T> numberDist;
	std::vector<T> numberPlusIndex;
	std::vector<T> numberSubIndex;
	std::vector<T> numberIndex;
public:
	size_t MinTimes(std::vector<T>& number1, std::vector<T>& number2)
	{
		static size_t timesTurn = 0;
		for (;;)
		{
			T BestTurn[2] = { 0 };
			T BestValue = 0;
			// 获取差值序列&初始化索引数组
			for (unsigned int i = 0; i < number1.size(); ++i)
			{
				numberDist.push_back(number1[i] - number2[i]);
				numberIndex.push_back(i);
			}

			// 访问差值序列首地址
			T* pNumberDist = numberDist.data(); T* pNumberIndex = numberIndex.data();

			// 访问正负缓冲区
			for (int i = 0; i < numberDist.size(); ++i)
			{
				if (numberDist[i] < 0) numberSubIndex.push_back(numberIndex[i]);
				else if (numberDist[i] > 0) numberPlusIndex.push_back(numberIndex[i]);
			}
			reverse(numberPlusIndex.begin(), numberPlusIndex.end());

			// 正负缓冲区只要有一个为空，则调出循环结束计算
			if (numberSubIndex.empty() || numberPlusIndex.empty())
			{
				std::vector<T>::iterator it = numberDist.begin();
				for (; it < numberDist.end(); ++it) timesTurn += abs(*it);
				break;
			}

			// 循环比较提取最优交换下标索引
			for (int i = 0; i < numberSubIndex.size(); ++i)
			{
				for (int j = 0; j < numberPlusIndex.size(); ++j)
				{
					T Before = abs(numberDist[numberSubIndex[i]]) + abs(numberDist[numberPlusIndex[j]]);
					Swap(number1[numberSubIndex[i]], number1[numberPlusIndex[j]]);
					numberDist[numberSubIndex[i]] = number1[numberSubIndex[i]] - number2[numberSubIndex[i]];
					numberDist[numberPlusIndex[j]] = number1[numberPlusIndex[j]] - number2[numberPlusIndex[j]];
					T Current = abs(numberDist[numberSubIndex[i]]) + abs(numberDist[numberPlusIndex[j]]);
					if (Before - Current > BestValue)
					{
						BestValue = Before - Current;
						BestTurn[0] = numberSubIndex[i];
						BestTurn[1] = numberPlusIndex[j];
					}
					Swap(number1[numberSubIndex[i]], number1[numberPlusIndex[j]]);
					numberDist[numberSubIndex[i]] = number1[numberSubIndex[i]] - number2[numberSubIndex[i]];
					numberDist[numberPlusIndex[j]] = number1[numberPlusIndex[j]] - number2[numberPlusIndex[j]];
				}
			}
			if (BestTurn[0] == 0 && BestTurn[1] == 0)
			{
				std::vector<T>::iterator it = numberDist.begin();
				for (; it < numberDist.end(); ++it) timesTurn += abs(*it);
				break;
			}
			Swap(number1[BestTurn[0]], number1[BestTurn[1]]); timesTurn += 1;
			numberDist.clear(); numberIndex.clear();
			numberSubIndex.clear(); numberPlusIndex.clear();
		}

		return timesTurn;
	}
};

int main()
{
	Solution<int> Siqi;
	std::cout << "数串1为：{1, 6, 2, 7, 5}\n" << "数串2为：{3, 2, 6, 4, 9}\n";
	std::vector<int> number1{ 1, 6, 2, 7, 5 };
	std::vector<int> number2{ 3, 2, 6, 4, 9 };
	std::cout << "最小次数为：\n" << Siqi.MinTimes(number1, number2) << "\n";

	system("pause");
	return 0;
}


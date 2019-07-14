// 2ArrayConvert.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <iostream>
#include <vector>

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
	void quickSortForIndex(T* pNumberDist, T* pNumberIndex, int begin, int end)
	{
		if (begin < end)
		{
			int i = begin + 1, j = end;
			while (i < j)
			{
				if (pNumberDist[i] > pNumberDist[begin])
				{
					Swap(pNumberDist[i], pNumberDist[j]); Swap(pNumberIndex[i], pNumberIndex[j]); --j;
				}
				else ++i;
			}
			if (pNumberDist[i] >= pNumberDist[begin]) --i;
			Swap(pNumberDist[i], pNumberDist[begin]); Swap(pNumberIndex[i], pNumberIndex[begin]);
			quickSortForIndex(pNumberDist, pNumberIndex, begin, i);
			quickSortForIndex(pNumberDist, pNumberIndex, j, end);
		}
	}
	size_t MinTimes(std::vector<T>& number1, std::vector<T>& number2)
	{
		static size_t timesTurn = 0;
		T Before = 0, Current = 0;
		for (;;)
		{
			// ��ȡ��ֵ����&��ʼ����������
			for (unsigned int i = 0; i < number1.size(); ++i)
			{
				numberDist.push_back(number1[i] - number2[i]);
				numberIndex.push_back(i);
			}

			// ���ʲ�ֵ�����׵�ַ
			T* pNumberDist = numberDist.data(); T* pNumberIndex = numberIndex.data();

			// ��ֵ���򣬼�¼����������仯
			quickSortForIndex(pNumberDist, pNumberIndex, 0, numberDist.size() - 1);
			pNumberDist = pNumberIndex = nullptr;

			// ��������������
			for (int i = 0; i < numberDist.size(); ++i)
			{
				if (numberDist[i] < 0) numberSubIndex.push_back(numberIndex[i]);
				else if (numberDist[i] > 0) numberPlusIndex.push_back(numberIndex[i]);
			}
			reverse(numberPlusIndex.begin(), numberPlusIndex.end());

			// ����������ֻҪ��һ��Ϊ�գ������ѭ����������
			if (numberSubIndex.empty() || numberPlusIndex.empty())
			{
				std::vector<T>::iterator it = numberDist.begin();
				for (; it < numberDist.end(); ++it) timesTurn += abs(*it);
				break;
			}

			// ѭ���Ƚ���ȡ���Ž����±�����
			for (int i = 0; i < numberSubIndex.size(); ++i)
			{
				for (int j = 0; j < numberPlusIndex.size(); ++j)
				{
					Before = abs(numberDist[numberSubIndex[i]]) + abs(numberDist[numberPlusIndex[j]]);
					Swap(number1[numberSubIndex[i]], number1[numberPlusIndex[j]]);
					numberDist[numberSubIndex[i]] = number1[numberSubIndex[i]] - number2[numberSubIndex[i]];
					numberDist[numberPlusIndex[j]] = number1[numberPlusIndex[j]] - number2[numberPlusIndex[j]];
					Current = abs(numberDist[numberSubIndex[i]]) + abs(numberDist[numberPlusIndex[j]]);
					if (Before > Current) continue;
					Swap(number1[numberSubIndex[i]], number1[numberPlusIndex[j]]);
					numberDist[numberSubIndex[i]] = number1[numberSubIndex[i]] - number2[numberSubIndex[i]];
					numberDist[numberPlusIndex[j]] = number1[numberPlusIndex[j]] - number2[numberPlusIndex[j]];
				}
				if (Before > Current) continue;
			}
			if (Before > Current)
			{
				numberDist.clear(); numberIndex.clear();
				numberSubIndex.clear(); numberPlusIndex.clear();
				continue;
			}
			else
			{
				std::vector<T>::iterator it = numberDist.begin();
				for (; it < numberDist.end(); ++it) timesTurn += abs(*it);
				break;
			}
		}

		return timesTurn;
	}
};

int main()
{
	Solution<int> Siqi;
	std::cout << "����1Ϊ��{1, 6, 2, 7, 5}\n" << "����2Ϊ��{3, 2, 6, 4, 9}\n";
	std::vector<int> number1{ 1, 6, 2, 7, 5 };
	std::vector<int> number2{ 3, 2, 6, 4, 9 };
	std::cout << "��С����Ϊ��\n" << Siqi.MinTimes(number1, number2) << "\n";

	system("pause");
	return 0;
}


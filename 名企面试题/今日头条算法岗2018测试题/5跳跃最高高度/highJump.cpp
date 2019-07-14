// highJump.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

int highCurrent = 0;

class AmyKing
{
public:
	void highJump(std::vector<int>& highBoard, int K, const int& H, const int& N)
	{
		sort(highBoard.begin(), highBoard.end(), std::less<int>());
		for (int i = 0; i < N; ++i)
		{
			if (K == 0) return;
			if ((highBoard[i] - highCurrent) > H)
			{
				if (i == 0) return;
				highCurrent += (highBoard[i - 1] - highCurrent) << 1;
				--K; --i; continue;
			}
			if (i == N - 1) highCurrent += (highBoard[i] - highCurrent) << 1;
		}
	}
};

int main()
{
	int N, K, H, ans; std::vector<int> highBoard; std::cin >> N >> K >> H;
	for (int i = 0; i < N; ++i) { std::cin >> ans; highBoard.push_back(ans); }
	AmyKing Siqi; Siqi.highJump(highBoard, K, H, N); std::cout << highCurrent;

	system("pause");
    return 0;
}


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <windows.h>
class Solution
{
private:
	COORD pos;
public:
	void GeneratorNumber(const short& index, const char& ch, const int& len)
	{
		switch (ch)
		{
		case '0':
		{
			pos = { index * 7, 2 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 3; i < 8; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "6...6";
			}
			pos = { index * 7, 8 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			if (index < len - 1)
			{
				for (short i = 2; i <= 8; ++i)
				{
					pos = { index * 7 + 5, i };
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					std::cout << "..";
				}
			}
			break;
		}
		case '1':
		{
			pos = { index * 7, 2 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "....6";
			for (short i = 3; i < 8; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "....6";
			}
			pos = { index * 7, 8 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "....6";
			if (index < len - 1)
			{
				for (short i = 2; i <= 8; ++i)
				{
					pos = { index * 7 + 5, i };
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					std::cout << "..";
				}
			}
			break;
		}
		case '2':
		{
			pos = { index * 7, 2 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 3; i <= 4; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "....6";
			}
			pos = { index * 7, 5 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 6; i <= 7; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "6....";
			}
			pos = { index * 7, 8 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			if (index < len - 1)
			{
				for (short i = 2; i <= 8; ++i)
				{
					pos = { index * 7 + 5, i };
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					std::cout << "..";
				}
			}
			break;
		}
		case '3':
		{
			pos = { index * 7, 2 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 3; i <= 4; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "....6";
			}
			pos = { index * 7, 5 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 6; i <= 7; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "....6";
			}
			pos = { index * 7, 8 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			if (index < len - 1)
			{
				for (short i = 2; i <= 8; ++i)
				{
					pos = { index * 7 + 5, i };
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					std::cout << "..";
				}
			}
			break;
		}
		case '4':
		{
			for (short i = 2; i <= 4; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "6...6";
			}
			pos = { index * 7, 5 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 6; i <= 8; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "....6";
			}
			if (index < len - 1)
			{
				for (short i = 2; i <= 8; ++i)
				{
					pos = { index * 7 + 5, i };
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					std::cout << "..";
				}
			}
			break;
		}
		case '5':
		{
			pos = { index * 7, 2 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 3; i <= 4; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "6....";
			}
			pos = { index * 7, 5 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 6; i <= 7; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "....6";
			}
			pos = { index * 7, 8 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			if (index < len - 1)
			{
				for (short i = 2; i <= 8; ++i)
				{
					pos = { index * 7 + 5, i };
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					std::cout << "..";
				}
			}
			break;
		}
		case '6':
		{
			pos = { index * 7, 2 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 3; i <= 4; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "6....";
			}
			pos = { index * 7, 5 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 6; i <= 7; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "6...6";
			}
			pos = { index * 7, 8 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			if (index < len - 1)
			{
				for (short i = 2; i <= 8; ++i)
				{
					pos = { index * 7 + 5, i };
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					std::cout << "..";
				}
			}
			break;
		}
		case '7':
		{
			pos = { index * 7, 2 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 3; i <= 8; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "....6";
			}
			if (index < len - 1)
			{
				for (short i = 2; i <= 8; ++i)
				{
					pos = { index * 7 + 5, i };
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					std::cout << "..";
				}
			}
			break;
		}
		case '8':
		{
			pos = { index * 7, 2 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 3; i <= 4; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "6...6";
			}
			pos = { index * 7, 5 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 6; i <= 7; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "6...6";
			}
			pos = { index * 7, 8 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			if (index < len - 1)
			{
				for (short i = 2; i <= 8; ++i)
				{
					pos = { index * 7 + 5, i };
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					std::cout << "..";
				}
			}
			break;
		}
		case '9':
		{
			pos = { index * 7, 2 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 3; i <= 4; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "6...6";
			}
			pos = { index * 7, 5 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			for (short i = 6; i <= 7; ++i)
			{
				pos = { index * 7, i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << "....6";
			}
			pos = { index * 7, 8 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "66666";
			if (index < len - 1)
			{
				for (short i = 2; i <= 8; ++i)
				{
					pos = { index * 7 + 5, i };
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					std::cout << "..";
				}
			}
			break;
		}
		}
	}
	void PrintNumber(std::string& pattern)
	{
		const int len = pattern.size();
		for (short i = 0; i != len; ++i) GeneratorNumber(i, pattern[i], len);
		std::cout << std::endl;
	}
	void Calculate(std::string& pattern)
	{
		char *matchBegin, *matchEnd; int count1 = 0, count2 = 0;
		_int64 a, b; int sign = 0;
		// 先计算乘法部分
		for (int i = 0; i != pattern.size(); ++i)
		{
			if (pattern[i] == '*')
			{
				const char *patBegin = pattern.data(), *patEnd = pattern.data() + pattern.size() - 1;
				matchBegin = &pattern[i - 1]; matchEnd = &pattern[i + 1];
				while ((matchBegin != (patBegin - 1)) && ('0' <= *matchBegin) && (*matchBegin <= '9')) {
					--matchBegin; ++count1;
				}
				while ((matchEnd != (patEnd + 1)) && ('0' <= *matchEnd) && (*matchEnd <= '9')) {
					++matchEnd; ++count2;
				}
				a = atoi((pattern.substr(i - count1, count1)).c_str());
				b = atoi((pattern.substr(i + 1, count2)).c_str());
				pattern.erase(i - count1, count1 + count2 + 1);
				pattern.insert(i - count1, std::to_string(a * b));
				i -= (count1 + 1); count1 = count2 = 0;
				patBegin = patEnd = nullptr;
			}
		}
		// 再计算加减法部分
		for (int i = 0; i != pattern.size(); ++i)
		{
			if (pattern[i] == '+')
			{
				const char *patBegin = pattern.data(), *patEnd = pattern.data() + pattern.size() - 1;
				matchBegin = &pattern[i - 1]; matchEnd = &pattern[i + 1];
				while ((matchBegin != (patBegin - 1)) && ('0' <= *matchBegin) && (*matchBegin <= '9')) {
					--matchBegin; ++count1;
				}
				while ((matchEnd != (patEnd + 1)) && ('0' <= *matchEnd) && (*matchEnd <= '9')) {
					++matchEnd; ++count2;
				}
				a = atoi((pattern.substr(i - count1, count1)).c_str());
				b = atoi((pattern.substr(i + 1, count2)).c_str());
				pattern.erase(i - count1, count1 + count2 + 1);
				if (sign == 0) { pattern.insert(i - count1, std::to_string(abs(a + b))); sign = 0; }
				else if (sign == 1) { pattern.insert(i - count1, std::to_string(abs(b - a))); if ((b - a) < 0) sign = 1; else sign = 0; }
				i -= (count1 + 1); count1 = count2 = 0;
				patBegin = patEnd = nullptr;
			}
			else if (pattern[i] == '-')
			{
				const char *patBegin = pattern.data(), *patEnd = pattern.data() + pattern.size() - 1;
				matchBegin = &pattern[i - 1]; matchEnd = &pattern[i + 1];
				while ((matchBegin != (patBegin - 1)) && ('0' <= *matchBegin) && (*matchBegin <= '9')) {
					--matchBegin; ++count1;
				}
				while ((matchEnd != (patEnd + 1)) && ('0' <= *matchEnd) && (*matchEnd <= '9')) {
					++matchEnd; ++count2;
				}
				a = atoi((pattern.substr(i - count1, count1)).c_str());
				b = atoi((pattern.substr(i + 1, count2)).c_str());
				pattern.erase(i - count1, count1 + count2 + 1);
				if (sign == 0) { pattern.insert(i - count1, std::to_string(abs(a - b))); if ((a - b) < 0) sign = 1; else sign = 0; }
				else if (sign == 1) { pattern.insert(i - count1, std::to_string(abs(a + b))); sign = 1; }
				i -= (count1 + 1); count1 = count2 = 0;
				patBegin = patEnd = nullptr;
			}
		}
		PrintNumber(pattern);
	}
};

int main()
{
	std::string pattern; std::cin >> pattern;
	Solution Siqi; Siqi.Calculate(pattern);

	system("pause");
	return 0;
}
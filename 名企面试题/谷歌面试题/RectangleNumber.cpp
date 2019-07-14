// RectangleNumber.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <ctime>

struct pos
{
	size_t x;
	size_t y;
};

int* generatorArray(const int& nRow, const int& nCol)
{
	int* array = new int[nRow * nCol];
	std::cout << "系统随机生成" << nRow << "*" << nCol << "的01矩阵\n";
	srand(std::time(0));
	for (int i = 0; i < nRow; ++i)
		for (int j = 0; j < nCol; ++j)
			array[j + i * nCol] = rand() % 2;
	return array;
}

void Combination(const int* array, const int& number, int& row, const int* const rowEndAddress, struct pos* pairIndex)
{
	
	if (number == 0)
	{
		// 输出
		return;
	}
	if (array == rowEndAddress) return;
	if (*array != 1) return; else 

	Combination(array + 1, number - 1, pairIndex);
	result.pop_back();
	Combination(array + 1, number, pairIndex);
}

const int numRectangle(const int* array, const int& nRow, const int& nCol)
{
	static int row = 0;
	const int number = 2;
	struct pos* pairIndex;
	const int * rowEndAddress = &array[(row + 1)*nCol - 1];
	Combination(&array[row * nCol], number, row, rowEndAddress, pairIndex);
	++row;
}

int main()
{
	int* array;
	int numbers, nRow, nCol;

	std::cout << "输入矩形的行列数：(格式：row空格col 或者 row回车col)\n";
	std::cin >> nRow >> nCol;

	array = generatorArray(nRow, nCol);
	numbers = numRectangle(array, nRow, nCol);

	std::cout << "能构成的矩形总数是: " << numbers << "\n";

	system("pause");

	return 0;
}


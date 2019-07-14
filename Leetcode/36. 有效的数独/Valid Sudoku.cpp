// Valid Sudoku.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int row[9][9] = { 0 }, col[9][9] = { 0 }, box[9][9] = { 0 };
		for (int i = 0; i != board.size(); ++i)
			for (int j = 0; j != board[i].size(); ++j)
				if (board[i][j] != '.')
				{
					int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
					if (row[i][num] || col[j][num] || box[k][num])
						return false;
					row[i][num] = col[j][num] = box[k][num] = 1;
				}
		return true;
	}
};

int main()
{
	vector<vector<char>> sudu{ 
	{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
	{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
	{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
	{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
	{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
	{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
	Solution siqi;
	cout << (siqi.isValidSudoku(sudu) ? "true" : "false");
	system("pause");
    return 0;
}


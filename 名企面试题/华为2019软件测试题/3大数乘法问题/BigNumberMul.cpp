// BigNumberMul.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

class Solution
{
private:
	int SymA, SymB; // A,B的符号
public:
	
	bool CheckInvalid(std::string& A, std::string& B)
	{
		std::string::iterator itA = A.begin();
		std::string::iterator itB = B.begin();
		if ((*itA > '9' || *itA < '0') && (*itA != '+' && *itA != '-')) return true;
		if ((*itB > '9' || *itB < '0') && (*itB != '+' && *itB != '-')) return true;
		for (++itA; itA < A.end(); ++itA) if (*itA > '9' || *itA < '0') return true;
		for (++itB; itB < B.end(); ++itB) if (*itB > '9' || *itB < '0') return true;
		return false;
	}

	void signJudge(std::string& A, std::string& B)
	{
		if (A[0] == '-') { SymA = 1; A.erase(0, 1); }
		else if (A[0] == '+') { SymA = 0; A.erase(0, 1); }
		else SymA = 0;
		if (B[0] == '-') { SymB = 1; B.erase(0, 1); }
		else if (B[0] == '+') { SymB = 0; B.erase(0, 1); }
		else SymB = 0;
	}

	void Multiply(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& c)
	{
		int tmp, k;
		for (int i = 0; i < a.size(); ++i) { k = i; for (int j = 0; j < b.size(); ++j) c[k++] += a[i] * b[j]; }
		for (k = c.size() - 1; k >= 0; --k)
		{
			if (c[k] > 9)
			{
				if (k != 0) { c[k - 1] += c[k] / 10; c[k] %= 10; }
				else { tmp = c[k] / 10; c[k] %= 10; c.insert(c.begin(), tmp); }
			}
		}
	}

	void BigNumberMul(std::string& A, std::string& B)
	{
		std::vector<int> a; std::vector<int> b;
		a.reserve(A.size()); b.reserve(B.size());
		for (int i = 0; i < A.size(); ++i) a.push_back(A[i] - '0');
		for (int i = 0; i < B.size(); ++i) b.push_back(B[i] - '0');
		std::vector<int> c(a.size() + b.size() - 1, 0);

		Multiply(a, b, c);

		std::string C; for (int i = 0; i < c.size(); ++i) C.push_back(c[i] + '0');
		if ((SymA ^ SymB) == 1) C.insert(0, "-");
		std::cout << C;
	}
};

int main()
{
	std::string A, B;
	Solution Siqi;

	std::cin >> A >> B;
	if (Siqi.CheckInvalid(A, B)) { std::cout << "输入乘数无效！！！\n"; return 0; }
	Siqi.signJudge(A, B);
	Siqi.BigNumberMul(A, B);

	system("pause");
    return 0;
}
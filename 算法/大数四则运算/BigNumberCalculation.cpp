// BigNumberMul.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <fstream>

class Solution
{
private:
	int pos;  //小数点的位置
	int SymA, SymB, Sign, tmp; // A,B的符号,以及运算之后的符号
	std::vector<int> a, b, c, tmpC;
public:

	int compare(std::vector<int>& x, std::vector<int>& y)
	{
		if (x.size() > y.size()) return 1;
		if (x.size() < y.size()) return -1;
		if (x.size() == y.size())
		{
			for (int i = 0; i != x.size(); ++i) { if (x[i] > y[i]) return 1; else if (x[i] < y[i]) return -1; }
			return 0;
		}
	}

	bool CheckInvalid(std::string& A, std::string& B)
	{
		std::string::iterator itA = A.begin(); std::string::iterator itB = B.begin();
		if ((*itA > '9' || *itA < '0') && (*itA != '+' && *itA != '-')) return true;
		if ((*itB > '9' || *itB < '0') && (*itB != '+' && *itB != '-')) return true;
		for (++itA; itA != A.end(); ++itA) if (*itA > '9' || *itA < '0') return true;
		for (++itB; itB != B.end(); ++itB) if (*itB > '9' || *itB < '0') return true;
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

	void OperationInit(const std::string& A, const std::string& B)
	{
		a.reserve(A.size()); b.reserve(B.size());
		for (int i = 0; i != A.size(); ++i) a.push_back(A[i] - '0');
		for (int i = 0; i != B.size(); ++i) b.push_back(B[i] - '0');
	}

	void Plus(std::vector<int> a, std::vector<int> b)
	{
		c.insert(c.begin(), (a.size() > b.size()) ? a.size() : b.size(), 0);
		if (a.size() > b.size()) b.insert(b.begin(), c.size() - b.size(), 0);
		else if (a.size() < b.size()) a.insert(a.begin(), c.size() - a.size(), 0);
		for (int i = 0; i != c.size(); ++i) c[i] = a[i] + b[i];
		for (int i = c.size() - 1; i >= 0; --i)
		{
			if (c[i] > 9)
			{
				if (i != 0) { c[i - 1] += c[i] / 10; c[i] %= 10; }
				else { tmp = c[i] / 10; c[i] %= 10; c.insert(c.begin(), tmp); }
			}
		}
	}

	void Sub(std::vector<int> a, std::vector<int> b)
	{
		int aMoreThanb = 0;
		c.insert(c.begin(), (a.size() > b.size()) ? a.size() : b.size(), 0);
		if (a.size() > b.size()) b.insert(b.begin(), c.size() - b.size(), 0);
		else if (a.size() < b.size()) a.insert(a.begin(), c.size() - a.size(), 0);
		for (int i = 0; i != c.size(); ++i)
		{
			if (a[i] < b[i]) { aMoreThanb = -1; break; }
			else if (a[i] > b[i]) { aMoreThanb = 1; break; }
		}
		if (aMoreThanb == 0) { Sign = 0; c.erase(c.begin(), c.end() - 1); return; }
		if (aMoreThanb == 1) for (int i = 0; i != c.size(); ++i) { c[i] = a[i] - b[i]; Sign = 0; }
		if (aMoreThanb == -1) for (int i = 0; i != c.size(); ++i) { c[i] = b[i] - a[i]; Sign = 1; }
		for (int i = c.size() - 1; i > 0; --i) if (c[i] < 0) { c[i - 1] -= 1; c[i] += 10; }
		int c_size = c.size(); for (int i = 0; i != c_size; ++i) if (c[0] == 0) c.erase(c.begin()); else break;
	}

	void Multiply(std::vector<int> a, std::vector<int> b)
	{
		int k;
		c.insert(c.begin(), a.size() + b.size() - 1, 0);
		for (int i = 0; i != a.size(); ++i) { k = i; for (int j = 0; j != b.size(); ++j) c[k++] += a[i] * b[j]; }
		for (k = c.size() - 1; k >= 0; --k)
		{
			if (c[k] > 9)
			{
				if (k != 0) { c[k - 1] += c[k] / 10; c[k] %= 10; }
				else { tmp = c[k] / 10; c[k] %= 10; c.insert(c.begin(), tmp); }
			}
		}
		for (int i = 0; i != c.size(); ++i) if (c[0] == 0) c.erase(c.begin()); else break;
	}

	std::vector<int> Div2(std::vector<int> factorMul1, std::vector<int> factorMul2)
	{
		c.clear(); Plus(factorMul1, factorMul2);
		std::vector<int> factorMul; factorMul = c; c.clear();
		for (int i = 0; i != factorMul.size() - 1; ++i)
		{
			factorMul[i + 1] += (factorMul[i] % 2) * 10;
			factorMul[i] /= 2;
		}
		factorMul[factorMul.size() - 1] /= 2;
		int factorMul_size = factorMul.size();
		for (int i = 0; i != factorMul_size; ++i) if (factorMul[0] == 0) factorMul.erase(factorMul.begin()); else break;
		return factorMul;
	}

	void DivCore(const int& precision)
	{
		//计算小数部分
		int count = precision;
		std::vector<int> rangeAverage, rangeLeft(1, 1), rangeRight(1, 9), resultMul;
		for (int i = 1; i <= count; ++i)
		{
			a.push_back(0); c.clear(); Multiply(b, rangeLeft);
			if (compare(a, c) < 0){ tmpC.push_back(0); continue; }
			if (compare(a, c) == 0){ tmpC.push_back(1); tmpC.insert(tmpC.end(), count - i, 0); return; }
			if (compare(a, c) > 0)
			{
				for (;;)
				{
					c.clear(); Sub(rangeRight, rangeLeft);
					if ((c.size() == 1) && c[0] == 1)
					{
						c.clear(); Multiply(b, rangeRight);
						if (compare(a, c) > 0)
						{
							tmpC.push_back(rangeRight[0]); c.clear(); Multiply(rangeRight, b);
							resultMul = c; c.clear(); Sub(a, resultMul); a.clear(); a = c; c.clear(); break;
						}
						if (compare(a, c) < 0)
						{
							tmpC.push_back(rangeLeft[0]); c.clear(); Multiply(rangeLeft, b);
							resultMul = c; c.clear(); Sub(a, resultMul); a.clear(); a = c; c.clear(); break;
						}
					}
					// 二分查找
					rangeAverage = Div2(rangeLeft, rangeRight);
					Multiply(b, rangeAverage);
					if (compare(a, c) == 0)
					{ tmpC.push_back(rangeAverage[0]); tmpC.insert(tmpC.end(), count - i, 0); return; }
					if (compare(a, c) < 0) { rangeRight.clear(); rangeRight = rangeAverage; rangeAverage.clear(); }
					if (compare(a, c) > 0) { rangeLeft.clear(); rangeLeft = rangeAverage; rangeAverage.clear(); }
				}
			}
		}
	}

	void Division(const int& precision)
	{
		//先计算整数部分
		std::vector<int> factorMul, factorMul1(1, 1), factorMul2(1, 1);
		Multiply(b, factorMul1);
		if (compare(a, c) < 0)
		{
			pos = 1; tmpC.push_back(0); DivCore(precision);
			a.clear(); b.clear(); c.clear(); c = tmpC;
			return;
		}
		if (compare(a, c) == 0)
		{
			pos = 1; tmpC.push_back(1);
			a.clear(); b.clear(); c.clear(); c = tmpC;
			c.insert(c.begin() + pos, precision, 0);
			return;
		}
		// compare(a, c) > 0
		for (;;)
		{
			factorMul2.erase(factorMul2.begin());
			factorMul2.insert(factorMul2.begin(), 0);
			factorMul2.insert(factorMul2.begin(), 1);
			c.clear(); Multiply(b, factorMul2);
			if (compare(a, c) > 0) { factorMul1.clear(); factorMul1 = factorMul2; continue; }
			if (compare(a, c) == 0)
			{
				pos = factorMul2.size(); tmpC = factorMul2;
				a.clear(); b.clear(); c.clear(); c = tmpC;
				c.insert(c.begin() + pos, precision, 0);
				return;
			}
			if (compare(a, c) < 0)
			{
				for (;;)
				{
					c.clear(); Sub(factorMul2, factorMul1);
					if ((c.size() == 1) && c[0] == 1)
					{
						c.clear();
						Multiply(b, factorMul2);
						if (compare(a, c) > 0) { pos = factorMul2.size(); tmpC = factorMul2; }
						if (compare(a, c) < 0) { pos = factorMul1.size(); tmpC = factorMul1; }
						c.clear(); break;
					}
					// 二分查找
					factorMul = Div2(factorMul1, factorMul2);
					Multiply(b, factorMul);
					if (compare(a, c) == 0)
					{
						pos = factorMul.size(); tmpC = factorMul;
						a.clear(); b.clear(); c.clear(); c = tmpC;
						c.insert(c.begin() + pos, precision, 0);
						return;
					}
					if (compare(a, c) < 0) { factorMul2.clear(); factorMul2 = factorMul; factorMul.clear(); }
					if (compare(a, c) > 0) { factorMul1.clear(); factorMul1 = factorMul; factorMul.clear(); }
				}
				// 扣去整数部分求剩下的a
				std::vector<int> tmpMul; Multiply(tmpC, b); tmpMul = c; c.clear();
				Sub(a, tmpMul); a.clear(); a = c; 
				DivCore(precision);
				a.clear(); b.clear(); c.clear(); c = tmpC;
				return;
			}
		}
	}

	const std::string BigNumberPlus(const std::string& A, const std::string& B)
	{
		std::string C;
		OperationInit(A, B);
		if (SymA == 0 && SymB == 0) { Plus(a, b); Sign = 0; }
		if (SymA == 1 && SymB == 1) { Plus(a, b); Sign = 1; }
		if (SymA == 0 && SymB == 1) Sub(a, b);
		if (SymA == 1 && SymB == 0) Sub(b, a);
		for (int i = 0; i != c.size(); ++i) C.push_back(c[i] + '0');
		if (Sign == 1) C.insert(0, "-"); a.clear(); b.clear(); c.clear();
		return C;
	}

	const std::string BigNumberSub(const std::string& A, const std::string& B)
	{
		std::string C;
		OperationInit(A, B);
		if (SymA == 0 && SymB == 1) { Plus(a, b); Sign = 0; }
		if (SymA == 1 && SymB == 0) { Plus(a, b); Sign = 1; }
		if (SymA == 0 && SymB == 0) Sub(a, b);
		if (SymA == 1 && SymB == 1) Sub(b, a);
		for (int i = 0; i != c.size(); ++i) C.push_back(c[i] + '0');
		if (Sign == 1) C.insert(0, "-"); a.clear(); b.clear(); c.clear();
		return C;
	}

	const std::string BigNumberMul(const std::string& A, const std::string& B)
	{
		std::string C;
		OperationInit(A, B);
		Multiply(a, b);
		if ((SymA ^ SymB) == 1) Sign = 1; else Sign = 0;
		for (int i = 0; i != c.size(); ++i) C.push_back(c[i] + '0');
		if (Sign == 1) C.insert(0, "-"); a.clear(); b.clear(); c.clear();
		return C;
	}

	const std::string BigNumberDiv(const std::string& A, const std::string& B, const int& precision)
	{
		std::string C;
		OperationInit(A, B);
		Division(precision);
		if ((SymA ^ SymB) == 1) Sign = 1; else Sign = 0;
		for (int i = 0; i != c.size(); ++i) C.push_back(c[i] + '0');
		C.insert(pos, "."); if (Sign == 1) C.insert(0, "-");
		a.clear(); b.clear(); c.clear();
		return C;
	}
};

int main()
{
	std::string A, B;
	Solution Siqi;

	std::cin >> A >> B;
	if (Siqi.CheckInvalid(A, B)) throw new std::exception("输入乘数无效！！！");
	Siqi.signJudge(A, B);

	std::cout << "A + B = " << Siqi.BigNumberPlus(A, B) << std::endl;

	std::cout << "A - B = " << Siqi.BigNumberSub(A, B) << std::endl;

	std::cout << "A * B = " << Siqi.BigNumberMul(A, B) << std::endl;

	std::cout << "A / B = " << Siqi.BigNumberDiv(A, B, 20) << std::endl;

	system("pause");
	return 0;
}
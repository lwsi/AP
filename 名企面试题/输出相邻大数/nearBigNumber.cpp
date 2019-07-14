// nearBigNumber.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

template <typename T> inline void Swap(T& a, T& b) { a ^= b ^= a ^= b; }

void Solution(char* str)
{
	if (str == nullptr) { cout << "None!"; return; }

	bool flag = false;
	int len = strlen(str);
	char* p1 = &str[len - 1]; char* p2 = &str[len - 1];

	for (int i = 1; i < len; ++i)
	{
		--p1;
		while ((p2 - p1) > 0)
		{
			if (*p1 < *p2) { Swap(*p1, *p2); flag = true; break; }
			--p2;
		}
		if (flag == true) break;
		p2 = &str[len - 1];
	}

	if (flag == true)
	{
		int i = 0; while (&str[i] <= p1) { cout << str[i]; ++i; }
		i = len - 1; while (&str[i] > p1) { cout << str[i]; --i; }
	}
	else cout << "None!";
}

/* -------------------功能测试--------------------*/
void Test(char* testName, char* str, char* expect)
{
	cout << testName << ": " << endl;
	if (str == nullptr)
		cout << "Origin: None!\tExpect: None!" << endl;
	else
	{
		cout << "Origin: " << str << "\tExpect: ";
		if (expect == nullptr) cout << "None!" << endl;
		else cout << expect << endl;
	}
	cout << "Output: "; Solution(str); cout << endl;
}

// 有大数1
void Test1() { char str[] = "12345"; Test("Test1", str, "12354"); }

// 有大数2
void Test2() { char str[] = "12453"; Test("Test2", str, "12534"); }

// 有大数3
void Test3() { char str[] = "12543"; Test("Test3", str, "13245"); }

// 有大数4
void Test4() { char str[] = "5998877665544332211"; Test("Test4", str, "6112233445556778899"); }

// 没有大数1
void Test5() { char str[] = "54321"; Test("Test5", str, nullptr); }

// 没有大数2
void Test6() { char str[] = "11"; Test("Test6", str, nullptr); }

// 数是一位
void Test7() { char str[] = "1"; Test("Test7", str, nullptr); }

// 输入为空指针
void Test8() { Test("Test8", nullptr, nullptr); }

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();

	system("pause");

	return 0;
}
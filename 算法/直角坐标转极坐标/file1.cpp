// first_test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "fc.h"

using namespace std;

int main()
{
	rect rplace;
	polar pplace;

	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers (q to quit): ";
	}
	cout << "Bye!\n";
 
	system("pause");
	return 0;
}

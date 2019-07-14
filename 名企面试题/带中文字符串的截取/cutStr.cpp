#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	inline bool is_zh_ch(const char& p) { return ((~(p >> 8) == 0) ? 1 : 0); }
	string strByte(const string& str, const int& n)
	{
		string s;
		for (int count = 0, i = 0; i != str.size() && count < n; ++i)
		{
			if (str[i] <= '9' && str[i] >= '0') continue;
			if (is_zh_ch(str[i])) { count += 2; s.push_back(str[i]); s.push_back(str[i + 1]); }
			else { count += 1; s.push_back(str[i]); }
		}
		return s;
	}
};

int main()
{
	cout.imbue(locale("chs"));
	string str = "ae12°®Äã";
	string s; Solution siqi;
	s = siqi.strByte(str, 3);
	cout << s << "\n";
	system("pause");
	return 0;
}
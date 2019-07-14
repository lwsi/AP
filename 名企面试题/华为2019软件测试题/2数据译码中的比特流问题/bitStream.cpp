#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <string>

void decodeConvert(std::string& bitStr, const int& decodeNum, const int* bitLen, int* decodeArray)
{
	for (int i = 0; i < decodeNum; ++i)
	{
		for (int j = 0; j < bitLen[i]; ++j)
		{
			decodeArray[i] += ((int)(bitStr[0] - '0') << (bitLen[i] - j - 1));
			bitStr.erase(0, 1);
		}
	}
}

void decodeCore(const int& dataLen, const int* data16, const int& decodeNum, const int* bitLen, int* decodeArray)
{
	std::string bitStr, bitTmp;
	for (int i = 0; i < dataLen; ++i)
	{
		std::bitset<8> bit16(data16[i]);
		bitStr.append(bit16.to_string());
	}
	decodeConvert(bitStr, decodeNum, bitLen, decodeArray);
}

int main()
{
	int dataLen, decodeNum;
	std::cin >> dataLen; int* data16 = new int[dataLen];
	for (int i = 0; i < dataLen; ++i) std::cin >> std::hex >> data16[i]; //oct八进制 hex十六进制 dec十进制
	std::cin >> decodeNum; int* bitLen = new int[decodeNum];
	for (int i = 0; i < decodeNum; ++i) std::cin >> bitLen[i];
	int* decodeArray = new int[decodeNum]();
	decodeCore(dataLen, data16, decodeNum, bitLen, decodeArray);
	for (int i = 0; i < decodeNum; ++i) std::cout << decodeArray[i] << " ";

	system("pause");
	return 0;
}

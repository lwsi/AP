#include <iostream>

using namespace std;

#define MAX 1000

typedef struct{
    char NumStr[MAX];
    int ChainLength;
} NumChainType;

int main()
{
    int i, j, k = 0, index = 0, count1 = 0, count2 = 0, count3 = 0, MaxLen = 0, MaxNum = 0;
    char str[MAX];
    NumChainType NumChain[MAX];
    //获取字符串
    cin >> str;

    for(i = 0; i < MAX; i++)
    {
        NumChain[i].ChainLength = 0;
        for(j = 0; j < MAX; j++)
            NumChain[i].NumStr[j] = '\0';
    }

    for(i = 0; str[i] != '\0'; i++)
    {
        while(str[i] >= '0' && str[i] <= '9')
        {
            count1++;
            i++;
            count3 = 1;
        }
        if(count1 != 0)
        {
            NumChain[k].ChainLength = count1;
            for(j = i-count1; j < i; j++)
                NumChain[k].NumStr[index++] = str[j];
            k++;
        }
        index = count1 = 0;
    }

    if(count3 == 0)
    {
        cout << "";
        return 0;
    }

    //确定数字串的总个数
    for(i = 0; i < MAX; i++)
    {
        if(NumChain[i].ChainLength != 0)
            count2++;
        else
            break;
    }

    for(i = 0; i < count2; i++)
        if(MaxLen < NumChain[i].ChainLength)
            MaxLen = NumChain[i].ChainLength;
    for(j = 0; j < count2; j++)
        if(NumChain[j].ChainLength == MaxLen)
                MaxNum++;
    for(i = count2-1; i >= 0; i--)
        if(NumChain[i].ChainLength == MaxLen)
        {
            if(MaxNum > 1)
            {
                for(j = 0; j < MaxLen; j++)
                    cout << NumChain[i].NumStr[j];
                cout << endl;
                cout << MaxLen;
                break;
            }
            else
            {
                cout << MaxLen;
                break;
            }
        }

    return 0;
}

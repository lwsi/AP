#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findUnlockKey(long lockingKey, int flag)
{
    int ptr1[5], *ptr2;
    int i, j, k = 0;
    int tmp;
    //提取每一位数字到ptr1
    do
    {
        ptr1[k++] =lockingKey % 10;
        lockingKey = lockingKey / 10;
    }
    while(lockingKey > 0);

    //构造等长数组
    ptr2 = (int* )calloc(k, sizeof(int));

    for(i = 0; i < k; i++)
        ptr2[i] = ptr1[i];

    //乾坤大挪移
    for(i = 0; i < k-1; i++)
    {
        for(j = i+1; j < k; j++)
        {
            if(ptr2[j] < ptr2[i])
            {
                tmp = ptr2[j];
                ptr2[j] = ptr2[i];
                ptr2[i] = tmp;
            }
        }
    }

    //移花接木
    if(ptr2[0] == 0)
        for(i = 1; i < k; i++)
        {
            if(ptr2[i] > 0)
            {
                ptr2[0] = ptr2[i];
                ptr2[i] = 0;
                break;
            }
        }

    if(flag == 0)
    {
        for(i = 0; i < k; i++)
            printf("%d", ptr2[i]);

    }
    else
    {
        printf("-");
        for(i = 0; i < k; i++)
            printf("%d", ptr2[i]);
    }
    printf("\n");
}

int main()
{
    long lockingKey;
    int flag;
    printf("输入一个锁定密钥整数（-1e5≤lockingKey≤1e5） \n");
    scanf("%ld", &lockingKey);

    if(lockingKey > 0)
        flag = 0;
    else
        flag = 1;

    findUnlockKey(abs(lockingKey), flag);

    return 0;
}


/******************************************************************
 * Program:  基数排序
 * State:    排序方式可选 1-从小到大 2-从大到小
 * Date:     2017/10/15
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void RadixSort(int *ptr, int length, int choose);
int MaxBits(int *ptr, int length);
int FindPos(int i, int number);

int main()
{
    int i, num, choose;
    int *ptr;

    printf("--------------基数排序----------------\n\n");
    printf("输入想要随机生成的整数个数： ");
    scanf(" %d", &num);

    //动态内存分配
    ptr = (int* )calloc(num, sizeof(int));

    //生成随机数序列
    srand(time(NULL));
    for(i = 0; i < num; i++)
    {
        ptr[i] = rand() % 100 + 1;
    }

    printf("\n排序前的数组: \n");
    for(i = 0; i < num; i++)
    {
        printf("%d\t", ptr[i]);
    }
    printf("\n\n");

    printf("排序方式选择：1-从小到大  2-从大到小\n");
    scanf(" %d", &choose);
    printf("\n");

    //基数排序
    printf("基数排序中...\n\n");

    printf("基数排序完成！\n\n");

    RadixSort(ptr, num, choose);

    printf("\n");
    printf("排序后的数组: \n");
    for(i = 0; i < num; i++)
    {
        printf("%d\t", ptr[i]);
    }
    printf("\n");

    printf("结束！\n");
    system("pause");

    return 0;
}

void RadixSort(int *ptr, int length, int choose)
{
    int i = 0, j = 0, k = 0, count;
    int Bit = MaxBits(ptr, length);
    int *Temp = (int *) calloc(length, sizeof(int));

    for(i = 0; i < length; ++i)
        Temp[i] = ptr[i];

    switch(choose)
    {
    case 1:
        for(count = 1; count <= Bit; ++count)
        {
            for(i = 0; i < 10; ++i)
            {
                for(j = 0; j < length; ++j)
                {
                    if(FindPos(count, ptr[j]) == i)
                        Temp[k++] = ptr[j];
                }
            }
            for(i = 0; i < length; ++i)
                ptr[i] = Temp[i];
            k = 0;
        }
        break;
    case 2:
        for(count = 1; count <= Bit; ++count)
        {
            for(i = 9; i >= 0; --i)
            {
                for(j = 0; j < length; ++j)
                {
                    if(FindPos(count, ptr[j]) == i)
                        Temp[k++] = ptr[j];
                }
            }
            for(i = 0; i < length; ++i)
                ptr[i] = Temp[i];
            k = 0;
        }
        break;
    }
}

int MaxBits(int *ptr, int length)
{
    int Bits = 0;
    // 计算数组ptr的最大值MAX
    int i, MAX = ptr[0];
    for (i = 1; i < length; ++i)
        if (MAX < ptr[i])
            MAX = ptr[i];
    // 计算最大值的位数
    while (MAX > 0)
    {
        MAX = MAX / 10;
        ++Bits;
    }
    return Bits;
}

int FindPos(int i, int number)
{
    int value = 0;
    value = (number / (int) pow(10,(i-1))) % 10;
    return value;
}



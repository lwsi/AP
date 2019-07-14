/******************************************************************
 * Program:  快速排序
 * State:    排序方式可选 1-从小到大 2-从大到小
 * Date:     2017/10/2
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int *ptr, int begin, int end, int choose);
void swap(int *a, int *b);

int main()
{
    int i, num, choose;
    int *ptr;

    printf("--------------快速排序----------------\n\n");
    printf("输入想要随机生成的整数个数： ");
    scanf(" %d", &num);

    //动态内存分配
    ptr = (int* )calloc(num, sizeof(int));

    //生成随机数序列
    srand(time(NULL));
    for(i = 0; i < num; i++)
    {
        ptr[i] = rand() % 50 + 1;
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

    //快速排序
    printf("快速排序中...\n\n");

    printf("快速排序完成！\n\n");

    QuickSort(ptr, 0, num-1, choose);

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
void QuickSort(int *ptr, int begin, int end, int choose)
{
    int i, j;

    switch(choose)
    {
    case 1:
        if(begin < end)
        {
            i = begin + 1;
            j = end;
            while(i < j)
            {
                if(ptr[i] > ptr[begin])
                {
                    swap(&ptr[i], &ptr[j]);
                    j--;
                }
                else
                    i++;
            }
            if(ptr[i] >= ptr[begin])
                i--;
            swap(&ptr[i], &ptr[begin]);
            QuickSort(ptr, begin, i, choose);
            QuickSort(ptr, j, end, choose);
        }

        break;

    case 2:
        if(begin < end)
        {
            i = begin + 1;
            j = end;
            while(i < j)
            {
                if(ptr[i] < ptr[begin])
                {
                    swap(&ptr[i], &ptr[j]);
                    j--;
                }
                else
                    i++;
            }
            if(ptr[i] <= ptr[begin])
                i--;
            swap(&ptr[i], &ptr[begin]);
            QuickSort(ptr, begin, i, choose);
            QuickSort(ptr, j, end, choose);
        }

        break;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


/******************************************************************
 * Program:  堆排序
 * State:    排序方式可选 1-从小到大 2-从大到小
 * Date:     2017/10/2
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void HeapAdjust(int *ptr, int i, int length, int choose);
void HeapSort(int *ptr, int length, int choose);
void swap(int *a, int *b);

int main()
{
    int i, num, choose;
    int *ptr;

    printf("--------------堆排序----------------\n\n");
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
    printf("堆排序中...\n\n");

    printf("堆排序完成！\n\n");

    HeapSort(ptr, num, choose);

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

void HeapAdjust(int *ptr, int i, int length, int choose)
{
    int nChild;
    switch(choose)
    {
    case 1:
        for(; (i<<1)+1 < length; i = nChild)
        {
            nChild = (i<<1)+1;
            if(nChild < length-1 && ptr[nChild+1] > ptr[nChild])
            {
                ++nChild;
            }
            if(ptr[i] < ptr[nChild])
                swap(&ptr[i], &ptr[nChild]);
            else
                break;
        }
        break;

    case 2:
        for(; (i<<1)+1 < length; i = nChild)
        {
            nChild = (i<<1)+1;
            if(nChild < length-1 && ptr[nChild+1] < ptr[nChild])
            {
                ++nChild;
            }
            if(ptr[i] > ptr[nChild])
                swap(&ptr[i], &ptr[nChild]);
            else
                break;
        }
        break;

    }
}

void HeapSort(int *ptr, int length, int choose)
{
    int i;
    for(i = length/2-1; i >= 0; i--)
        HeapAdjust(ptr, i, length, choose);
    for(i = length-1; i >0; i--)
    {
        swap(&ptr[0], &ptr[i]);
        HeapAdjust(ptr, 0, i, choose);
    }
}

void swap(int *a, int *b)
{
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
}


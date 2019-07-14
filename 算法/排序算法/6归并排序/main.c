/******************************************************************
 * Program:  归并排序
 * State:    排序方式可选 1-从小到大 2-从大到小
 * Date:     2017/10/2
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void MergeSort(int *ptr, int length, int begin, int end, int choose);
void Merge(int *ptr, int length, int low, int mid, int high, int choose);

int main()
{
    int i, num, choose;
    int *ptr;

    printf("--------------归并排序----------------\n\n");
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

    //归并排序
    printf("归并排序中...\n\n");

    printf("归并排序完成！\n\n");

    MergeSort(ptr, num, 0, num-1, choose);

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


void Merge(int *ptr, int length, int low, int mid, int high, int choose)
{
    int i = low, j = mid+1, k = low;
    int *temp;
    temp = (int *)calloc(length, sizeof(int));
    switch(choose)
    {
    case 1:
        while(i <= mid && j <= high)
            if(ptr[i] < ptr[j])
                temp[k++] = ptr[i++];
            else
                temp[k++] = ptr[j++];
        while(i <= mid)
            temp[k++] = ptr[i++];
        while (j <= high)
            temp[k++] = ptr[j++];
        for (i = low; i <= high; i++)
            ptr[i] = temp[i];

        break;
    case 2:
        while(i <= mid && j <= high)
            if(ptr[i] > ptr[j])
                temp[k++] = ptr[i++];
            else
                temp[k++] = ptr[j++];
        while(i <= mid)
            temp[k++] = ptr[i++];
        while (j <= high)
            temp[k++] = ptr[j++];
        for (i = low; i <= high; i++)
            ptr[i] = temp[i];

        break;
    }
}

void MergeSort(int *ptr, int length, int begin, int end, int choose)
{
    if(begin < end)
    {
        int mid = (begin+end)/2;
        MergeSort(ptr, length, begin, mid, choose);
        MergeSort(ptr, length, mid+1, end, choose);
        Merge(ptr, length, begin, mid, end, choose);
    }
}

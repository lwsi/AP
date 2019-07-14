/******************************************************************
 * Program:  男女
 * State:    排序方式可选 1-从小到大 2-从大到小
 * Date:     2017/8/8
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SelectSort(int *ptr, int N, int choose);

int main()
{
    int i, num, choose;
    int *ptr;

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

    //选择排序
    printf("选择排序中...\n\n");

    printf("选择排序完成！\n\n");

    SelectSort(ptr, num, choose);

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

void SelectSort(int *ptr, int N, int choose)
{
    int i, j, k, tmp;

    switch(choose)
    {
    case 1:
        for(i = 0; i < N-1; i++)
        {
            for(j = i+1; j < N; j++)
                if(ptr[j] < ptr[i])
                {
                    tmp = ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = tmp;
                }
            printf("第%d步排序结果： ", i+1);
            for(k = 0; k < N; k++)
                printf("%d\t", ptr[k]);
            printf("\n");
        }
        break;
    case 2:
          for(i = 0; i < N-1; i++)
        {
            for(j = i+1; j < N; j++)
                if(ptr[j] > ptr[i])
                {
                    tmp = ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = tmp;
                }
            printf("第%d步排序结果： ", i+1);
            for(k = 0; k < N; k++)
                printf("%d\t", ptr[k]);
            printf("\n");
        }
        break;
    }

}

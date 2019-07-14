/******************************************************************
 * Program:  冒泡排序算法
 * State:    排序方式可选 1-从小到大 2-从大到小
 * Date:     2017/8/8
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *ptr, int N, int choose);

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

    //冒泡排序
    printf("冒泡排序中...\n\n");

    printf("冒泡排序完成！\n\n");

    BubbleSort(ptr, num, choose);

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

void BubbleSort(int *ptr, int N, int choose)
{
    int i, j, k, temp, flag = 0;

    for(i = 0; i < N-1; i++)
    {
        flag = 0;
        //判断排序是否完成，并提前中止后续排序过程
        switch(choose)
        {
        case 1:
            for(j = 0; j < N-1; j++)
            {
                if(ptr[j] > ptr[j+1])
                {
                    flag = 1;
                    break;
                }
            }
            break;
        case 2:
            for(j = 0; j < N-1; j++)
            {
                if(ptr[j] < ptr[j+1])
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0)
            break;

        //排序
        for(j = N-1; j > i; j--)
        {
            switch(choose)
            {
            case 1:

                if(ptr[j-1] > ptr[j])
                {
                    temp = ptr[j-1];
                    ptr[j-1] = ptr[j];
                    ptr[j] = temp;
                }
                break;
            case 2:
                if(ptr[j-1] < ptr[j])
                {
                    temp = ptr[j-1];
                    ptr[j-1] = ptr[j];
                    ptr[j] = temp;
                }
            }
        }

        printf("第%d步排序结果：", i+1);

        for(k = 0; k < N; k++)
        {
            printf("%d\t", ptr[k]);
        }
        printf("\n");
    }
}

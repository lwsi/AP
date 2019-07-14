/******************************************************************
 * Program:  Shell 排序
 * State:    排序方式可选 1-从小到大 2-从大到小
 * Date:     2017/8/8
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ShellSort(int *ptr, int length, int choose);

int main()
{
    int i, num, choose;
    int *ptr;

    printf("--------------Shell排序----------------\n\n");
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

    //Shell排序
    printf("Shell排序中...\n\n");

    printf("Shell排序完成！\n\n");

    ShellSort(ptr, num, choose);

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

void ShellSort(int *ptr, int length, int choose)
{
    int i, j, temp, flag;


    switch(choose)
    {
    case 1:

        for(flag = length/2; flag > 0; flag /= 2)
            for(i = flag; i < length; i++)
                for(j = i-flag; j >= 0; j -= flag)
                    if(ptr[j] > ptr[j+flag])
                    {
                        temp = ptr[j];
                        ptr[j] = ptr[j+flag];
                        ptr[j+flag] = temp;
                    }
        break;

    case 2:

        for(flag = length/2; flag > 0; flag /= 2)
            for(i = flag; i < length; i++)
                for(j = i-flag; j >= 0; j -= flag)
                    if(ptr[j] < ptr[j+flag])
                    {
                        temp = ptr[j];
                        ptr[j] = ptr[j+flag];
                        ptr[j+flag] = temp;
                    }
        break;
    }

}

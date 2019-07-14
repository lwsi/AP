/******************************************************************
 * Program:  Shell ����
 * State:    ����ʽ��ѡ 1-��С���� 2-�Ӵ�С
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

    printf("--------------Shell����----------------\n\n");
    printf("������Ҫ������ɵ����������� ");
    scanf(" %d", &num);

    //��̬�ڴ����
    ptr = (int* )calloc(num, sizeof(int));

    //�������������
    srand(time(NULL));
    for(i = 0; i < num; i++)
    {
        ptr[i] = rand() % 50 + 1;
    }

    printf("\n����ǰ������: \n");
    for(i = 0; i < num; i++)
    {
        printf("%d\t", ptr[i]);
    }
    printf("\n\n");

    printf("����ʽѡ��1-��С����  2-�Ӵ�С\n");
    scanf(" %d", &choose);
    printf("\n");

    //Shell����
    printf("Shell������...\n\n");

    printf("Shell������ɣ�\n\n");

    ShellSort(ptr, num, choose);

    printf("\n");
    printf("����������: \n");
    for(i = 0; i < num; i++)
    {
        printf("%d\t", ptr[i]);
    }
    printf("\n");

    printf("������\n");
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

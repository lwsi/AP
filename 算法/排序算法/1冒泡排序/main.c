/******************************************************************
 * Program:  ð�������㷨
 * State:    ����ʽ��ѡ 1-��С���� 2-�Ӵ�С
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

    //ð������
    printf("ð��������...\n\n");

    printf("ð��������ɣ�\n\n");

    BubbleSort(ptr, num, choose);

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

void BubbleSort(int *ptr, int N, int choose)
{
    int i, j, k, temp, flag = 0;

    for(i = 0; i < N-1; i++)
    {
        flag = 0;
        //�ж������Ƿ���ɣ�����ǰ��ֹ�����������
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

        //����
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

        printf("��%d����������", i+1);

        for(k = 0; k < N; k++)
        {
            printf("%d\t", ptr[k]);
        }
        printf("\n");
    }
}

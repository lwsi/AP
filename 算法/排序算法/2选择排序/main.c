/******************************************************************
 * Program:  ��Ů
 * State:    ����ʽ��ѡ 1-��С���� 2-�Ӵ�С
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

    //ѡ������
    printf("ѡ��������...\n\n");

    printf("ѡ��������ɣ�\n\n");

    SelectSort(ptr, num, choose);

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
            printf("��%d���������� ", i+1);
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
            printf("��%d���������� ", i+1);
            for(k = 0; k < N; k++)
                printf("%d\t", ptr[k]);
            printf("\n");
        }
        break;
    }

}

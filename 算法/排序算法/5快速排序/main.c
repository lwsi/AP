/******************************************************************
 * Program:  ��������
 * State:    ����ʽ��ѡ 1-��С���� 2-�Ӵ�С
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

    printf("--------------��������----------------\n\n");
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

    //��������
    printf("����������...\n\n");

    printf("����������ɣ�\n\n");

    QuickSort(ptr, 0, num-1, choose);

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


/******************************************************************
 * Program:  ������
 * State:    ����ʽ��ѡ 1-��С���� 2-�Ӵ�С
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

    printf("--------------������----------------\n\n");
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
    printf("��������...\n\n");

    printf("��������ɣ�\n\n");

    HeapSort(ptr, num, choose);

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


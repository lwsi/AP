/******************************************************************
 * Program:  �鲢����
 * State:    ����ʽ��ѡ 1-��С���� 2-�Ӵ�С
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

    printf("--------------�鲢����----------------\n\n");
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

    //�鲢����
    printf("�鲢������...\n\n");

    printf("�鲢������ɣ�\n\n");

    MergeSort(ptr, num, 0, num-1, choose);

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

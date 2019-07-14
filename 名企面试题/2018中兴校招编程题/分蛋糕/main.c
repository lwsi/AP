
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag1 = 0;
int flag2 = 0;
int MaxMatch = 0;

//����ˮ��ѡ���б�
typedef struct
{
    int *PreferFruit;
    int count;
} FriendFruitList;

void FriendComb(int i, int deep, int rows, int columns, int numOfFriends, int *SelectFruit, FriendFruitList *Friend);
int RepeatNumberTime(int numOfFriends, int *SelectFruit, int ArraySize);

int main()
{
    int rows, columns, numOfFriends, *SelectFruit;
    int i, j, k = 0, l = 0;
    char *StrList;

    printf("rows = ");
    scanf("%d", &rows);
    printf("columns = ");
    scanf("%d", &columns);
    printf("numOfFriends = ");
    scanf("%d", &numOfFriends);

    //�������ѡ���ˮ�����
    SelectFruit = (int *)calloc(numOfFriends, sizeof(int));

    //���ǽṹ������������ַ����Ĵ洢����
    StrList = (char *)calloc(5*rows*columns*numOfFriends, sizeof(char));

    FriendFruitList Friend[numOfFriends];

    //�ṹ���ʼ��(����Ӧ���кܷ���ķ�������ʱû���뵽��������)
    for(i = 0; i < numOfFriends; i++)
    {
        Friend[i].PreferFruit = (int *)calloc(rows*columns, sizeof(int));
    }


    for(i = 0; i < numOfFriends; i++)
    {
        for(j = 0; j < rows*columns; j++)
        {
            Friend[i].PreferFruit[j] = 0;
        }

        Friend[i].count = 0;
    }

    //��ʽ������
    printf("choicelist = ");


    //һ��ѭ����������Ļس���
    for(i = 0; i < 2; i++)
        gets(StrList);

    for(i = 0; i < numOfFriends; i++)
    {
        while(StrList[k] != '\0')
        {
            if(StrList[k] == ']')
            {
                break;
            }
            if(StrList[k] >= '0' && StrList[k] <= '9')
            {
                Friend[i].PreferFruit[l] = Friend[i].PreferFruit[l]*10+StrList[k]-'0';
                if(StrList[k+1] < '0' || StrList[k+1] > '9')
                    l++;
            }
            k++;
        }

        //��¼ÿ����ϲ���ĵ����Ÿ���
        Friend[i].count = l;

        k++;
        l = 0;
    }

    printf("\n");
    //�ֵ���
    FriendComb(0, 0, rows, columns, numOfFriends, SelectFruit, Friend);

    printf("%d\n", MaxMatch);

    return 0;
}

void FriendComb(int i, int deep, int rows, int columns, int numOfFriends, int *SelectFruit, FriendFruitList *Friend)
{
    int TMP = 0;
    if(flag1 != 0)
        deep++;
    flag1 = 1;
    while(i < Friend[deep].count)
    {
        SelectFruit[deep] = Friend[deep].PreferFruit[i];

        /** ��һ����������ȡ����SelectFruit�����ȡ�ظ���ŵĴ��������������� **/

        //ͨ��flag2���Ƽ���
        flag2++;
        if(flag2 > numOfFriends)
            flag2 = numOfFriends;

        if(flag2 >= numOfFriends)
        {
            //����ѡ��ˮ���б���º�����������
            TMP = numOfFriends - RepeatNumberTime(numOfFriends, SelectFruit, rows*columns);
            if(TMP > MaxMatch)
                MaxMatch = TMP;
        }
        /** -------------------------------------------------------------- **/
        if(deep < numOfFriends-1)
            FriendComb(0, deep, rows, columns, numOfFriends, SelectFruit, Friend);

        i++;
    }
}

int RepeatNumberTime(int numOfFriends, int *SelectFruit, int ArraySize)
{
    int i;
    int RepeatNum = 0;
    int *RepeatTimeArray;
    RepeatTimeArray = (int *)calloc(ArraySize, sizeof(int));

    for(i = 0; i < numOfFriends; i++)
        RepeatTimeArray[SelectFruit[i]-1] += 1;

    for(i = 0; i < numOfFriends; i++)
        if(RepeatTimeArray[i] > 0)
        RepeatTimeArray[i] -= 1;

    for(i = 0; i < ArraySize; i++)
        RepeatNum += RepeatTimeArray[i];

    return RepeatNum;
}

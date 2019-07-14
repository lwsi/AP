/******************************************************************************
 ** Date:             2017/08/16                                              *
 ** Version:          1.0                                                     *
 ** Description:      Male & Female - Blind                                   *
 ******************************************************************************
 **                         Important Edit History                            *
 ** --------------------------------------------------------------------------*
 ** DATE           NAME             DESCRIPTION                               *
 ** 2017/08/15    SiQi_Wang             Create                                *
 ******************************************************************************/

/**---------------------------------------------------------------------------*
 *                              Include Files                                 *
 *----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**---------------------------------------------------------------------------*
 *                           StructType Definition                            *
 *----------------------------------------------------------------------------*/
typedef struct
{
    int RoadJunctionId;               //·��Id
    int PassCycle;                    //ͨ������
} RoadJunctionType;                   //�ṹ��·��

typedef struct
{
    int RoadStartId;                  //·����ʼId
    int RoadEndId;                    //·����ֹId
    int ThroughTime;                  //·��ͨ��ʱ��
} RoadPathType;                       //�ṹ��·��

/**---------------------------------------------------------------------------*
 *                            GLOBAL DEFINITION                               *
 *----------------------------------------------------------------------------*/
//int MinTime = 0;

/**---------------------------------------------------------------------------*
 *                              FUNCTION DECLARE                              *
 *----------------------------------------------------------------------------*/
void MinTravelTime(int N, int M, int **WeightMatrix, int StartNode, int EndNode, int *StartToMarkMinTime, RoadJunctionType *RoadJunction);

/******************************************************************************
 *                              Main Function                                 *
 * ---------------------------------------------------------------------------*
 * This function is programming entrance which is able to easily make you know*
 * the run process of program.                                                *
 ******************************************************************************/
int main()
{
    //��������
    int N, M, StartNode, EndNode;
    int *StartToMarkMinTime;
    int i, j;
    int **WeightMatrix;
    RoadJunctionType *RoadJunction;
    RoadPathType *RoadPath;

    /**____________________________________��ʽ�����벿��____________________________________**/
    //·����
    scanf("%d", &N);

    //��ʼ��Ȩ�ؾ���
    WeightMatrix = (int **)malloc(sizeof(int *)*N);
    for(i = 0; i < N; i++)
        *(WeightMatrix + i) = (int *)malloc(sizeof(int)*N);

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            WeightMatrix[i][j] = INT_MAX;

    //��ʼ��·��IdMarkNodeVector
    RoadJunction = (RoadJunctionType *)calloc(N, sizeof(RoadJunctionType));

    for(i = 0; i < N; i++)
        scanf("%d%d", &RoadJunction[i].RoadJunctionId, &RoadJunction[i].PassCycle);

    //·������
    scanf("%d", &M);

    //��ʼ������߼�����Ȩ�ؾ���ֵ
    RoadPath = (RoadPathType *)calloc(M, sizeof(RoadPathType));

    for(i = 0; i < M; i++)
    {
        scanf("%d%d%d", &RoadPath[i].RoadStartId, &RoadPath[i].RoadEndId, &RoadPath[i].ThroughTime);
        WeightMatrix[RoadPath[i].RoadStartId][RoadPath[i].RoadEndId] = RoadPath[i].ThroughTime;
        WeightMatrix[RoadPath[i].RoadEndId][RoadPath[i].RoadStartId] = RoadPath[i].ThroughTime;
    }

    //��������յ�
    scanf("%d%d", &StartNode, &EndNode);

    //dijkstra�㷨������ʼ��
    StartToMarkMinTime = (int *)calloc(N, sizeof(int));       //��㵽����ǽڵ�����ʱ��
    //��ʼ����ʼ�ڵ㵽����ǽڵ����ʱ��Ϊ0
    for(i = 0; i < N; i++)
        StartToMarkMinTime[i] = 0;

    /**_______________________________________Dijkstra�����㷨����________________________________________**/
    MinTravelTime(N, M, WeightMatrix, StartNode, EndNode, StartToMarkMinTime, RoadJunction);

    //�ͷ��ڴ�
    for(i = 0; i < N; i++)
    {
        free(*(WeightMatrix + i));
        WeightMatrix[i] = NULL;
    }
    free(WeightMatrix);
    WeightMatrix = NULL;

    return 0;
}

void MinTravelTime(int N, int M, int **WeightMatrix, int StartNode, int EndNode, int *StartToMarkMinTime, RoadJunctionType *RoadJunction)
{
    int i,j,k;
    int min;
    int tmp;
    int MarkNodeVector[N];      // MarkNodeVeector[i]=1��ʾ"����StartNode"��"����i"�����ʱ���ѳɹ���ȡ��
    int **WaitTime;

    WaitTime = (int **)malloc(sizeof(int *)*N);
    for(i = 0; i < N; i++)
        *(WaitTime + i) = (int *)malloc(sizeof(int)*N);
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            WaitTime[i][j] = 0;

    // ��ʼ��
    for (i = 0; i < N; i++)
    {
        MarkNodeVector[i] = 0;              // ����i�����ʱ�仹û��ȡ����
        StartToMarkMinTime[i] = WeightMatrix[StartNode][i];// ����i�����ʱ��Ϊ"����StartNode"��"����i"��Ȩ��
    }

    // ��"����StartNode"������г�ʼ��
    MarkNodeVector[StartNode] = 1;
    StartToMarkMinTime[StartNode] = 0;

    // ����N-1�Σ�ÿ���ҳ�һ����������ʱ�䡣
    for (i = 1; i < N; i++)
    {
        // Ѱ�ҵ�ǰ��С��ʱ�䣻
        // ������δ��ȡ���ʱ��Ķ����У��ҵ���StartNode����Ķ���(k)��
        min = INT_MAX;
        for (j = 0; j < N; j++)
        {
            if (MarkNodeVector[j]==0 && StartToMarkMinTime[j]<min)
            {
                min = StartToMarkMinTime[j];
                k = j;
            }
        }
        // ���"����k"Ϊ�Ѿ���ȡ�����ʱ��
        MarkNodeVector[k] = 1;

        // ������ǰ���ʱ���ǰ������
        // �������Ѿ�"����k�����ʱ��"֮�󣬸���"δ��ȡ���ʱ��Ķ�������ʱ���ǰ������"��
        for (j = 0; j < N; j++)
        {
            if((((min + WeightMatrix[k][j]) / RoadJunction[j].PassCycle) % 2) == 0 || j == EndNode)
                WaitTime[k][j] = 0;
            else
                WaitTime[k][j] = RoadJunction[j].PassCycle;
            tmp = (WeightMatrix[k][j]==INT_MAX ? INT_MAX : (min + WeightMatrix[k][j] + WaitTime[k][j])); // ��ֹ���
            if (MarkNodeVector[j] == 0 && (tmp  < StartToMarkMinTime[j]) )
                StartToMarkMinTime[j] = tmp;
        }
    }

    // ��ӡdijkstra���ʱ��Ľ��
    for (i = 0; i < N; i++)
        printf("  MinTime(%d, %d)=%d\n", RoadJunction[StartNode].RoadJunctionId, RoadJunction[i].RoadJunctionId, StartToMarkMinTime[i]);

    //�ͷ��ڴ�
    for(i = 0; i < N; i++)
    {
        free(*(WaitTime + i));
        WaitTime[i] = NULL;
    }
    free(WaitTime);
    WaitTime = NULL;

}


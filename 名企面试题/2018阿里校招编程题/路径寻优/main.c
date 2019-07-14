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
    int RoadJunctionId;               //路口Id
    int PassCycle;                    //通行周期
} RoadJunctionType;                   //结构体路口

typedef struct
{
    int RoadStartId;                  //路径起始Id
    int RoadEndId;                    //路径中止Id
    int ThroughTime;                  //路径通过时间
} RoadPathType;                       //结构体路径

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
    //变量声明
    int N, M, StartNode, EndNode;
    int *StartToMarkMinTime;
    int i, j;
    int **WeightMatrix;
    RoadJunctionType *RoadJunction;
    RoadPathType *RoadPath;

    /**____________________________________格式化输入部分____________________________________**/
    //路口数
    scanf("%d", &N);

    //初始化权重矩阵
    WeightMatrix = (int **)malloc(sizeof(int *)*N);
    for(i = 0; i < N; i++)
        *(WeightMatrix + i) = (int *)malloc(sizeof(int)*N);

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            WeightMatrix[i][j] = INT_MAX;

    //初始化路口IdMarkNodeVector
    RoadJunction = (RoadJunctionType *)calloc(N, sizeof(RoadJunctionType));

    for(i = 0; i < N; i++)
        scanf("%d%d", &RoadJunction[i].RoadJunctionId, &RoadJunction[i].PassCycle);

    //路的条数
    scanf("%d", &M);

    //初始化有向边集并给权重矩阵赋值
    RoadPath = (RoadPathType *)calloc(M, sizeof(RoadPathType));

    for(i = 0; i < M; i++)
    {
        scanf("%d%d%d", &RoadPath[i].RoadStartId, &RoadPath[i].RoadEndId, &RoadPath[i].ThroughTime);
        WeightMatrix[RoadPath[i].RoadStartId][RoadPath[i].RoadEndId] = RoadPath[i].ThroughTime;
        WeightMatrix[RoadPath[i].RoadEndId][RoadPath[i].RoadStartId] = RoadPath[i].ThroughTime;
    }

    //输入起点终点
    scanf("%d%d", &StartNode, &EndNode);

    //dijkstra算法参数初始化
    StartToMarkMinTime = (int *)calloc(N, sizeof(int));       //起点到各标记节点的最短时间
    //初始化初始节点到各标记节点最短时间为0
    for(i = 0; i < N; i++)
        StartToMarkMinTime[i] = 0;

    /**_______________________________________Dijkstra核心算法部分________________________________________**/
    MinTravelTime(N, M, WeightMatrix, StartNode, EndNode, StartToMarkMinTime, RoadJunction);

    //释放内存
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
    int MarkNodeVector[N];      // MarkNodeVeector[i]=1表示"顶点StartNode"到"顶点i"的最短时间已成功获取。
    int **WaitTime;

    WaitTime = (int **)malloc(sizeof(int *)*N);
    for(i = 0; i < N; i++)
        *(WaitTime + i) = (int *)malloc(sizeof(int)*N);
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            WaitTime[i][j] = 0;

    // 初始化
    for (i = 0; i < N; i++)
    {
        MarkNodeVector[i] = 0;              // 顶点i的最短时间还没获取到。
        StartToMarkMinTime[i] = WeightMatrix[StartNode][i];// 顶点i的最短时间为"顶点StartNode"到"顶点i"的权。
    }

    // 对"顶点StartNode"自身进行初始化
    MarkNodeVector[StartNode] = 1;
    StartToMarkMinTime[StartNode] = 0;

    // 遍历N-1次；每次找出一个顶点的最短时间。
    for (i = 1; i < N; i++)
    {
        // 寻找当前最小的时间；
        // 即，在未获取最短时间的顶点中，找到离StartNode最近的顶点(k)。
        min = INT_MAX;
        for (j = 0; j < N; j++)
        {
            if (MarkNodeVector[j]==0 && StartToMarkMinTime[j]<min)
            {
                min = StartToMarkMinTime[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短时间
        MarkNodeVector[k] = 1;

        // 修正当前最短时间和前驱顶点
        // 即，当已经"顶点k的最短时间"之后，更新"未获取最短时间的顶点的最短时间和前驱顶点"。
        for (j = 0; j < N; j++)
        {
            if((((min + WeightMatrix[k][j]) / RoadJunction[j].PassCycle) % 2) == 0 || j == EndNode)
                WaitTime[k][j] = 0;
            else
                WaitTime[k][j] = RoadJunction[j].PassCycle;
            tmp = (WeightMatrix[k][j]==INT_MAX ? INT_MAX : (min + WeightMatrix[k][j] + WaitTime[k][j])); // 防止溢出
            if (MarkNodeVector[j] == 0 && (tmp  < StartToMarkMinTime[j]) )
                StartToMarkMinTime[j] = tmp;
        }
    }

    // 打印dijkstra最短时间的结果
    for (i = 0; i < N; i++)
        printf("  MinTime(%d, %d)=%d\n", RoadJunction[StartNode].RoadJunctionId, RoadJunction[i].RoadJunctionId, StartToMarkMinTime[i]);

    //释放内存
    for(i = 0; i < N; i++)
    {
        free(*(WaitTime + i));
        WaitTime[i] = NULL;
    }
    free(WaitTime);
    WaitTime = NULL;

}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, m, SumSub, Sumn = 0, Summ = 0, *a, *tmpa, *b, *tmpb, *sub;
    int i, j, lena, lenb, tmp, MinSubAbs, TmpMinSubAbs;

    scanf("%d", &n);

    a = (int* )calloc(n, sizeof(int));
    tmpa = (int* )calloc(n, sizeof(int));

    for(i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        tmpa[i] = a[i];
        Sumn = Sumn + a[i];

    }

    scanf("%d", &m);

    b = (int* )calloc(m, sizeof(int));
    tmpb = (int* )calloc(m, sizeof(int));

    for(j = 0; j < m; j++)
    {
        scanf("%d", b + j);
        tmpb[j] = b[j];
        Summ = Summ + b[j];

    }

    //sum(a) - sum(b)
    SumSub = Sumn - Summ;

    //交换一对数字的差值遍历向量
    sub = (int* )calloc(m*n, sizeof(int));


    /**  ------------------交换一次的情况------------------ **/
    int k = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            sub[k++] = a[i] - b[j];
        }
    }

    for(i = 0; i < m*n; i++)
    {
        sub[i] = abs(2*sub[i] - SumSub);
    }

    //寻找min(sub[i])，即为最小的绝对差值
    MinSubAbs = sub[0];

    for(i = 0; i < m*n; i++)
    {
        if(sub[i] < MinSubAbs)
            MinSubAbs = sub[i];
    }


    /**  ------------------交换两次的情况------------------ **/
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            //获取交换一次之后的数列ab,即tmpa,tmpb
            tmp = tmpa[i];
            tmpa[i] = tmpb[j];
            tmpb[j] = tmp;

            /*_________对交换一次的数列tmpa和tmpb运用交换一次的求法________*/

            k = 0;
            SumSub = 0, Sumn = 0, Summ = 0;
            //更新数列的和
            for(lena = 0; lena < n; lena++)
                Sumn = Sumn + tmpa[lena];
            for(lenb = 0; lenb < m; lenb++)
                Summ = Summ + tmpb[lenb];
            SumSub = Sumn - Summ;

            //更新遍历差值
            for(lena = 0; lena < n; lena++)
            {
                for(lenb = 0; lenb < m; lenb++)
                {
                    sub[k++] = tmpa[lena] - tmpb[lenb];
                }
            }

            for(lena = 0; lena < m*n; lena++)
            {
                sub[lena] = abs(2*sub[lena] - SumSub);
            }

            //寻找min(sub[lena])，即为局部最小的绝对差值
            TmpMinSubAbs = sub[0];

            for(lena = 0; lena < m*n; lena++)
            {
                if(sub[lena] < TmpMinSubAbs)
                    TmpMinSubAbs = sub[lena];
            }

            //更新全局最小差值
            if(TmpMinSubAbs < MinSubAbs)
                MinSubAbs = TmpMinSubAbs;

            //还原tmpa, tmpb
            for(lena = 0; lena < n; lena++)
                tmpa[lena] = a[lena];
            for(lenb = 0; lenb < m; lenb++)
                tmpb[lenb] = b[lenb];

        }
    }

    printf("%d", MinSubAbs);

    return 0;
}

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

    //����һ�����ֵĲ�ֵ��������
    sub = (int* )calloc(m*n, sizeof(int));


    /**  ------------------����һ�ε����------------------ **/
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

    //Ѱ��min(sub[i])����Ϊ��С�ľ��Բ�ֵ
    MinSubAbs = sub[0];

    for(i = 0; i < m*n; i++)
    {
        if(sub[i] < MinSubAbs)
            MinSubAbs = sub[i];
    }


    /**  ------------------�������ε����------------------ **/
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            //��ȡ����һ��֮�������ab,��tmpa,tmpb
            tmp = tmpa[i];
            tmpa[i] = tmpb[j];
            tmpb[j] = tmp;

            /*_________�Խ���һ�ε�����tmpa��tmpb���ý���һ�ε���________*/

            k = 0;
            SumSub = 0, Sumn = 0, Summ = 0;
            //�������еĺ�
            for(lena = 0; lena < n; lena++)
                Sumn = Sumn + tmpa[lena];
            for(lenb = 0; lenb < m; lenb++)
                Summ = Summ + tmpb[lenb];
            SumSub = Sumn - Summ;

            //���±�����ֵ
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

            //Ѱ��min(sub[lena])����Ϊ�ֲ���С�ľ��Բ�ֵ
            TmpMinSubAbs = sub[0];

            for(lena = 0; lena < m*n; lena++)
            {
                if(sub[lena] < TmpMinSubAbs)
                    TmpMinSubAbs = sub[lena];
            }

            //����ȫ����С��ֵ
            if(TmpMinSubAbs < MinSubAbs)
                MinSubAbs = TmpMinSubAbs;

            //��ԭtmpa, tmpb
            for(lena = 0; lena < n; lena++)
                tmpa[lena] = a[lena];
            for(lenb = 0; lenb < m; lenb++)
                tmpb[lenb] = b[lenb];

        }
    }

    printf("%d", MinSubAbs);

    return 0;
}

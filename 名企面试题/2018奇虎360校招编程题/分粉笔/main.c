#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d, n, m, x, y, z, max1, max2, max3;
    int i, j, k, tmp, MaxMoney = 0;

    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    scanf("%d%d%d", &x, &y, &z);

    if((n/a) < (m/b))
        max1 = n / a;
    else
        max1 = m / b;

    max2 = m / c;
    max3 = n / d;

    for(i = 0; i <= max1; i++)
        for(j = 0; j <= max2; j++)
            for(k = 0; k <= max3; k++)
                if((a*i + d*k) <= n && (b*i + c*j) <= m)
                {
                    tmp = x*i + y*j + z*k;
                    if(tmp > MaxMoney)
                        MaxMoney = tmp;
                }

    printf("%d", MaxMoney);

    return 0;
}

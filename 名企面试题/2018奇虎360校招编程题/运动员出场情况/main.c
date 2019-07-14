#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, *a;
    int i, j, num = 0;

    scanf("%d", &n);

    a = (int* )calloc(n, sizeof(int));

    for(i = 0; i < n; i++)
        scanf("%d", a+i);

    for(i = 0; i < n; i++)
    {
        for(j = i; j >= 0; j--)
        {
            if(a[j] > a[i])
                num++;
        }

        printf("%d ", num);

        num = 0;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 1000

int main() {
	int n, K;
	int i, j, k, *prefer, *fav, favsum = 0, minfav = 0, mink = 0;

	scanf("%d%d", &n, &K);

	if (n > 1e5 || n < 10 || K > n || K < 2)
		return 0;
	prefer = (int *)calloc(n, sizeof(int));
	fav = (int *)calloc(K, sizeof(int));

	for (i = 0; i < K; i++)
		fav[i] = 0;

	for (i = 0; i < n; i++) {
		scanf("%d", &prefer[i]);
	}

	minfav = prefer[0];
	for (i = 0; i <= n; i++)
	{
		if (i < K)
		{
			fav[i] = prefer[i];
			continue;
		}
		for (j = 0; j < K; j++)
		{
			favsum += fav[j];
		}
		printf("%d ", favsum);
		favsum = 0;
		if (i == n)
			break;

		for (k = 0; k < K; k++)
		{
			if (fav[k] < minfav)
			{
				minfav = fav[k];
				mink = k;
			}
		}

		if (prefer[i] > minfav)
			fav[mink] = prefer[i];

		minfav = MAX_INT;
	}

	system("pause");

	return 0;
}

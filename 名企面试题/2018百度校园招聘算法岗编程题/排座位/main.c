#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int L, S;
	int i, SeatSort = 0;
	scanf("%d%d", &L, &S);

	//排座位总数2^L
	SeatSort = pow(2, L);

	//不算环路之外，抠去挨着的不满足次数
	for(i = L-S+1; i >= 1; i--)
        SeatSort -= i;

    //抠去环路不满足次数
    for(i = S-1; i <= L-2; i++)
        SeatSort -= i;

    printf("%d", SeatSort % 123456789);

	return 0;
}

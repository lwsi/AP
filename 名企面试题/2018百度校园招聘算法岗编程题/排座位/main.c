#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int L, S;
	int i, SeatSort = 0;
	scanf("%d%d", &L, &S);

	//����λ����2^L
	SeatSort = pow(2, L);

	//���㻷·֮�⣬��ȥ���ŵĲ��������
	for(i = L-S+1; i >= 1; i--)
        SeatSort -= i;

    //��ȥ��·���������
    for(i = S-1; i <= L-2; i++)
        SeatSort -= i;

    printf("%d", SeatSort % 123456789);

	return 0;
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	int N, M, X, Y, T;
	scanf("%d %d %d %d", &N, &M, &X, &Y);
	T = (Y*N+M)/(X+Y);
	T = (T>N?N:T);
	printf("%d\n", T);
	return 0;
}
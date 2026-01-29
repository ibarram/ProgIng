#include <stdio.h>

int main(int argc, char *argv[])
{
	int M, N, X, Y, P;
	scanf("%d %d %d %d", &M, &N, &X, &Y);
	P = (N+Y*M)/(X+Y);
	printf("%d\n", P>M?M:P);
	return 0;
}
#include <stdio.h>

int main(int argc, char *argv[])
{
	int N, M, X, Y, E;
	scanf("%d %d %d %d", &N, &M, &X, &Y);
	E = (M+N*Y)/(X+Y);
	E = (E>N?N:E);
	printf("%d\n", E);
	return 0;
}
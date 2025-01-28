#include <stdio.h>

int main(int argc, char *argv[])
{
	int N, M, X, Y, S;
	printf("Ingrese los valores: ");
	scanf("%d %d %d %d", &N, &M, &X, &Y);
	S = (N*Y+M)/(X+Y);
	printf("Resultado = %d\n", N*X<M?N:S);
	return 0;
}
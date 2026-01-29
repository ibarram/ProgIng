#include <stdio.h>

int main(int argc, char *argv[])
{
	int D4, D3, D2, D1, salida, b2, b1, b0;
	scanf("%d %d %d %d", &D4, &D3, &D2, &D1);
	b0 = D1|D3&~D2&~D1;
	b1 = D3&~D2&~D1|D2&~D1;
	b2 = D4&~D3&~D2&~D1;
	salida = (b2<<2)+(b1<<1)+b0;

	printf("Salida = %d (%1d %1d %1d)\n", salida, b2, b1, b0);
	return 0;
}
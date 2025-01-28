#include<stdio.h>

int main(int argc, char *argv[])
{
	int D4, D3, D2, D1, sal, b0, b1, b2;
	printf("Ingrese el estado: ");
	scanf("%d %d %d %d", &D4, &D3, &D2, &D1);
	b0 = D1|(~D2&D3);
	b1 = ~D1&(D2|D3);
	b2 = ~D1&~D2&~D3&D4;
	sal = 4*b2+2*b1+b0;
	printf("Salida = %d (%d%d%d)\n", sal, b2, b1, b0);
	return 0;
}
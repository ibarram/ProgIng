#include <stdio.h>

int main(int argc, char *argv[])
{
	float ex, x, fct;
	long int i, j, n;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%ld", &n);
	}while(n<0);
	for(i=0, ex=0; i<n; i++)
	{
		for(j=0, fct=1; j<i; j++)
			fct *= x/(j+1);
		ex += fct;
	}
	printf("exp(%f) = %f\n", x, ex);
	return 0;
}
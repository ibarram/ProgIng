#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, i, j;
	float x, ex, fct;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	for(i=0, ex=0; i<n; i++)
	{
		for(j=0, fct=1; j<i; j++)
			fct*=(x/(j+1));
		ex+=fct;
	}
	printf("exp(%f) = %f\n", x, ex);
	return 0;
}

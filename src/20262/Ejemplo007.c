#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, i, j;
	long int fn;
	float x, px, ex;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	for(i=0, ex=0; i<n; i++)
	{
		for(j=0, px=1, fn=1; j<i; j++)
		{
			px*=x;
			fn*=(j+1);
		}
		ex+=(px/fn);
	}
	printf("exp(%f) = %f\n", x, ex);
	return 0;
}

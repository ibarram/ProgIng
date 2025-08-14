#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, i, den;
	float x, ex, num;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	for(i=0, ex=0, num=1, den=1; i<n; i++)
	{
		ex+=(num/den);
		num*=x;
		den*=(i+1);
	}
	printf("exp(%f) = %f\n", x, ex);
	return 0;
}
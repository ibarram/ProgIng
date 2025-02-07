#include <stdio.h>

int main(int argc, char *argv[])
{
	float ex, x, num;
	long int i, j, n, den;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%ld", &n);
	}while(n<0);
	for(i=0, ex=0; i<n; i++)
	{
		for(j=0, num=1, den=1; j<i; j++)
		{
			num*=x;
//		for(j=0, den=1; j<i; j++)
			den*=(j+1); //den=den*(j+1);
		}
		ex += num/den;
	}
	printf("exp(%f) = %f\n", x, ex);
	return 0;
}
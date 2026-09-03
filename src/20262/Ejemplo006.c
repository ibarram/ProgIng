#include<stdio.h>

int main(int argc, char *argv[])
{
	int n, i, s, d;
	float pi;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	for(i=0, pi=0, s=1; i<n; i++)
	{
		d = 2*i+1;
		pi+=(s*1.0/d);
		s *= -1;
	}
	pi*=4;
	printf("PI = %f\n", pi);
	return 0;
}
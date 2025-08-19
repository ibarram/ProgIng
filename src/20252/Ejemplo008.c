#include<stdio.h>

int main(int argc, char*argv[])
{
	int i, n;
	float x, lnx, fct, num;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	do{
		printf("Ingrese l valor de x: ");
		scanf("%f", &x);
	}while(x<=0);
	for(i=0, fct=(x-1)/(x+1), num=fct, lnx=0; i<n; i++)
	{
		lnx+=(num/(2*i+1));
		num*=(fct*fct);
	}
	lnx*=2;
	printf("ln(%f) = %f\n", x, lnx);
	return 0;
}
#include <stdio.h>

int main(int argc, char *argv[])
{
	float lnx, x, num, fct, px;
	int i, den, n;
	do{
		printf("Intese el valor de x: ");
		scanf("%f", &x);
	}while(x<=0);
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<=0);
	for(i=0, px=(x-1)/(x+1), fct=px, lnx=0; i<n; i++)
	{
		lnx += fct;
		fct*= (2*i+1)*(px*px)/(2*i+3);

	}
	lnx*=2;
	printf("ln(%f) = %f\n", x, lnx);
	return 0;
}
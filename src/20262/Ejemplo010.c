#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, i, j;
	float x, f, pf, lnx;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	do{
		printf("Ingrese el valor de x: ");
		scanf("%f", &x);
	}while(x<=0);
	for(i=0, f=(x-1)/(x+1), lnx=0; i<n; i++)
	{
		for(j=0, pf=1; j<(2*i+1); j++)
			pf*=f;
		lnx+=(pf/(2*i+1));
	}
	lnx*=2;
	printf("ln(%f) = %f\n", x, lnx);
	return 0;
}

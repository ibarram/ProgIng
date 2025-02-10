#include <stdio.h>

#define PI2 2*3.1415926535897932

int main(int argc, char *argv[])
{
	float x, sx, fct;
	int n, i;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	x-=((int)(x/(PI2)))*PI2;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	for(i=0, sx=0, fct=x; i<n; i++)
	{
		sx += (1-2*(i%2))*fct;
		fct *= (x/(2*i+2))*(x/(2*i+3));
	}
	printf("sin(%f) = %f\n", x, sx);
	return 0;
}

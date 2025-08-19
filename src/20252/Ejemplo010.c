#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, n, s;
	float x, sx, fct;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	for(i=0, fct=x, sx=0; i<n; i++)
	{
		s = 1-2*(i%2);
		sx += (s*fct);
		fct *= (x/(2*i+2))*(x/(2*i+3));
	}
	printf("sin(%f) = %f\n", x, sx);
	return 0;
}
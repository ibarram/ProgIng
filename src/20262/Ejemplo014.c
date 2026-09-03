#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, i, s;
	float x, sx, fct;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	for(i=0, sx=0, s=1, fct=x; i<n; i++)
	{
		sx+=(s*fct);
		s*=-1;
		fct*=((x/(2*i+2))*(x/(2*i+3)));
	}
	printf("sin(%f) = %f\n", x, sx);
	return 0;
}

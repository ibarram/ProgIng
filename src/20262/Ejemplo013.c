#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, i, j, s;
	float x, sx, fct;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	for(i=0, sx=0, s=1; i<n; i++)
	{
		for(j=0, fct=1; j<(2*i+1); j++)
			fct*=(x/(j+1));
		sx+=(s*fct);
		s*=-1;
	}
	printf("sin(%f) = %f\n", x, sx);
	return 0;
}

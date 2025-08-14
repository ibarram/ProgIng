#include <stdio.h>

int main(int argc, char *argv[])
{
	// s es el signo
	// d es el denominador
	// n es el numero de terminos
	// i es el contador
	// pi es el valor de pi
	int n, i, s, d;
	float pi;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<=0);
	for(i=0, pi=0; i<n; i++)
	{
		s = 1-2*(i%2);
		d = 2*i+1;
		pi+=(s*1.0/d);
	}
	pi*=4;
	printf("PI = %f\n", pi);
	return 0;
}
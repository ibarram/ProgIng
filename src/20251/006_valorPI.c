#include <stdio.h>

int main(int argc, char *argv[])
{
	float pi;
	int i, n, den, sg;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<0);
	for(i=0, pi=1; i<n; i++)
	{
		den = 2*i+3;
		sg = 2*(i%2)-1;
		pi+=(sg/(float)den);
	}
	pi*=4;
	printf("PI = %f\n", pi);
	return 0;
}
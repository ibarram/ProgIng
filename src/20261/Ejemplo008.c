#include<stdio.h>

int main(int argc, char *argv[])
{
	float pi;
	int i, n, den, signo;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	for(i=0, pi=0; i<n; i++)
	{
		den = 2*i+1;
		signo = 1-2*(i%2);
		pi+=(signo*1.0/den);
	}
	pi*=4;
	printf("PI = %f\n", pi);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000

int main(int argc, char *argv[])
{
	int n, i;
	float max, min, aux, x[N], vmx, vmn, md, st;
	srand(time(NULL));
	do{
		printf("Ingrese el numero de datos: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	printf("Ingrese el numero maximo: ");
	scanf("%f", &max);
	printf("Ingrese el numero minimo: ");
	scanf("%f", &min);
	if(max<min)
	{
		aux = max;
		max = min;
		min = aux;
	}
	for(i=0, vmn=max, vmx=min, md=0, st=0; i<n; i++)
	{
		x[i] = ((max-min)*rand())/RAND_MAX+min;
		printf("X[%d] = %f\n", i+1, x[i]);
		if(vmn>x[i])
			vmn = x[i];
		if(vmx<x[i])
			vmx = x[i];
		md+=x[i];
		st+=(x[i]*x[i]);
	}
	md/=n;
	st/=n;
	st-=(md*md);
	st=sqrt(st);
	printf("Max: %f\n Min = %f\n Media = %f\n D. E. = %f\n", 
		vmx, vmn, md, st);
	return 0;
}

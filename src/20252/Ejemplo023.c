#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000

int main(int argc, char *argv[])
{
	int n, i, flag, op;
	float max, min, aux, x[N], vmx, vmn, md, st, z[N], cn, nr;
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
	flag = 0;
	printf("Desea centrar: ");
	scanf("%d", &op);
	if(op)
	{
		printf("Por rango: ");
		scanf("%d", &op);
		flag|=(op?1:4);
	}
	printf("Desea normalizar: ");
	scanf("%d", &op);
	if(op)
	{
		printf("Por rango: ");
		scanf("%d", &op);
		flag|=(op?2:8);
	}
	cn = (flag&1)?vmn:(flag&4?md:0);
	nr = (flag&2)?vmx-vmn:(flag&8?st:1);
	printf("%d\t%f\t%f\n", flag, cn, nr);
	for(i=0; i<n; i++)
	{
		z[i] = (x[i]-cn)/nr;
		printf("Z[%d] = %f\n", i+1, z[i]);
	}
	return 0;
}

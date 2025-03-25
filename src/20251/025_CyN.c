#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 10000

int main(int argc, char *argv[])
{
	float X[N], min, max, xmin, xmax, xmed, xvar, xran;
	int n, i, flag, flag_e, flag_n, flag_c;
	do{
		printf("Ingrese el numero de muestra: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Ingrese el valor minimo: ");
	scanf("%f", &min);
	printf("Ingrese le valor maximo: ");
	scanf("%f", &max);
	if(min>max)
	{
		max*=min;
		min=max/min;
		max/=min;
	}
	srand(time(NULL));
	for(i=0; i<n; i++)
	{
		X[i] = ((max-min)*rand())/RAND_MAX+min;
		printf("X[%d] = %f\n", i+1, X[i]);
	}
	printf("Normalización: ");
	scanf("%d", &flag_n);
	printf("Centrado: ");
	scanf("%d", &flag_c);
	printf("Estadistico: ");
	scanf("%d", &flag_e);
	flag = ((flag_c<<1)|flag_n)<<(flag_e<<1);
	printf("flag = %d\n", flag);
	for(xmin=X[0], xmax=X[0], xmed=X[0], xvar=X[0]*X[0], i=1; i<n; i++)
	{
		if(X[i]<xmin)
			xmin = X[i];
		if(X[i]>xmax)
			xmax = X[i];
		xmed += X[i];
		xvar += X[i]*X[i];
	}
	xmed/=n;
	xvar/=n;
	xvar-=(xmed*xmed);
	xran=xmax-xmin;
	if((flag&1)|(flag&4))
		for(i=0; i<n; i++)
			X[i]-=(flag&4?xmed:xmin);
	if((flag&2)|(flag&8))
		for(i=0; i<n; i++)
			X[i]/=(flag&8?xvar:xran);
	printf("Maximo: %f\nMinimo: %f\nMedia: %f\nVarianza: %f\n", 
		xmax, xmin, xmed, xvar);
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, X[i]);
	return 0;
}
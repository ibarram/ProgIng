#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000

int main(int argc, char *argv[])
{
	int n, i;
	float x[N], xnr[N], xnz[N], min, max, m, s;
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	srand((unsigned int)time(NULL));
	for(i=0; i<n; i++)
		x[i] = (16.0*rand())/RAND_MAX+4;
	for(i=1, min=x[0], max=x[0], m=x[0], s=x[0]*x[0]; i<n; i++)
	{
		if(min>x[i])
			min = x[i];
		if(max<x[i])
			max = x[i];
		m+=x[i];
		s+=(x[i]*x[i]);
	}
	m/=n;
	s/=n;
	s-=(m*m);
	s = sqrt(s);
	for(i=0; i<n; i++)
	{
		xnr[i] = (x[i]-min)/(max-min);
		xnz[i] = (x[i]-m)/s;
	}
	printf("Maximo = %f\tMinimo=%f\n", max, min);
	printf("Media = %f\tDesviacion Estandar = %f\n", m, s);
	for(i=0; i<n; i++)
		printf("%f\t%f\t%f\n", x[i], xnr[i], xnz[i]);
	return 0;
}
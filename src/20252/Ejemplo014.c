#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10000

int main(int argc, char*argv[])
{
	int i, j, n;
	float max, min, x[N], aux;
	srand(time(NULL));
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	printf("Ingrese el valor maximo: ");
	scanf("%f", &max);
	printf("Ingrese el valor minimo: ");
	scanf("%f", &min);
	if(min>max)
	{
		if(max)
		{
			if(min)
			{
				min*=max;
				max=min/max;
				min/=max;
			}
			else
			{
				min = max;
				max = 0;
			}
		}
		else
		{
			max = min;
			min = 0;
		}
	}
	printf("Desordenado.\n");
	for(i=0; i<n; i++)
	{
		x[i] = ((max-min)*rand())/RAND_MAX+min;
		printf("X[%d] = %f\n", i+1, x[i]);
	}
	// Algoritmo Pares y Nones
	for(i=0; i<n; i++)
	{
		for(j=i%2; j<(n+i%2)/2; j++)
			if(x[2*j-i%2]>x[2*j+1-i%2])
			{
				aux = x[2*j-i%2];
				x[2*j-i%2] = x[2*j+1-i%2];
				x[2*j+1-i%2] = aux;
			}
		/*
		if(i%2)
			for(j=1; j<n/2; j++)
				x[2*i-1] x[2*i]
			x[1] x[2]
			x[3] x[4]
			x[5] x[6]
		else
			for(j=0; j<n/2; j++)
				x[2*i] x[2*i+1]
			x[0] x[1]
			x[2] x[3]
			x[4] x[5]
			*/
	}
	printf("Ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, x[i]);
	return 0;
}
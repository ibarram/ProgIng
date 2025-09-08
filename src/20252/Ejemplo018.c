#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10000

int main(int argc, char*argv[])
{
	int i, j, k, n;
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
	// Algoritmo de Bidireccional
	for(i=0; i<n-1; i++)
	{
		i%2
		n-2 1
		n-3 2
		n-4 3
		for(j=(i%2?n-1-i/2:i/2+1); ; i%2?j--:j++)
	}
	/*
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(x[i]>x[j])
			{
				aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			}
		}
	}
	for(i=n-1; i>0; i--)
	{
		for(j=i-1; j>-1; j--)
		{
			if(x[i]<x[j])
			{
				aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			}
		}
	}
	*/
	printf("Ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, x[i]);
	return 0;
}
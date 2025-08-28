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
	// Algoritmo de Insercion
	printf("Ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, x[i]);
	return 0;
}
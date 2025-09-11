#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000000

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
		for(j=(i%2?n-1-i/2:i/2+1); 
				(i%2?j>=(i/2+1):(j<=n-1-i/2)); 
				i%2?j--:j++)
		{
			if(i%2?(x[i%2?n-i/2-1:i/2]<x[j])
				:(x[i%2?n-i/2-1:i/2]>x[j]))
			{
				aux = x[j];
				x[j] = x[i%2?n-i/2-1:i/2];
				x[i%2?n-i/2-1:i/2] = aux;
			}
//			printf("i=%d\tx[k], k=%d\tj=%d\n", i, 
//				i%2?n-i/2-1:i/2, j);
		}
	}
	printf("Ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, x[i]);
	return 0;
}
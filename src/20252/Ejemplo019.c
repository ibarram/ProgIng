#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000000

int main(int argc, char*argv[])
{
	int i, j, k, n;
	int max, min, x[N], h[N];
	srand(time(NULL));
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	printf("Ingrese el valor maximo: ");
	scanf("%d", &max);
	printf("Ingrese el valor minimo: ");
	scanf("%d", &min);
	if(min>max)
	{
		if(max)
		{
			if(min)
			{
				min+=max;
				max=min-max;
				min-=max;
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
		x[i] = rand()%(max-min+1)+min;
		printf("X[%d] = %d\n", i+1, x[i]);
	}
	// Algoritmo de Conteo
	for(i=0; i<(max-min+1); i++)
		h[i]=0;
	for(i=0; i<n; i++)
		h[x[i]-min]++;
	for(j=0, i=0; j<(max-min+1); j++)
	{
		while(h[j])
		{
			x[i] = j+min;
			h[j]--;
			i++;
		}
		if(i==n)
			break;
	}
	printf("Ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %d\n", i+1, x[i]);
	return 0;
}
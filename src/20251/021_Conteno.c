#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main(int argc, char *argv[])
{
	int n, min, max, X[N], i, j, rg;
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
		max^=min;
		min^=max;
		max^=min;
	}
	rg = max-min;
	srand(time(NULL));
	for(i=0; i<n; i++)
		X[i] = (rand()%(max-min+1))+min;
	printf("Desordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %d\n", i+1, X[i]);
	int h[rg+1];
	for(i=0; i<rg+1; i++)
		h[i] = 0;
	for(i=0; i<n; i++)
		h[X[i]-min]++;
	printf("Histograma\n");
	for(i=0; i<rg+1; i++)
		printf("h[%d] = %d\n", min+i, h[i]);
	for(i=0, j=0; i<n; )
	{
		while(!h[j])
			j++;
		while(h[j])
		{
			h[j]--;
			X[i++] = j+min;
		}
	}

	printf("Ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %d\n", i+1, X[i]);
	return 0;
}
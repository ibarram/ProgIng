#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000

int main(int argc, char *argv[])
{
	int i, j, k, n;
	int X[N], max, min, aux, h[N];
	//srand((unsigned)time(NULL));
	srand(123);
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	printf("Ingrese el maximo: ");
	scanf("%d", &max);
	printf("Ingrese el minimo: ");
	scanf("%d", &min);
	if(max<min)
	{
		max+=min;
		min=max-min;
		max-=min;
	}
	printf("n = %d\nrango = [%d, %d]\n", n, min, max);
	printf("Vector desordenado.\n");
	for(i=0; i<n; i++)
	{
		X[i] = rand()%(max-min+1)+min;
		printf("X[%d] = %d\n", i+1, X[i]);
	}
	for(i=0; i<(max-min+1); i++)
		h[i] = 0;
	for(i=0; i<n; i++)
		h[X[i]-min]++;
	for(i=0, j=0; i<(max-min+1); i++)
		while(h[i])
		{
			X[j++] = i+min;
			h[i]--;
		}
	printf("Vector ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %d\n", i+1, X[i]);
	return 0;
}
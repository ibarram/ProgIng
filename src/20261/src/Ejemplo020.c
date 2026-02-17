#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int main(int argc, char *argv[])
{
	long int n, i, j;
	int min, max, x[N], aux;
	do{
		printf("Ingrese el numero de elmentos: ");
		scanf("%ld", &n);
	}while(n<1||n>N);
	printf("Ingrese el valor maximo: ");
	scanf("%d", &max);
	printf("Ingrese el valor minimo: ");
	scanf("%d", &min);
	if(min>max)
	{
		max+=min;
		min=max-min;
		max-=min;
	}
	srand(time(NULL));
	printf("Desordenado.\n");
	for(i=0; i<n; i++)
	{
		x[i] = rand()%(max-min+1)+min;
		printf("x[%ld] = %d\n", i+1, x[i]);
	}
	for(i=0; i<n-1; i++)
	{
		printf("%ld-\t", i%2);
		for(j=i%2; j<n/2; j++)
			printf("%ld\t", j);
		printf("\n");

	}
	printf("Ordenado.\n");
	for(i=0; i<n; i++)
		printf("x[%ld] = %d\n", i+1, x[i]);
	return 0;
}
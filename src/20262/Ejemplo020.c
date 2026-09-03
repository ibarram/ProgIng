#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000

int main(int argc, char *argv[])
{
	int i, j, n;
	float X[N], max, min, aux;
	srand((unsigned)time(NULL));
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	printf("Ingrese el maximo: ");
	scanf("%f", &max);
	printf("Ingrese el minimo: ");
	scanf("%f", &min);
	if(max<min)
	{
		if(!max)
		{
			max=min;
			min=0; 
		}
		else if(!min)
		{
			min=max;
			max=0;
		}
		else
		{
			max*=min;
			min=max/min;
			max/=min;
		}
	}
	printf("n = %d\nrango = [%f, %f]\n", n, min, max);
	printf("Vector desordenado.\n");
	for(i=0; i<n; i++)
	{
		X[i] = (((max-min)*rand())/RAND_MAX)+min;
		printf("X[%d] = %f\n", i+1, X[i]);
	}
	for(i=0; i<n-1; i++)
		for(j=i%2; j<(n+i%2)/2; j++)
			if(X[2*j-i%2]>X[2*j+1-i%2])
			{
				aux = X[2*j-i%2];
				X[2*j-i%2] = X[2*j+1-i%2];
				X[2*j+1-i%2] = aux;
			}
	printf("Vector ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, X[i]);
	return 0;
}
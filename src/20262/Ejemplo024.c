#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000

int main(int argc, char *argv[])
{
	int i, j, k, n;
	float X[N], max, min, aux;
	//srand((unsigned)time(NULL));
	srand(123);
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
	for(k=0; k<(n-1); k++)
	{
		i = k%2?(n-(k+1)/2):k/2;
		for(j=i+(k%2?-1:+1); k%2?j>(k-1)/2:j<(n-k/2); k%2?j--:j++)
			if(k%2?X[i]<X[j]:X[i]>X[j])
			{
				aux = X[i];
				X[i] = X[j];
				X[j] = aux;
			}
	}
	printf("Vector ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, X[i]);
	return 0;
}
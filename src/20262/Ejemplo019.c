#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000

int main(int argc, char *argv[])
{
	int i, n;
	float X[N], max, min;
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
	for(i=0; i<n; i++)
	{
		X[i] = (((max-min)*rand())/RAND_MAX)+min;
		printf("X[%d] = %f\n", i+1, X[i]);
	}
	return 0;
}
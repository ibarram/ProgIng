#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main(int argc, char *argv[])
{
	long int n, i, j;
	float X[N], max, min;
	srand(time(NULL));
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%ld", &n);
	}while(n<2||n>N);
	printf("Ingrese le valor maximo: ");
	scanf("%f", &max);
	printf("Ingrese el valor minimo: ");
	scanf("%f", &min);
	if(max<min)
	{
		max*=min;
		min=max/min;
		max/=min;
	}
	printf("[%f, %f]\n", min, max);
	printf("Desordenados.\n");
	for(i=0; i<n; i++)
	{
		X[i] = ((max-min)*rand())/RAND_MAX+min;
		printf("X[%ld] = %f\n", i+1, X[i]);
	}
	for(j=0; j<n; j++)
	{
		for(i=j%2; i<(n+j%2)/2; i++)
			if(X[2*i-j%2]>X[2*i+(j+1)%2])
			{
				X[2*i-j%2]*=X[2*i+(j+1)%2];
				X[2*i+(j+1)%2]=X[2*i-j%2]/X[2*i+(j+1)%2];
				X[2*i-j%2]/=X[2*i+(j+1)%2];
			}
/*		for(i=0; i<n/2; i++)
			if(X[2*i]>X[2*i+1])
			{
				X[2*i]*=X[2*i+1];
				X[2*i+1]=X[2*i+1]/X[2*i];
				X[2*i]/=X[2*i+1];
			}
		for(i=1; i<(n+1)/2; i++)
			if(X[2*i-1]>X[2*i])
			{
				X[2*i-1]*=X[2*i];
				X[2*i]=X[2*i-1]/X[2*i];
				X[2*i-1]/=X[2*i];
			}*/
	}

	printf("Ordenados.\n");
	for(i=0; i<n; i++)
		printf("X[%ld] = %f\n", i+1, X[i]);
	return 0;
}
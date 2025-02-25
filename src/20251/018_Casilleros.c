#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000000
#define M 1000

int main(int argc, char *argv[])
{
	long int n, m, i, j, k, car[M], ind[M], ind2;
	float X[N], max, min, aux, rg[M], rng_int, Y[N];
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
	m = sqrt(n);
	printf("Casilleros: %ld\n", m);
	rng_int = ceil((max-min)/m);
	rg[0] = min;
	car[0] = 0;
	for(i=1; i<m+1; i++)
	{
		rg[i] = rg[i-1]+rng_int;
		car[i] = 0;
	}
	for(i=0; i<n; i++)
		car[(int)((X[i]-min)/rng_int)]++;
	ind[0]=0;
	for(i=1; i<m; i++)
		ind[i]=ind[i-1]+car[i-1];
	for(i=0; i<m; i++)
		printf("#[%f, %f) = %ld\t%ld\n", rg[i], rg[i+1], car[i], ind[i]);
	for(i=0; i<n; i++)
	{
		ind2 = (int)((X[i]-min)/rng_int);
		Y[ind[ind2]] = X[i];
		ind[ind2]++;
	}
	printf("Buket.\n");
	for(i=0; i<n; i++)
		printf("Y[%ld] = %f\n", i+1, Y[i]);
	for(k=0, ind2 = 0; k<m; k++)
	{
		for(i=ind2; i<(ind2+car[k]-1) ; i++)
			for(j=i+1; j<(ind2+car[k]); j++)
				if(Y[i]>Y[j])
				{
					Y[i]*=Y[j];
					Y[j]=Y[i]/Y[j];
					Y[i]/=Y[j];
				}
		ind2 += car[k];
	}


	printf("Ordenados.\n");
	for(i=0; i<n; i++)
		printf("Y[%ld] = %f\n", i+1, Y[i]);
	return 0;
}
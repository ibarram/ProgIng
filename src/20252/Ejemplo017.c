#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10000

int main(int argc, char*argv[])
{
	int i, j, k, l, n, nc, cs[N], id[N], ncs;
	float max, min, x[N], xs[N], aux, rng_c;
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
		cs[i] = 0;
		printf("X[%d] = %f\n", i+1, x[i]);
	}
	// Algoritmo de Bucket
	nc = 0;
	aux = n;
	while(aux>(2*nc+1))
	{
		aux -= (2*nc+1);
		nc++;
	}
	rng_c = (max-min)/nc;
	for(i=0; i<n; i++)
		cs[(int)((x[i]-min)/rng_c)]++;
	for(i=1, id[0]=0; i<n; i++)
		id[i] = id[i-1]+cs[i-1];
	for(i=0; i<n; i++)
	{
		ncs = (int)((x[i]-min)/rng_c);
		xs[id[ncs]] = x[i];
		id[ncs]++;
	}
	printf("%d\t%f\n", nc, rng_c);
	for(i=0; i<nc; i++)
		printf("CS[%d] = %d\n", i, cs[i]);
	for(i=0; i<nc; i++)
		printf("%f\t", min+rng_c*(i+1));
	printf("Pseudo-ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %f\t%d\t%f\n", i+1, x[i], (int)((x[i]-min)/rng_c), xs[i]);
	for(i=1, id[0]=0; i<n; i++)
		id[i] = id[i-1]+cs[i-1];
	for(l=0; l<nc; l++)
	{
		// Algoritmo de Seleccion
		for(i=id[l]; i<(id[l]+cs[l])-1; i++)
		{
			for(j=i+1, k=i; j<(id[l]+cs[l]); j++)
				if(xs[k]>xs[j])
					k = j;
			if(k!=i)
			{
				aux = xs[i];
				xs[i] = xs[k];
				xs[k] = aux;
			}
		}
	}
	printf("Ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, xs[i]);
	return 0;
}
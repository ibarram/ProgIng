#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000

int main(int argc, char *argv[])
{
	int i, j, k, n, n1, nc, cnc[N];
	float X[N], X1[N], max, min, aux, D;
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
	n1 = n;
	nc = 0;
	while(n1>0)
	{
		n1-=(2*nc+1);
		nc++;
	}
	for(i=0; i<nc; i++)
		cnc[i] = 0;
	D = (max-min)/nc;
	printf("Casilleros = %d\nDelta = %f\n", nc, D);
	for(i=0; i<n; i++)
		cnc[(int)((X[i]-min)/D)]++;
	for(i=1, cnc[nc] = 0, cnc[2*nc] = 0; i<nc; i++)
	{
		cnc[nc+i] = cnc[nc+i-1]+cnc[i-1];
		cnc[2*nc+i] = cnc[nc+i];
	}
	for(i=0; i<nc; i++)
		printf("[%f, %f] = #{%d}\t%d\n", min+i*D, min+(i+1)*D, cnc[i], cnc[i+nc]);
	for(i=0; i<n; i++)
	{
		j = (X[i]-min)/D;
		X1[cnc[j+nc]++] = X[i];
	}
	for(k=0; k<nc; k++)
	{
		for(i=cnc[k+2*nc]+1; i<(cnc[k+2*nc]+1+cnc[k]); i++)
		{
			aux = X1[i];
			j=i-1;
			while(aux<X1[j])
			{
				X1[j+1] = X1[j];
				j--;
				if(j<0)
					break;
			}
			X1[j+1] = aux;
		}
	}
	printf("Vector ordenado.\n");
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, X1[i]);
	return 0;
}
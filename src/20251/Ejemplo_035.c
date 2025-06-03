#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float sumar(float *X, int n)
{
	return n?X[0]+sumar(X+1,n-1):0;
}

float media(float *X, int n)
{
	return sumar(X, n)/n;
}

int main(void)
{
	int n, m, i;
	float *A;
	srand(time(NULL));
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1);
	do{
		printf("Ingrese el numero de muestras: ");
		scanf("%d", &m);
	}while(m<1||m>n);
	A = (float*)malloc(n*sizeof(float));
	if(A==NULL)
		return 1;
	for(i=0; i<n; i++)
	{
		A[i] = (1.0*rand())/RAND_MAX;
		printf("A[%d] = %f\t%p\n", i+1, A[i], A+i);
	}
	for(i=0; i<n-m; i++)
		printf("u(%d) = %f\n", i+1, media(A+i, m));
	free(A);
	return 0;
}

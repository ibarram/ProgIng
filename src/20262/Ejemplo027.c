#include <stdio.h>

#define N 10

int main(int argc, char *argv[])
{
	int n, i, j, k;
	float A[N][N], b[N], fct, x[N];
	do{
		printf("Ingrese el numero de ecuaciones: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%f", &A[i][j]);
		}
		printf("b[%d] = ", i+1);
		scanf("%f", &b[i]);
		x[i] = 0;
	}
	printf("\nEcuaciones:\n");
	for(i=0; i<n; i++)
	{
		printf("%.3fx1", A[i][0]);
		for(j=1; j<n; j++)
			printf("%+.3fx%d", A[i][j], j+1);
		printf("=%.3f\n", b[i]);
	}
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
		{
			for(k=0, fct=A[j][i]/A[i][i]; k<n; k++)
				A[j][k] -= (fct*A[i][k]);
			b[j] -= fct*b[i];
		}
	printf("\nTriangular superior\n");
	for(i=0; i<n; i++)
	{
		printf("%.3fx1", A[i][0]);
		for(j=1; j<n; j++)
			printf("%+.3fx%d", A[i][j], j+1);
		printf("=%.3f\n", b[i]);
	}
	for(i=n-1; i>-1; i--)
	{
		for(j=0, x[i]=b[i]; j<n; j++)
			x[i] -= (i!=j?x[j]*A[i][j]:0);
		x[i]/=A[i][i];
	}
	printf("\nSoluciones\n");
	for(i=0; i<n; i++)
		printf("x[%d] = %f\n", i+1, x[i]);
	return 0;
}
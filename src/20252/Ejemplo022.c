#include <stdio.h>

#define N 100

int main(int argc, char *argv[])
{
	int n, i, j, k;
	float A[N][N], b[N], fct, x[N];
	do{
		printf("Ingrese el numero de incognitas: ");
		scanf("%d", &n);
	}while(n<3||n>N);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%f", &(A[i][j]));
		}
		printf("b[%d] = ", i+1);
		scanf("%f", &b[i]);
		x[i] = 0;
	}
	for(i=0; i<n; i++)
	{
		printf("%.2fx1", A[i][0]);
		for(j=1; j<n; j++)
		{
			printf("%+.2fx%d", A[i][j], j+1);
		}
		printf("=%.2f\n", b[i]);
	}
	for(i=1; i<n; i++)
		for(j=i; j<n; j++)
		{
			for(k=0, fct=A[j][i-1]/A[i-1][i-1]; k<n; k++)
				A[j][k]-=(fct*A[i-1][k]);
			b[j]-=(fct*b[i-1]);
		}
	/*
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%.2f\t", A[i][j]);
		printf("%.2f\n", b[i]);
	}
	*/
	for(i=n-1; i>-1; i--)
	{
		x[i] = b[i];
		for(j=i+1; j<n; j++)
			x[i]-=A[i][j]*x[j];
		x[i]/=A[i][i];
	}
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, x[i]);
	return 0;
}
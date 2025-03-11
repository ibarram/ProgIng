#include <stdio.h>

#define NV 100

int main(int argc, char *argv[])
{
	int n, i, j, k;
	float A[NV][NV], b[NV], fct, x[NV];
	do{
		printf("Ingrese el numero de variables: ");
		scanf("%d", &n);
	}while(n<1||n>NV);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%f", &A[i][j]);
		}
		printf("b[%d] = ", i+1);
		scanf("%f", &b[i]);
	}
	printf("---\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%.2f\t", A[i][j]);
		printf("%.2f\n", b[i]);
	}
	for(i=1; i<n; i++)
	{
		fct = A[i][0]/A[0][0];
		for(j=0; j<n; j++)
			A[i][j]-=(fct*A[0][j]);
		b[i]-=fct*b[0];
	}
	printf("---\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%.2f\t", A[i][j]);
		printf("%.2f\n", b[i]);
	}
	for(i=2; i<n; i++)
	{
		fct = A[i][1]/A[1][1];
		for(j=0; j<n; j++)
			A[i][j]-=(fct*A[1][j]);
		b[i]-=fct*b[1];
	}
	printf("---\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%.2f\t", A[i][j]);
		printf("%.2f\n", b[i]);
	}
	for(i=0; i<n; i++)
		x[i] = 0;
	for(i=n-1; i>-1; i--)
	{
		x[i]=b[i];
		for(j=0; j<n; j++)
			if(i!=j)
				x[i]-=A[i][j]*x[j];
		x[i]/=A[i][i];
		printf("x[%d] = %f\n", i+1, x[i]);
	}
	return 0;
} 
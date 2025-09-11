#include<stdio.h>

#define N 100
#define M 100

int main(int argc, char *argv[])
{
	float A[N][M], B[N][M], C[N][M];
	int n, m, i, j;
	do{
		printf("Ingrese el numero de filas: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	do{
		printf("Ingrese el numero de columnas: ");
		scanf("%d", &m);
	}while(m<1||m>M);
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		{
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%f", &(A[i][j]));
		}
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		{
			printf("B[%d][%d] = ", i+1, j+1);
			scanf("%f", &(B[i][j]));
		}
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
			printf("C[%d][%d] = %f\n", i+1, j+1, C[i][j]);
		}
	return 0;
}
#include<stdio.h>

#define N 100
#define M 100

int main(int argc, char *argv[])
{
	float A[N][M], B[N][M], C[N][M];
	int nA, mA, nB, mB, i, j, k;
	do{
		printf("Ingrese el numero de filas de A: ");
		scanf("%d", &nA);
	}while(nA<1||nA>N);
	do{
		printf("Ingrese el numero de columnas de A: ");
		scanf("%d", &mA);
	}while(mA<1||mA>M);
	do{
		printf("Ingrese el numero de filas de B: ");
		scanf("%d", &nB);
	}while(nB!=mA);
	do{
		printf("Ingrese el numero de columnas de B: ");
		scanf("%d", &mB);
	}while(mB<1||mB>M);
	for(i=0; i<nA; i++)
		for(j=0; j<mA; j++)
		{
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%f", &(A[i][j]));
		}
	for(i=0; i<nB; i++)
		for(j=0; j<mB; j++)
		{
			printf("B[%d][%d] = ", i+1, j+1);
			scanf("%f", &(B[i][j]));
		}
	for(i=0; i<nA; i++)
		for(j=0; j<mB; j++)
		{
			for(k=0, C[i][j] = 0; k<mA; k++)
				C[i][j] += (A[i][k]*B[k][j]);
			printf("C[%d][%d] = %f\n", i+1, j+1, C[i][j]);
		}
	return 0;
}
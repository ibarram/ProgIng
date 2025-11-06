#include <stdio.h>
#include <stdlib.h>

double *crearMat(int r, int c)
{
	double *M;
	M = (double*)malloc(r*c*sizeof(double));
	if(M==NULL)
		return NULL;
	return M;
}

int capturar(double *M, int r, int c, char *str)
{
	int i, j;
	for(i=0; i<r; i++)
		for(j=0; j<c; j++)
		{
			printf("%s[%d][%d] = ", str, i+1, j+1);
			scanf("%lf", M+c*i+j);
		}
	return 0;
}

int imprimir(double *M, int r, int c)
{
	int i, j;
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
			printf("%.4lf\t", M[c*i+j]);
		printf("\n");
	}
	return 0;
}

double *multiplicar(double *M1, int r1, int c1, double *M2, int r2, int c2)
{
	int i, j, k;
	double *M3;
	if(c1!=r2)
	{
		printf("Error: En el tamaño de las matrices.\n");
		return NULL;
	}
	M3 = crearMat(r1, c2);
	if(M3==NULL)
		return NULL;
	for(i=0; i<r1; i++)
		for(j=0; j<c2; j++)
			for(k=0, M3[i*c1+j]=0; k<c1; k++)
				M3[i*c2+j] += M1[i*c1+k]*M2[k*c2+j];
//				M3[i][j] = M3[i][j]+M1[i][k]*M2[k][j]
//				M3[i][j] += M1[i][k]*M2[k][j]
//				M3[i*c2+j] += M1[i*c1+k]*M2[k*r2+j]
	return M3;
}

int main(int argc, char *argv[])
{
	int rA, rB, cA, cB;
	double *A, *B, *C;
	do{
		printf("Ingrese el numero de renglones de A: ");
		scanf("%d", &rA);
	}while(rA<1);
	do{
		printf("Ingrese el numero de columnas de A: ");
		scanf("%d", &cA);
	}while(cA<1);
	A = crearMat(rA, cA);
	if(A==NULL)
		return 1;
	capturar(A, rA, cA, "A");
	do{
		printf("Ingrese el numero de renglones de B: ");
		scanf("%d", &rB);
	}while(rB<1);
	do{
		printf("Ingrese el numero de columnas de B: ");
		scanf("%d", &cB);
	}while(cB<1);
	B = crearMat(rB, cB);
	if(B==NULL)
	{
		free(A);
		return 2;
	}
	capturar(B, rB, cB, "B");
	C = multiplicar(A, rA, cA, B, rB, cB);
	if(C==NULL)
	{
		free(A);
		free(B);
		return 4;
	}
	printf("A\n");
	imprimir(A, rA, cA);
	printf("B\n");
	imprimir(B, rB, cB);
	printf("C\n");
	imprimir(C, rA, cB);
	free(A);
	free(B);
	free(C);
	return 0;
}
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

double **crearMatC(int r, int c)
{
	double **M;
	int i;
	M = (double**)malloc(r*sizeof(double*));
	if(M==NULL)
		return NULL;
	M[0] = (double*)malloc(r*c*sizeof(double));
	if(M[0]==NULL)
	{
		free(M);
		return NULL;
	}
	for(i=1; i<r; i++)
		M[i] = M[i-1]+c;
	return M;
}

double **crearMatD(int r, int c)
{
	double **M;
	int i;
	M = (double**)malloc(r*sizeof(double*));
	if(M==NULL)
		return NULL;
	for(i=0; i<r; i++)
	{
		M[i] = (double*)malloc(c*sizeof(double));
		if(M[i]==NULL)
		{
			for(--i; i>-1; i--)
				free(M[i]);
			free(M);
			return NULL;
		}
	}
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

int imprimirM(double **M, int r, int c)
{
	int i, j;
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
			printf("%.4lf\t", M[i][j]);
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

double **multiplicarM(double **M1, int r1, int c1, double **M2, int r2, int c2)
{
	int i, j, k;
	double **M3;
	if(c1!=r2)
	{
		printf("Error: En el tamaño de las matrices.\n");
		return NULL;
	}
	M3 = crearMatC(r1, c2);
	if(M3==NULL)
		return NULL;
	for(i=0; i<r1; i++)
		for(j=0; j<c2; j++)
			for(k=0, M3[i][j]=0; k<c1; k++)
				M3[i][j] += M1[i][k]*M2[k][j];
	return M3;
}

int capturarM(double **M, int r, int c, char *str)
{
	int i, j;
	for(i=0; i<r; i++)
		for(j=0; j<c; j++)
		{
			printf("%s[%d][%d] = ", str, i+1, j+1);
			scanf("%lf", M[i]+j);
		}
	return 0;
}

int liberar(double **M, int r)
{
	int i;
	for(i=0; i<r; i++)
		free(M[i]);
	free(M);
	return 0;
}

int main(int argc, char *argv[])
{
	int rA, rB, cA, cB;
	double **A, **B, **C;
	do{
		printf("Ingrese el numero de renglones de A: ");
		scanf("%d", &rA);
	}while(rA<1);
	do{
		printf("Ingrese el numero de columnas de A: ");
		scanf("%d", &cA);
	}while(cA<1);
	A = crearMatC(rA, cA);
	if(A==NULL)
		return 1;
	capturarM(A, rA, cA, "A");
	do{
		printf("Ingrese el numero de renglones de B: ");
		scanf("%d", &rB);
	}while(rB<1);
	do{
		printf("Ingrese el numero de columnas de B: ");
		scanf("%d", &cB);
	}while(cB<1);
	B = crearMatD(rB, cB);
	if(B==NULL)
	{
		free(A[0]);
		free(A);
		return 2;
	}
	capturarM(B, rB, cB, "B");
	C = multiplicarM(A, rA, cA, B, rB, cB);
	if(C==NULL)
	{
		free(A[0]);
		free(A);
		liberar(B, rB);
		return 4;
	}
	printf("A\n");
	imprimirM(A, rA, cA);
	printf("B\n");
	imprimirM(B, rB, cB);
	printf("C\n");
	imprimirM(C, rA, cB);
	free(A[0]);
	free(A);
	liberar(B, rB);
	free(C);
	return 0;
}
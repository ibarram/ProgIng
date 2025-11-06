#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int r, c, i, j;
	double *A;
	do{
		printf("Ingrese el numero de renglones: ");
		scanf("%d", &r);
	}while(r<1);
	do{
		printf("Ingrese el numero de columnas: ");
		scanf("%d", &c);
	}while(c<1);
	A = (double*)malloc(r*c*sizeof(double));
	if(A==NULL)
		return 1;
	for(i=0; i<r; i++)
		for(j=0; j<c; j++)
		{
			printf("A[%d][%d] = ", i+1, j+1);
//			scanf("%lf", &A[c*i+j]);
//			scanf("%lf", &*(A+c*i+j));
			scanf("%lf", A+c*i+j);
		}
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
			printf("%.4lf\t", A[c*i+j]);
		printf("\n");
	}
	free(A);
	return 0;
}
#include <stdio.h>

#define Re 100
#define Co 100

int main(int argc, char *argv[])
{
	int rA, cA, rB, cB, i, j, k;
	float A[Re][Co], B[Re][Co], C[Re][Co];
	do{
		printf("Ingrese el numero de renglones de A: ");
		scanf("%d", &rA);
	}while(rA<1||rA>Re);
	do{
		printf("Ingrese el numero de columnas de A: ");
		scanf("%d", &cA);
	}while(cA<1||cA>Co);
	for(i=0; i<cA; i++)
		for(j=0; j<rA; j++)
		{
			printf("A[%d][%d] = ", i+1, j+1);
			while(!scanf("%f", &A[i][j]));
		}
	do{
		printf("Ingrese el numero de renglones de B: ");
		scanf("%d", &rB);
	}while(rB<1||rB>Re);
	do{
		printf("Ingrese el numero de columnas de B: ");
		scanf("%d", &cB);
	}while(cB<1||cB>Co);
	for(i=0; i<cB; i++)
		for(j=0; j<rB; j++)
		{
			printf("B[%d][%d] = ", i+1, j+1);
			while(!scanf("%f", &B[i][j]));
		}
	if(cA!=rB)
	{
		printf("Error: La multiplicacion no puede realizarse\n");
		return 1;
	}
	for(i=0; i<rA; i++)
		for(j=0; j<cB; j++)
			for(k=0, C[i][j]=0; k<cA; k++)
				C[i][j]+=A[i][k]*B[k][j];
	for(i=0; i<rA; i++)
		for(j=0; j<cB; j++)
			printf("C[%d][%d] = %f\n", i+1, j+1, C[i][j]);
	return 0;
}
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

	return 0;
}
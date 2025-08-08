#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	float **A, **B, **C, *pA, *pC;
	int nA, mA, nB, mB, i, j, k;
	do{
		printf("Ingrese el numero de columnas de A: ");
		scanf("%d", &nA);
		printf("Ingrese el numro de renglones de A: ");
		scanf("%d", &mA);
	}while(nA<1||mA<1);
	do{
		printf("Ingrese el numero de columnas de B: ");
		scanf("%d", &nB);
		printf("Ingrese el numro de renglones de B: ");
		scanf("%d", &mB);
	}while(nB<1||mB<1||nB!=mA);
	pA = (float*)malloc(nA*mA*sizeof(float));
	if(pA==NULL)
		return 1;
	A = (float**)malloc(nA*sizeof(float*));
	if(A==NULL)
	{
		free(pA);
		return 2;
	}
	for(i=0; i<nA; i++)
		A[0] = pA+i*mA;
	B = (float**)malloc(nB*sizeof(float*));
	if(B==NULL)
	{
		free(pA);
		free(A);
		return 3;
	}
	for(i=0; i<nB; i++)
	{
		B[i] = (float*)malloc(mB*sizeof(float));
		if(B[i]== NULL)
		{
			free(pA);
			free(A);
			for(--i; i>-1; i--)
				free(B[i]);
			free(B);
			return 4;
		}
	}
	free(B);
	free(pA);
	free(A);
	return 0;
}

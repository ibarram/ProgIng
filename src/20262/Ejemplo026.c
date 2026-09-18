#include <stdio.h>
#define N 10
#define M 10

int main(int argc, char *argv[])
{
	int n, m, i, j, op;
	float A[N][M], B[N][M], C[N][M];
	do{
		printf("Ingrese el numero de renglones: ");
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
	do{
		printf("MENU:\n0. Salir.\n1. Suma.\n2. Resta.\n3. Multiplicacion.\n4. Division.\n");
		scanf("%d", &op);
		for(i=0; i<n; i++)
			for(j=0; j<m; j++)
			{
				switch(op)
				{
				case 1:
					C[i][j] = A[i][j] + B[i][j];
					break;
				case 2:
					C[i][j] = A[i][j] - B[i][j];
					break;
				case 3:
					C[i][j] = A[i][j] * B[i][j];
					break;
				case 4:
					C[i][j] = A[i][j] / B[i][j];
					break;
				default:
					C[i][j] = 0;
				}
				printf("C[%d][%d] = %f\n", i+1, j+1, C[i][j]);
			}
	}while(op);
	return 0;
}
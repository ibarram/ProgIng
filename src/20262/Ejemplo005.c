#include<stdio.h>

int main(int argc, char *argv[])
{
	float T1, T2, T3, T4, T;
	int B;
	printf("Ingrese las temperaturas: ");
	scanf("%f %f %f %f", &T1, &T2, &T3, &T4);
	printf("Ingrese T: ");
	scanf("%f", &T);
	printf("%d\t%d\t%d\t%d\n", T>T4, T>T3, T>T2, T>T1);
	B = ((T>T4)<<3)|((T>T3)<<2)|((T>T2)<<1)|(T>T1);
	printf("%d\n", B);
	printf("La temperatura es ");
	switch(B)
	{
	case 0:
		printf("muy ");
	case 1:
		printf("baja");
		break;
	case 3:
		printf("templada");
		break;
	case 15:
		printf("muy ");
	default:
		printf("alta");
	}
	printf(".\n");
	return 0;
}
#include <stdio.h>

int main(int argc, char *argv[])
{
	float T1, T2, T3, T4, T;
	int B1, B2, B3, B4, B;
	printf("Ingrese los rangos de temperaturas: ");
	scanf("%f %f %f %f", &T1, &T2, &T3, &T4);
	printf("Ingrese la tempratura: ");
	scanf("%f", &T);
	B1 = T1>T;
	B2 = T2>T;
	B3 = T3>T;
	B4 = T4>T;
	B = B4<<3|B3<<2|B2<<1|B1;
	printf("%d (%d%d%d%d)\n", B, B4, B3, B2, B1);
	printf("La temperatura es ");
	switch(B)
	{
	case 15:
		printf("muy ");
	case 14:
		printf("baja\n");
		break;
	case 12:
		printf("templada\n");
		break;
	case 0:
		printf("muy ");
	case 8:
		printf("alta\n");
		break;
	default:
		break;
	}
	printf("\n");
	return 0;
}
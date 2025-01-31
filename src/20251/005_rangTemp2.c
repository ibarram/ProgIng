#include <stdio.h>

int main(int argc, char *argv[])
{
	float T1, T2, T3, T4, T;
	int B;
	printf("Ingrese los rangos de temperatura: ");
	scanf("%f %f %f %f", &T1, &T2, &T3, &T4);
	printf("Ingrese la temperatura: ");
	scanf("%f", &T);
	B = ((T4>T)<<3)|((T3>T)<<2)|((T2>T)<<1)|(T1>T);
	printf("%d\n", B);
	switch(B)
	{
	case 15:
		printf("Muy ");
	case 14:
		printf("Baja\n");
		break;
	case 12:
		printf("Templada\n");
		break;
	case 0:
		printf("Muy ");
	default:
		printf("Alta\n");
	}
	return 0;
}
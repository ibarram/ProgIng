#include<stdio.h>

int main(int argc, char *argv[])
{
	float T1, T2, T3, T4, T;
	int B;
	scanf("%f %f %f %f %f", &T1, &T2, &T3, &T4, &T);
	B = ((T4>T)<<3)|((T3>T)<<2)|((T2>T)<<1)|(T1>T);
	switch(B)
	{
	case 15:
		printf("Muy ");
	case 14:
		printf("Baja");
		break;
	case 12:
		printf("Templada");
		break;
	case 0:
		printf("Muy ");
	default:
		printf("Alta");
	}
	printf(".\n");
	return 0;
}
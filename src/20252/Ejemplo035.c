#include <stdio.h>

typedef struct{
	char a;
	int b;
	float c;
}dato_s;

typedef union{
	char a;
	int b;
	float c;
}dato_u;

int main(int argc, char *argv[])
{
	dato_s x;
	dato_u y;
	printf("Sizeof(char) = %ld\n", sizeof(char));
	printf("Sizeof(int) = %ld\n", sizeof(int));
	printf("Sizeof(float) = %ld\n", sizeof(float));
	printf("Sizeof(dato_s) = %ld\n", sizeof(x));
	printf("Sizeof(dato_u) = %ld\n", sizeof(y));
	x.a = 1;
	y.a = 1;
	printf("x.a = %d\n", x.a);
	printf("y.a = %d\n", y.a);
	x.b = 2;
	y.b = 2;
	printf("x.a = %d\n", x.a);
	printf("y.a = %d\n", y.a);
	printf("x.b = %d\n", x.b);
	printf("y.b = %d\n", y.b);
	return 0;
}
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	float a, b, c, x1r, x1i, x2r, x2i, r;
	printf("Ingrese el cuadratico: ");
	scanf("%f", &a);
	printf("Ingrese el lineal: ");
	scanf("%f", &b);
	printf("Ingrese el independiente: ");
	scanf("%f", &c);
	r = b*b-4*a*c;
	x1r = (-b+(r>=0?sqrt(r):0))/(2*a);
	x1i = r>=0?0:sqrt(-r)/(2*a);
	x2r = (-b+(r>=0?-sqrt(r):0))/(2*a);
	x2i = r>=0?0:-sqrt(-r)/(2*a);
	printf("X1 = %f%+fi\n", x1r, x1i);
	printf("X2 = %f%+fi\n", x2r, x2i);
	return 0;
}
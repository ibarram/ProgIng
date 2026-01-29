#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
	float a, b, c, r, x1r, x1i, x2r, x2i;
	printf("Ingrese el termino cuadratico: ");
	scanf("%f", &a);
	printf("Ingrese el termino lineal: ");
	scanf("%f", &b);
	printf("Ingrese el termino independiente: ");
	scanf("%f", &c);
	r = b*b-4*a*c;
	x1r = (-b+(r>=0?sqrt(r):0))/(2*a);
	x1i = (r>=0?0:sqrt(-r)/(2*a));
	x2r = (-b-(r>=0?sqrt(r):0))/(2*a);
	x2i = (r>=0?0:-x1i);
	printf("x1 = %.4f%+.4fi\n", x1r, x1i);
	printf("x2 = %.4f%+.4fi\n", x2r, x2i);
	return 0;
}
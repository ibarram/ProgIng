#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
	float a, b, c, r, x1r, x1i, x2r, x2i;
	printf("Coeficiente cuadratico = ");
	scanf("%f", &a);
	printf("Coeficiente lineal = ");
	scanf("%f", &b);
	printf("Coeficiente independiente = ");
	scanf("%f", &c);
	r = b*b-4*a*c;
	x1r = (-b+(r<0?0:sqrt(r)))/(2*a);
	x1i = r<0?sqrt(-r)/(2*a):0;
	x2r = (-b-(r<0?0:sqrt(r)))/(2*a);
	x2i = r<0?-sqrt(-r)/(2*a):0;
	printf("x1 = %f%+fi\n", x1r, x1i);
	printf("x2 = %f%+fi\n", x2r, x2i);
	return 0;
}
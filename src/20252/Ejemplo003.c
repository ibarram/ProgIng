#include<stdio.h>
#include<math.h>

int main(int argc, char*argv[])
{
	float a, b, c, x1r, x2r, x1i, x2i, r;
	printf("Ingrese el valor de a: ");
	scanf("%f", &a);
	printf("Ingrese el valor de b: ");
	scanf("%f", &b);
	printf("Ingrese el valor de c: ");
	scanf("%f", &c);
	r = b*b-4*a*c;
	x1r=(-b+(r>=0?sqrt(r):0))/(2*a);
	x2r=(-b-(r>=0?sqrt(r):0))/(2*a);
	x1i=(r>=0?0:sqrt(-r)/(2*a));
	x2i=-x1i;
	printf("x1=%.2f%+.2fi\n", x1r, x1i);
	printf("x2=%.2f%+.2fi\n", x2r, x2i);
	return 0;
}
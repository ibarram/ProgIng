#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, n, s;
	long den;
	float x, sx, num;
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	for(i=0, num=x, den=1, sx=0; i<n; i++)
	{
		s = 1-2*(i%2);
		sx += (s*num/den);
		//printf("%d. %d %f %ld %f\n", i, s, num, den, sx);
		num*=(x*x);
		den*=((2*i+2)*(2*i+3));
	}
	printf("sin(%f) = %f\n", x, sx);
	return 0;
}
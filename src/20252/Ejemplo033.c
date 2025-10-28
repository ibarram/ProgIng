#include <stdio.h>
#include <stdlib.h>

#define N 1000

float validar2(float a, float min, float max, char *str)
{
	if(a>min&&a<max)
		return a;
	printf("Ingrese el valor de %s: ", str);
	scanf("%f", &a);
	if(a>min&&a<max)
		return a;
	else
		return validar2(a, min, max, str);
}

float validar(float min, float max, char *str)
{
	float a;
	printf("Ingrese el valor de %s: ", str);
	scanf("%f", &a);
	if(a>min&&a<max)
		return a;
	else
		return validar(min, max, str);
}

float asen(float x, int n)
{
	int i;
	float asx, fct;
	for(i=0, asx=0, fct=x; i<n; i++)
	{
		asx+=fct;
		fct*=((2*i+1)*x*x/(2*i+3));
		fct*=((2*i+1.0)/(2*(i+1)));
	}
	return asx;
}

int main(int argc, char *argv[])
{
	int n=0;
	float x=-1, asx;
	if(argc==3)
		x = atof(argv[2]);
	if(argc&2)
		n = atoi(argv[1]);
	n = (int)validar2(n, 1, N, "n");
	x = validar2(x, -1, 1, "x");
	asx = asen(x, n);
	printf("asen(%f) = %f\n", x, asx);
	return 0;
}
#include <stdio.h>

double exp1(double x, int n);
double exp3(double x, int n);
double exp4(double x, int n);
double exp5(double x, int n);
double potencia(double x, int n);
long int factorial(int n);
double potencia2(double x, int n);
long int factorial2(int n);
double fct(double x, int n);

int main(int argc, char *argv[])
{
	double x, ex, ex2, ex3, ex4;
	int n;
	printf("Ingrese el valor de x: ");
	scanf("%lf", &x);
	do{
		printf("Ingrese le numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	ex = exp1(x, n);
	ex2 = exp3(x, n);
	ex3 = exp4(x, n);
	ex4 = exp5(x, n);
	printf("exp(%lf) = %lf\n", x, ex);
	printf("exp(%lf) = %lf\n", x, ex2);
	printf("exp(%lf) = %lf\n", x, ex3);
	printf("exp(%lf) = %lf\n", x, ex4);
	return 0;
}

double fct(double x, int n)
{
	if(n!=1)
		return fct(x, n-1)*(x/n);
	else
		return x;
}

double exp5(double x, int n)
{
	if(n)
		return exp5(x, n-1)+fct(x, n);
	else
		return 1;
}

double exp3(double x, int n)
{
	int i;
	double ex, fct;
	for(i=0, ex=0, fct=1; i<n; i++)
	{
		ex += fct;
		fct *= x/(i+1);
	}
	return ex;
}

double exp1(double x, int n)
{
	int i;
	double ex;
	for(i=0, ex=0; i<n; i++)
		ex += potencia(x, i)/factorial(i);
	return ex;
}

double potencia(double x, int n)
{
	int i;
	double xn;
	for(i=0, xn=1; i<n; i++)
		xn *= x;
	return xn;
}

long int factorial(int n)
{
	int i;
	long int fn;
	for(i=0, fn=1; i<n; i++)
		fn *= (i+1);
	return fn;
}

double exp4(double x, int n)
{
	if(n>0)
		return exp4(x, n-1)+potencia2(x,n)/factorial2(n);
	else
		return 1;
}

double potencia2(double x, int n)
{
	if(n>0)
		return potencia2(x, n-1)*x;
	else
		return 1;
}

long int factorial2(int n)
{
	if(n>0)
		return factorial2(n-1)*n;
	else
		return 1;
}
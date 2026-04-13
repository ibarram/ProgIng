#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 10000

int main(int argc, char *argv[])
{
	float x[N], z[N], mx_X, mn_X, min, max, media, varianza, a, b;
	int i, n, bandera, op1, op2, op3;
	srand((unsigned int)time(NULL));
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	printf("Ingrese el valor maximo: ");
	scanf("%f", &mx_X);
	printf("Ingrese el valor minimo: ");
	scanf("%f", &mn_X);
	if(mx_X<mn_X)
	{
		if(mx_X&&mn_X)
		{
			mx_X *= mn_X;
			mn_X = mx_X/mn_X;
			mx_X /= mn_X;
		}
		else if(mx_X)
		{
			mn_X = mx_X;
			mx_X = 0;
		}
		else if(mn_X)
		{
			mx_X = mn_X;
			mn_X = 0;
		}
		else
			mx_X = mn_X + 1;
	}
	printf("¿Quieres centrar?: ");
	scanf("%d", &op1);
	printf("¿Quieres normalizar?: ");
	scanf("%d", &op2);
	if(op1||op2)
	{
		printf("Menu:\n");
		printf("1. Maximo-Minimo.\n");
		printf("2. z-score.\n");
		printf("Opción: ");
		scanf("%d", &op3);
	}
	switch(8*op1+4*op2+op3)
	{
	case 5:
		bandera = 2;
		break;
	case 6:
		bandera = 8;
		break;
	case 9:
		bandera = 1;
		break;
	case 10:
		bandera = 4;
		break;
	case 13:
		bandera = 3;
		break;
	case 14:
		bandera = 12;
		break;
	default:
		bandera = 0;
	}
	for(i=0; i<n; i++)
		x[i] = (((mx_X-mn_X)*rand())/RAND_MAX)+mn_X;
	for(i=1, max=x[0], min=x[0]; i<n; i++)
	{
		if(max<x[i])
			max = x[i];
		if(min>x[i])
			min = x[i];
	}
	for(i=1, media=x[0], varianza=x[0]*x[0]; i<n; i++)
	{
		media += x[i];
		varianza += (x[i]*x[i]);
	}
	media /= n;
	varianza /= n;
	varianza -= (media*media);
	if(bandera&1)
		a = min;
	else if(bandera&4)
		a = media;
	else
		a = 0;
	if(bandera&2)
		b = max-min;
	else if(bandera&8)
		b = sqrt(varianza);
	else
		b = 1;
	for(i=0; i<n; i++)
		z[i] = (x[i]-a)/b;
	printf("Maximo: %f\n", max);
	printf("Minimo: %f\n", min);
	printf("Media: %f\n", media);
	printf("Varianza: %f\n", varianza);
	for(i=0; i<n; i++)
		printf("%d\t%f\t%f\n", i+1, x[i], z[i]);
	return 0;
}
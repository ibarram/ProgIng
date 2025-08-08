#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 60
#define min 1.5
#define max 2.1

int main(int argc, char *argv[])
{
	float X[N];
	float med, var;
	int i, n;
	srand(time(NULL));
	do{
		printf("Ingrese el numero de estudiantes: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	for(i=0, med=0, var=0; i<n; i++)
	{
		X[i] = (max-min)*rand()/RAND_MAX+min;
		med += X[i];
		var += (X[i]*X[i]);
		printf("X[%d] = %.3f\n", i+1, X[i]);
	}
	med /= n;
	var /= n;
	var -= (med*med);
	printf("Media = %.3f\n", med);
	printf("Varianza = %.3f\n", var);
	return 0;
}
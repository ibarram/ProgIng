#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	double *x, m;
	int n, i;
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1);
	x = (double*)malloc(n*sizeof(double));
	if(x==NULL)
		return 1;
	for(i=0, m=0; i<n; i++)
	{
		printf("x[%d] = ", i+1);
		scanf("%lf", x+i);
		m += x[i];
	}
	m/=n;
	printf("Media = %lf\n", m);
	free(x);
	return 0;
}
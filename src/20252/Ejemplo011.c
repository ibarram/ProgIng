#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char*argv[])
{
	int i, n, max, min, x, aux;
	srand(time(NULL));
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Ingrese el valor maximo: ");
	scanf("%d", &max);
	printf("Ingrese el valor minimo: ");
	scanf("%d", &min);
	if(min>max)
	{
		aux = max;
		max = min;
		min = aux;
	}
	for(i=0; i<n; i++)
	{
		x = rand()%(max-min+1)+min;
		printf("%d. %d\n", i+1, x);
	}
	return 0;
}
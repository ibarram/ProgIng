#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char*argv[])
{
	int i, n;
	float max, min, x;
	srand(time(NULL));
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Ingrese el valor maximo: ");
	scanf("%f", &max);
	printf("Ingrese el valor minimo: ");
	scanf("%f", &min);
	if(min>max)
	{
		if(max)
		{
			if(min)
			{
				min*=max;
				max=min/max;
				min/=max;
			}
			else
			{
				min = max;
				max = 0;
			}
		}
		else
		{
			max = min;
			min = 0;
		}
	}
	for(i=0; i<n; i++)
	{
		x = ((max-min)*rand())/RAND_MAX+min;
		printf("%d. %f\n", i+1, x);
	}
	return 0;
}
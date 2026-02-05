#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, rn, i;
	do{
		printf("Ingrese el valor de n: ");
		scanf("%d", &n);
	}while(n<=0);
	rn = n;
	i = 0;
	while(rn>0)
	{
		rn -= (2*i+1);
		i++;
	}
	printf("%d^2 = %d\n", i, n);
	return 0;
}
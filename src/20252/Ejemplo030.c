#include <stdio.h>

int buscar(int n)
{
	return n%2?n:buscar(n/2);
}

int main(int argc, char *argv[])
{
	int n, a, b, i, j, x;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d %d", &a, &b);
		for(j=a, x=0; j<=b; j++)
		{
			printf("%d (%d)\t", j, buscar(j));
			x += buscar(j);
		}
		printf("%d\n", x);
	}
	return 0;
}
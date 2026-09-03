#include<stdio.h>
#include<stdlib.h>
#define N 10

int main(int argc, char *argv[])
{
	int i, X[N];
	srand(321);
	for(i=0; i<N; i++)
	{
		X[i] = rand();
		printf("X[%d] = %d\n", i+1, X[i]);
	}
	return 0;
}
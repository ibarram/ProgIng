#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define max 20
#define min -10

int main(int argc, char *argv[])
{
	int A[N], i;
	float X[N];
	srand(time(NULL));
	for(i=0; i<N; i++)
	{
		A[i] = rand()%(max-min)+min;
		X[i] = (max-min)*((float)rand())/RAND_MAX+min;
		printf("A[%d] = %d\n", i, A[i]);
		printf("X[%d] = %f\n", i, X[i]);
	}
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

int main(int argc, char *argv[])
{
	int i;
	float X[N];
	srand((unsigned)time(NULL));
	for(i=0; i<N; i++)
	{
		X[i] = (((float)rand())/RAND_MAX);
		printf("X[%d] = %f\n", i+1, X[i]);
	}
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

int main(int argc, char *argv[])
{
	int i, X[N], mx=6, mn=1, rg = mx-mn+1;
	srand((unsigned)time(NULL));
	for(i=0; i<N; i++)
	{
		X[i] = (rand()%rg)+mn;
		printf("X[%d] = %d\n", i+1, X[i]);
	}
	return 0;
}
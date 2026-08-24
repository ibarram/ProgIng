#include <stdio.h>

int main(int argc, char *argv[])
{
	int N, R, K, Rmin, Rmax;
	scanf("%d %d %d", &N, &R, &K);
	Rmin = (2*(R>=K)-1)*(R-K);
	Rmax = ((N-R)<K)*(2*N)+(2*((N-R)>=K)-1)*(R+K);
	printf("%d %d\n", Rmin, Rmax);
	return 0;
}
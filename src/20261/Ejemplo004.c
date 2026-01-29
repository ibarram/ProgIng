#include <stdio.h>

int main(int argc, char *argv[])
{
	int N, R, K, Rmn, Rmx;
	scanf("%d %d %d", &N, &R, &K);
	Rmn = (2*(R>=K)-1)*(R-K);
	Rmx = ((N-R)<K)*2*N+(2*((N-R)>=K)-1)*(R+K);
	printf("%d\t%d\n", Rmn, Rmx);
}
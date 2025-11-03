#include <stdio.h>

int main(int argc, char *argv[])
{
	int x, *px;
	char *py;
	double *pz;
	x = 20;
	px = &x;
	py = (char*)&x;
	pz = (double*)&x;
	printf("x = %d\n", x);
	printf("&x = %p\n", &x);
	printf("px = %p\n", px);
	printf("*px = %d\n", *px);
	printf("px = %p\n", px);
	printf("py = %p\n", py);
	printf("pz = %p\n", pz);
	printf("px = %p (%ld)\n", px+1, sizeof(int));
	printf("py = %p (%ld)\n", py+1, sizeof(char));
	printf("pz = %p (%ld)\n", pz+1, sizeof(double));
	(*px)++;
	printf("x = %d\n", x);
	printf("px = %p\n", px);
	(*py)++;
	printf("x = %d\n", x);
	printf("py = %p\n", py);
	py++;
	(*py)++;
	printf("x = %d\n", x);
	printf("py = %p\n", py);
	(*py)++;
	printf("x = %d\n", x);
	printf("py = %p\n", py);
	py++;
	(*py)++;
	printf("x = %d\n", x);
	printf("py = %p\n", py);
	return 0;
}
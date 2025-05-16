#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int i, a, b, s;
	if(argc!=3)
	{
		printf("Uso: %s A B\n", argv[0]);
		return 1;
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	s = a + b;
	printf("%d%+d=%d\n", a, b, s);
	return 0;
}
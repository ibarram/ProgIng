#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 10, b = -250, n = 4;
	printf("%d\t%d\n", a, b);
	printf("%+d\t%+d\n", a, b);
	printf("%05d\t%05d\n", a, b);
	printf("%0*d\t%0*d\n", 5, a, 5, b);
	printf("%0*d\t%0*d\n", n, a, n, b);
	return 0;
}

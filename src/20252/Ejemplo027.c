#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, a, ai, b, m, c, mr, i;
	printf("n = ");
	scanf("%d", &n);
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	for(i=0; i<n; i++)
		if(((a*i)%n)==1)
		{
			ai = i;
			printf("ai = %d\n", ai);
		}
	printf("m = ");
	scanf("%d", &m);
	c = (a*m+b)%n;
	printf("c = %d\n", c);
	if(c>=b)
		mr = c-b;
	else
		mr = n+c-b;
	mr = (ai*mr)%n;
	printf("m = %d\n", mr);
	return 0;
}
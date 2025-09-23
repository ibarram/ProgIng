#include <stdio.h>

#define	BIT(n)				(1<<(n))
#define	BIT_GET(x,n)		((x) & BIT(n))
#define	BIT_SET(x,n)		((x) |= BIT(n))
#define	BIT_CLEAR(x,n)		((x) &= ~BIT(n))
#define	BIT_TOGGLE(x,n)		((x) ^= BIT(n))
#define	BIT_WRITE(x,n,v)	((v)?BIT_SET(x,n):BIT_CLEAR(x,n))
#define	ES_PAR(x)			(!BIT_GET(x,0))

int main(int argc, char *argv[])
{
	int x, nb, i;
	printf("x = ");
	scanf("%d", &x);
	printf("b = ");
	scanf("%d", &nb);
	for(i=7; i>-1; i--)
		printf("%d", BIT_GET(x,i)?1:0);
	printf("\n");
	BIT_SET(x, nb);
	printf("%d\n", x);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define	BIT(n)				(1<<(n))
#define	BIT_GET(x,n)		((x) & BIT(n))
#define	BIT_SET(x,n)		((x) |= BIT(n))
#define	BIT_CLEAR(x,n)		((x) &= ~BIT(n))
#define	BIT_TOGGLE(x,n)		((x) ^= BIT(n))
#define	BIT_WRITE(x,n,v)	((v)?BIT_SET(x,n):BIT_CLEAR(x,n))

int main(int argc, char *argv[])
{
	int x, i, n, nb, v;
	n = 8*sizeof(x);
	printf("X = ");
	scanf("%d", &x);
	for(i=n-1; i>-1; i--)
		printf("%d ", BIT_GET(x, i)?1:0);
	printf("\n");
	printf("Bit set.\n");
	printf("Numero de bit: ");
	scanf("%d", &nb);
	BIT_SET(x,nb);
	for(i=n-1; i>-1; i--)
		printf("%d ", BIT_GET(x, i)?1:0);
	printf("\n");
	printf("x = %d\n", x);
	printf("Bit clear.\n");
	printf("Numero de bit: ");
	scanf("%d", &nb);
	BIT_CLEAR(x,nb);
	for(i=n-1; i>-1; i--)
		printf("%d ", BIT_GET(x, i)?1:0);
	printf("\n");
	printf("x = %d\n", x);
	printf("Bit toggle.\n");
	printf("Numero de bit: ");
	scanf("%d", &nb);
	BIT_TOGGLE(x,nb);
	for(i=n-1; i>-1; i--)
		printf("%d ", BIT_GET(x, i)?1:0);
	printf("\n");
	printf("x = %d\n", x);
	printf("Bit write.\n");
	printf("Numero de bit: ");
	scanf("%d", &nb);
	printf("Valor del bit: ");
	scanf("%d", &v);
	BIT_WRITE(x,nb,v);
	for(i=n-1; i>-1; i--)
		printf("%d ", BIT_GET(x, i)?1:0);
	printf("\n");
	printf("x = %d\n", x);
	return 0;
}
#include <stdio.h>

#define BIT(n)				(1<<(n))
#define BIT_GET(x,n)		((x)&BIT(n))
#define BIT_SET(x,n)		((x) |= BIT(n))
#define BIT_CLEAR(x,n)		((x) &= ~BIT(n))
#define BIT_TOGGLE(x,n)		((x) ^= BIT(n))
#define BIT_WRITE(x,n,v)	((v)?BIT_SET(x,n):BIT_CLEAR(x,n))

int main(int argc, char *argv[])
{
	int i, n, nb;
	int xi;
	char x, xb;
	printf("x = ");
	scanf("%d", &xi);
	x = (char)xi;
	n = 8*sizeof(x);
	for(i=n; i>0; i--)
		printf("%d", BIT_GET(x,i-1)?1:0);
	printf("\n");
	do{
		printf("Ingrese el numero de bit: ");
		scanf("%d", &nb);
	}while(nb<-1|nb>=n);
	printf("%d\n", BIT_SET(x, nb));
	do{
		printf("Ingrese el numero de bit: ");
		scanf("%d", &nb);
	}while(nb<-1|nb>=n);
	printf("%d\n", BIT_CLEAR(x, nb));
	do{
		printf("Ingrese el numero de bit: ");
		scanf("%d", &nb);
	}while(nb<-1|nb>=n);
	printf("%d\n", BIT_TOGGLE(x, nb));
	do{
		printf("Ingrese el numero de bit: ");
		scanf("%d", &nb);
	}while(nb<-1|nb>=n);
	printf("Ingrese el valor del bit: ");
	scanf("%d", &xi);
	xb = (char)xi;
	printf("%d\n", BIT_WRITE(x, nb, xb));	
	return 0;
}

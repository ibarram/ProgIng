#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	BIT(n)				(1<<(n))
#define	BIT_GET(x,n)		((x) & BIT(n))
#define	BIT_SET(x,n)		((x) |= BIT(n))
#define	BIT_CLEAR(x,n)		((x) &= ~BIT(n))
#define	BIT_TOGGLE(x,n)		((x) ^= BIT(n))
#define	BIT_WRITE(x,n,v)	((v)?BIT_SET(x,n):BIT_CLEAR(x,n))
#define	ES_PAR(x)			(!BIT_GET(x,0))
#define N 50

int main(int argc, char *argv[])
{
	char str[N], c, p, v;
	int i, nc, cc, cb;
	srand(time(NULL));
	i = 0;
	do{
		c = getchar();
		str[i] = c;
		i++;
	}while(c!=10&&i<(N-1));
	nc = i-1;
	str[nc] = '\0';
	p = 0;
	i = 0;
	while(str[i]!='\0')
	{
		p^=str[i];
		i++;
	}
	printf("%s (%d)\n", str, p);
	cc = (rand()%nc);
	cb = (rand()%8);
	BIT_TOGGLE(str[cc],cb);
	v = p;
	i = 0;
	while(str[i]!='\0')
	{
		v^=str[i];
		i++;
	}
	printf("%s (%d, %d, %d)\n", str, v, cc, cb);
	return 0;
}
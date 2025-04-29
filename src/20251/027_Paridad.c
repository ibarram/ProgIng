#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	BIT(n)			(1<<(n))
#define	BIT_TOGGLE(x,n)	((x) ^= BIT(n))
#define NC 				100

int main(int argc, char *argv[])
{
	char msg[NC+1], p, v;
	int i, nc, _nc, _nb;
	srand(time(NULL));
	i=0;
	do{
		msg[i++] = getc(stdin);
	}while(msg[i-1]!=10&&i<NC);
	nc = i-1;
	msg[nc] = '\0';
	for(i=0, p=0; i<nc; i++)
		p^=msg[i];
	for(i=0, v=p; i<nc; i++)
		v^=msg[i];
	printf("MSG: %s(%d)-%c-%d\n", msg, nc, p, (int )v);
	_nc = rand()%nc;
	_nb = rand()%(8*sizeof(char));
	BIT_TOGGLE(msg[_nc], _nb);
	for(i=0, v=p; i<nc; i++)
		v^=msg[i];
	printf("MSG: %s(%d)-%c-%u\n", msg, nc, p, (unsigned int)v);
	return 0;
}
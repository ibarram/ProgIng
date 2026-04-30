#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define	BIT(n)				(1<<(n))
#define	BIT_GET(x,n)		((x) & BIT(n))
#define	BIT_TOGGLE(x,n)		((x) ^= BIT(n))

int main(int argc, char *argv[])
{
	char msg[N], P, V;
	int i, n, nc, nb;
	srand(time(NULL));
	i = 0;
	do{
		msg[i] = getchar();
		i++;
	}while(i<N&&msg[i-1]!=10);
	msg[i-1] = '\0';
	n = i-1;
	for(i=0, P=0; i<n; i++)
		P^=msg[i];
	printf("MSG: %s\n", msg);
	printf("Paridad: %c (", P);
	for(i=7; i>-1; i--)
		printf("%d ", BIT_GET(P, i)?1:0);
	printf(")\n");
	nc = rand()%n;
	nb = rand()%8;
	printf("NC = %d\tNB = %d\n", nc, nb);
	BIT_TOGGLE(msg[nc], nb);
	printf("MSG: %s\n", msg);
	for(i=0, V=P; i<n; i++)
		V^=msg[i];
	printf("Validacion: %c (", V);
	for(i=7; i>-1; i--)
		printf("%d ", BIT_GET(V, i)?1:0);
	printf(")\n");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100
#define P 7
#define	BIT(n)				(1<<(n))
#define	BIT_GET(x,n)		((x) & BIT(n))
#define	BIT_TOGGLE(x,n)		((x) ^= BIT(n))

int main(int argc, char *argv[])
{
	char msg[N], msgP[N+P], msgV[N];
	int i, j, n, np, nc, nb, l2;
	float l2f;
	srand(time(NULL));
	i = 0;
	do{
		msg[i] = getchar();
		i++;
	}while(i<N&&msg[i-1]!=10);
	msg[i-1] = '\0';
	n = i-1;
	np = log2(n+log2(n)+1)+1;
	printf("n = %d\tnp = %d\n", n, np);
	printf("MSG: %s\n", msg);
	for(i=0; i<(n+np); i++)
	{
		l2f = log2(i+1);
		l2 = l2f;
		if(l2f==l2)
			msgP[i] = 0;
		else
			msgP[i] = msg[i-l2-1];
	}
	for(i=0; i<(n+np); i++)
	{
		l2f = log2(i+1);
		l2 = l2f;
		if(l2f==l2)
		{
			for(j=i; j<(n+np); j++)
				if((j+1)%2)
					printf("%c", msgP[j]);
		}
	}
	printf("\n");
	/*
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
	printf(")\n");*/
	return 0;
}
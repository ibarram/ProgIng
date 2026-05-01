#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100
#define P 7
#define	BIT(n)				(1<<(n))
#define	BIT_GET(x,n)		((x) & BIT(n))
#define	BIT_SET(x,n)		((x) |= BIT(n))
#define	BIT_TOGGLE(x,n)		((x) ^= BIT(n))

int main(int argc, char *argv[])
{
	char msg[N], msgP[N+P], V[P], msgV[N];
	int i, j, k, n, np, nc, nb, l2, ncv, nbv;
	float l2f, aux;
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
	for(i=0; i<np; i++)
	{
		j = (1<<i)-1;
		for(k=j; k<(n+np); k++)
			if(((k-j)/(j+1)+1)%2)
				msgP[j]^=msgP[k];
	}
	msgP[n+np] = '\0';
	printf("MSG_P: %s\n", msgP);
	nc = rand()%(n+np);
	nb = rand()%8;
	printf("NC = %d\tNB = %d\n", nc, nb);
	BIT_TOGGLE(msgP[nc], nb);
	printf("MSG_E: %s\n", msgP);
	for(i=0; i<np; i++)
	{
		j = (1<<i)-1;
		for(k=j+1, V[j]=msgP[j]; k<(n+np); k++)
		{
			if(((k-j)/(j+1)+1)%2)
				V[j]^=msgP[k];
		}
		printf("P_%d = %d\n", i, V[j]);
	}
	for(i=0, ncv=0, nbv=0; i<np; i++)
		if(V[i])
		{
			BIT_SET(ncv, i);
			if(!nbv)
				nbv = (int)V[i];
			printf("%d\t%d\t%d\n", i, V[i], nbv);
		}
	ncv--;
	printf("%d\t", nbv);
	aux = log2(nbv);
	nbv = aux;
	printf("%d\t%f\n", nbv, aux);
	printf("NC_V = %d\tNB_V = %d\n", ncv, nbv);
	/*
	for(i=0, V=P; i<n; i++)
		V^=msgP[i];
	printf("Validacion: %c (", V);
	for(i=7; i>-1; i--)
		printf("%d ", BIT_GET(V, i)?1:0);
	printf(")\n");*/
	return 0;
}
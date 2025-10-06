#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define	BIT(n)				(1<<(n))
#define	BIT_GET(x,n)		((x) & BIT(n))
#define	BIT_SET(x,n)		((x) |= BIT(n))
#define	BIT_CLEAR(x,n)		((x) &= ~BIT(n))
#define	BIT_TOGGLE(x,n)		((x) ^= BIT(n))
#define	BIT_WRITE(x,n,v)	((v)?BIT_SET(x,n):BIT_CLEAR(x,n))
#define	ES_PAR(x)			(!BIT_GET(x,0))
#define N 					50

int main(int argc, char *argv[])
{
	char str[N], strP[N], strR[N], c, p, v;
	int i, j, k, l, nc, cc, cb, np, p2, p2f, cc2, cb2;
	srand(time(NULL));
	i = 0;
	do{
		c = getchar();
		str[i] = c;
		i++;
	}while(c!=10&&i<(N-1));
	nc = i-1;
	str[nc] = '\0';
	np = (int)(log2(nc+log2(nc)+1)+1);
	printf("NP = %d\n", np);
	printf("%s (%d, %d)\n", str, nc, np);
	for(i=0, j=0, p2=1; i<(nc+np); i++)
	{
		if((i+1)==p2)
		{
			strP[i] = 0;
			p2<<=1;
		}
		else
		{
			c = str[j++];
			strP[i] = c;
			for(k=0, p2f=1; k<np; k++)
			{
				if(p2f&(i+1))
					strP[p2f-1]^=c;
				p2f<<=1;
			}
		}
	}
	strP[nc+np] = '\0';
	cc = rand()%(nc+np);
	cb = rand()%8;
	BIT_TOGGLE(strP[cc],cb);
	printf("%s\n", strP);
	for(i=0, j=0, l=0, p2=1; i<(nc+np); i++)
	{
		if((i+1)==p2)
		{
			strR[nc+1+l] = strP[i];
			l++;
			p2 <<= 1;
		}
		else
		{
			c = strP[i];
			strR[j++] = c;
			for(k=0, p2f=1; k<np; k++)
			{
				if(p2f&(i+1))
					strR[nc+1+k]^=c;
				p2f<<=1;
			}
		}
	}
	strR[nc] = '\0';
	strR[nc+np+1] = '\0';
	printf("%s (%d, %d)\n", strR, cc, cb);
	for(i=0, cc2=0; i<np; i++)
	{
		printf("%d\t", strR[nc+1+i]);
		BIT_WRITE(cc2,i,strR[nc+1+i]);
		if(strR[nc+1+i])
			cb2 = log2(strR[nc+1+i]);
	}
	printf("(%d, %d)\n", cc2-1, cb2);
	BIT_TOGGLE(strP[cc2-1],cb2);
	printf("%s\n", strP);
	return 0;
}
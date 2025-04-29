#include <stdio.h>
#include <math.h>

#define MC 2048
#define l2 log(2)

int main(int argc, char *argv[])
{
	char str[MC], strP[MC];
	int i, j, k, nc, nP;
	i=0;
	do{
		str[i++] = getc(stdin);
	}while(str[i-1]!=10);
	str[i-1] = '\0';
	nc = i-1;
	nP = log(nc+log(nc)/l2+1)/l2+1;
	printf("%s(%d, %d)\n", str, nc, nP);
	for(i=0, j=1, k=0; i<nc+nP; i++)
	{
		if((i+1)!=j)
			strP[i] = str[k++];
		else
		{
			strP[i] = 0;
			j<<=1;
		}
	}
	for(i=0, j=1; i<nP; i++)
	{
		for(k=j; k<=(nc+nP); k++)
			if(((k-j)%(2*j))<j)
				strP[j-1]^=strP[k-1];
//			printf("%d\t", ((k-j)%(2*j))<j);
//		printf("\n");
		j<<=1;
	}
	strP[nc+nP] = '\0';
	for(i=0; i<nc+nP; i++)
		printf("%d\n", strP[i]);
	printf("%s\n", strP);
	return 0;
}
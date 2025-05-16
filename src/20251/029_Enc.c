#include <stdio.h>

#define MC 2048

int main(int argc, char *argv[])
{
	char str[MC], strE[MC], strD[MC], aux[MC];
	int i, nc, a, ai, b, n;
	a = 17;
//	ai = 49;
	b = 21;
	n = 52;
	i=0;
	do{
		str[i++] = getc(stdin);
	}while(str[i-1]!=10);
	str[i-1] = '\0';
	nc = i-1;
	printf("MSG: %s\n", str);
	for(i=0; i<nc; i++)
		printf("%d ", str[i]);
	printf("\n");
	for(i=0; i<nc; i++)
	{
		aux[i] = str[i]-'A'-6*(str[i]>='a');
		printf("%d ", aux[i]);
	}
	printf("\n");
	for(i=0; i<nc; i++)
	{
		aux[i] = (a*((int)aux[i])+b)%n;
		printf("%d ", aux[i]);
	}
	printf("\n");
	for(i=0; i<nc; i++)
		strE[i] = aux[i]+'A'+6*(aux[i]>(n/2-1));
	strE[nc]='\0';
	printf("%s\n", strE);
	for(i=0; i<nc; i++)
	{
		aux[i] = strE[i]-'A'-6*(strE[i]>='a');
		printf("%d ", aux[i]);
	}
	printf("\n");
	ai=1;
	while(((ai*a)%n)!=1)
		ai++;
	printf("ai = %d\n", ai);
	for(i=0; i<nc; i++)
	{
		aux[i] = (ai*((aux[i]<b)*n+aux[i]-b))%n;
		printf("%d ", aux[i]);
	}
	printf("\n");
	for(i=0; i<nc; i++)
	{
		strD[i] = aux[i]+'A'+6*(aux[i]>25);
		printf("%d ", strD[i]);
	}
	strD[nc] = '\0';
	printf("\n");
	printf("%s\n", strD);
	return 0;
}
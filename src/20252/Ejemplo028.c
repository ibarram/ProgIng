#include <stdio.h>

#define N 50
#define NC 52

int main(int argc, char *argv[])
{
	char str[N], strC[N], strD[N], c;
	int i, a, b, ai, nc;
	ai = -1;
	do{
		printf("a = ");
		scanf("%d", &a);
		for(i=0; i<NC; i++)
			if(((a*i)%NC)==1)
			{
				ai = i;
				break;
			}
	}while(ai<0);
	printf("b = ");
	scanf("%d", &b);
	while ((c = getchar()) != '\n' && c != EOF) {}
	i = 0;
	do{
		c = getchar();
		if((c>='A'&&c<='Z')||((c>='a'&&c<='z')||c==' '))
		{
			str[i] = c;
			i++;
		}
	}while(c!=10&&i<(N-1));
	nc = i;
	str[nc] = '\0';
	printf("MSG: %s\n", str);
	for(i=0; i<nc; i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
			strC[i] = str[i]-'A';
		else if(str[i]>='a'&&str[i]<='z')
			strC[i] = str[i]-'a'+26;
		else
			strC[i] = NC;
	}
	strC[nc] = '\0';
	for(i=0; i<nc; i++)
		if(strC[i]<NC)
			strC[i] = (a*strC[i]+b)%NC;
	for(i=0; i<nc; i++)
	{
		if(strC[i]<NC/2)
			strC[i] = strC[i]+'A';
		else if(strC[i]<NC)
			strC[i] = strC[i]+'a'-26;
		else
			strC[i] = ' ';
	}
	printf("MSG ENCRIPTADO: %s\n", strC);
	for(i=0; i<nc; i++)
	{
		if(strC[i]>='A'&&strC[i]<='Z')
			strD[i] = strC[i]-'A';
		else if(strC[i]>='a'&&strC[i]<='z')
			strD[i] = strC[i]-'a'+26;
		else
			strD[i] = NC;
	}
	strD[nc] = '\0';
	for(i=0; i<nc; i++)
		if(strD[i]<NC)
		{
			if(strD[i]>=b)
				strD[i] = (ai*(strD[i]-b))%NC;
			else
				strD[i] = (ai*(NC+strD[i]-b))%NC;
		}
	for(i=0; i<nc; i++)
	{
		if(strD[i]<NC/2)
			strD[i] = strD[i]+'A';
		else if(strD[i]<NC)
			strD[i] = strD[i]+'a'-26;
		else
			strD[i] = ' ';
	}
	printf("MSG DESENCRIPTADO: %s\n", strD);
	return 0;
}
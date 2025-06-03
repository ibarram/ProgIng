#include<stdio.h>

int str2int(char str[])
{
	int num = 0;
	int i = str[0]=='-'?1:0;
	while(str[i]>='0'&&str[i]<='9')
	{
		num *= 10;
		num += (str[i++]-'0');
	}
	return str[0]=='-'?-num:num;
}

float str2float(char str[])
{
	float num = 0;
	int i = str[0]=='-'?1:0, p10=10;
	while(str[i]>='0'&&str[i]<='9')
	{
		num *= 10;
		num += (str[i++]-'0');
	}
	if(str[i++]!='.')
		return str[0]=='-'?-num:num;
	while(str[i]>='0'&&str[i]<='9')
	{
		num += (str[i++]-'0')/((float)p10);
		p10 *= 10;
	}
	return str[0]=='-'?-num:num;
}

int main(int argc, char *argv[])
{
	int i;
	float s, d;
	if(argc==1)
	{
		printf("Uso: %s A B\n", argv[0]);
		return 1;
	}
	for(i=1, s=0; i<argc; i++)
	{
		d = str2float(argv[i]);
		s += d;
		printf("%d-> %f\t%f\n", i, d, s);
	}
	printf("Suma = %f\n", s);
	return 0;
}
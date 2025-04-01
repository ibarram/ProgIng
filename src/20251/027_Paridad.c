#include <stdio.h>

#define NC 100

int main(int argc, char *argv[])
{
	char msg[NC+1];
	int i;
	i=0;
	do{
		msg[i++] = getc(stdin);
	}while(msg[i-1]!=10);
	msg[i] = '\0';
	printf("MSG: %s\n", msg);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	float pi;
	if(argc>1)
	{
		for(i=1, pi=0; i<argc; i++)
			pi+=atof(argv[i]);
		printf("La suma es %f\n", pi);
		return 0;
	}
	else
		return 1;
}
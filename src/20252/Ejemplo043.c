#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 50

int main(int argc, char *argv[])
{
	int i, n;
	double x;
	FILE *fp;
	char filename[N];
	do{
		printf("Ingrese el valor de n: ");
		scanf("%d", &n);
	}while(n<1);
	if(argc==2)
		strcpy(filename, argv[1]);
	else
		strcpy(filename, "Prueba.txt");
	fp = fopen(filename, "wt");
	if(fp==NULL)
		return 1;
	srand(time(NULL));
	fprintf(fp, "%d\n", n);
	for(i=0; i<n; i++)
	{
		x = (1.0*rand())/RAND_MAX;
		fprintf(fp, "%d\t%lf\n", i+1, x);
		printf("x[%d] = %lf\n", i+1, x);
	}
	fclose(fp);
	return 0;
}
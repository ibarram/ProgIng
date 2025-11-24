#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

int main(int argc, char *argv[])
{
	int i, n, c;
	double *x, m;
	FILE *fp;
	char filename[N];
	if(argc==2)
		strcpy(filename, argv[1]);
	else
		strcpy(filename, "Prueba.txt");
	fp = fopen(filename, "rt");
	if(fp==NULL)
		return 1;
	fscanf(fp, "%d\n", &n);
	printf("n = %d\n", n);
	x = (double*)malloc(n*sizeof(double));
	if(x==NULL)
	{
		fclose(fp);
		return 2;
	}
	for(i=0, m=0; i<n; i++)
	{
//		fscanf(fp, "%d\t%lf\n", &c, &x[i]);
		fscanf(fp, "%d\t%lf\n", &c, x+i);
		printf("x[%d] = %lf\n", c, x[i]);
		m+=x[i];
	}
	m/=n;
	printf("Media = %lf\n", m);
	fclose(fp);
	return 0;
}
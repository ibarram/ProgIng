#include <stdio.h>
#include <string.h>

#define N 50

int main(int argc, char *argv[])
{
	int i, n;
	FILE *fp;
	char filename[N];
	printf("Ingrese el valor de n: ");
	scanf("%d", &n);
	if(argc==2)
		strcpy(filename, argv[1]);
	else
		strcpy(filename, "Prueba.txt");
	fp = fopen(filename, "wt");
	if(fp==NULL)
		return 1;
	for(i=0; i<n; i++)
		fprintf(fp, "%d\n", i+1);
	fclose(fp);
	return 0;
}
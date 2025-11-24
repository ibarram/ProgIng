#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, n;
	FILE *fp;
	printf("Ingrese el valor de n: ");
	scanf("%d", &n);
	fp = fopen("Prueba.txt", "wt");
	if(fp==NULL)
		return 1;
	for(i=0; i<n; i++)
		fprintf(fp, "%d\n", i+1);
	fclose(fp);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define N 	50

int main(int argc, char *argv[])
{
	char filename[N] = "full_data.csv";
	char *str;
	char c;
	int i, j, nc, nl, *ln, *Ceremony, *Year;
	FILE *fp;
	fp = fopen(filename, "rt");
	if(fp==NULL)
	{
		printf("Error al leer el archivo.\n");
		return 1;
	}
	//fscanf(fp, "%s", str);
	/*
	for(i=0; i<10; i++)
	{
		fgets(str, NC-1, fp);
		printf("%s", str);
	}
	*/
	j=0;
	i=0;
	while((c=fgetc(fp))!=EOF)
	{
		j++;
		if(c==10)
			i++;
	}
	nl = i;
	nc = j;
	printf("Num L: %d\n", nl);
	printf("Num C: %d\n", nc);
	str = (char*)malloc((nc+1)*sizeof(char));
	if(str==NULL)
	{
		fclose(fp);
		return 1;
	}
	ln = (int*)calloc(nl, sizeof(int));
	if(ln==NULL)
	{
		fclose(fp);
		free(str);
		return 2;
	}
	fseek(fp, 0, SEEK_SET);
	for(i=0, j=1; i<nc; i++)
	{
		str[i] = getc(fp);
		if(str[i]==10)
			ln[j++] = i+1;
	}
	str[i] = '\0';
	fclose(fp);
	for(i=1; i<nl; i++)
		str[ln[i]-1] = '\0';
	Ceremony = (int*)malloc((nl-1)*sizeof(int));
	if(Ceremony==NULL)
	{
		free(ln);
		free(str);
		return 3;
	}
	Year = (int*)malloc((nl-1)*sizeof(int));
	if(Year==NULL)
	{
		free(Ceremony);
		free(ln);
		free(str);
		return 3;
	}	
	for(i=1; i<nl; i++)
	{
		Ceremony[i-1] = atoi(str+ln[i]);
		j=0;
		while(str[ln[i]+j]!=9)
			j++;
		Year[i-1] = atoi(str+ln[i]+j+1);
		printf("%d. %d\t%d\n", i, Ceremony[i-1], Year[i-1]);
	}
	free(Year);
	free(Ceremony);
	free(ln);
	free(str);
	return 0;
}
#include <stdio.h>

#define NM 50
#define NE 20
#define NC 10

typedef struct
{
	char nombre[NM];
	long int telefono;
	char email[NE];
}contacto;

int main(int argc, char *argv[])
{
	contacto agenda[NC];
	int op, i, n;
	char c;
	n = 0;
	do{
		printf("Nombre: ");
		i = 0;
		do{
			c = getchar();
			agenda[n].nombre[i++] = c;
		}while(c!=10);
		agenda[n].nombre[i-1] = '\0';
		// scanf("%s", agenda[n].nombre);
		// &(agenda[i].nombre[]) -> agenda[i].nombre
		printf("Telefono: ");
		scanf("%ld", &(agenda[n].telefono));
		printf("Correo electronico: ");
		scanf("%s", agenda[n].email);
		n++;
		printf("Ingresar otro contacto: ");
		scanf("%d", &op);
		do{
			c = getchar();
		}while(c!=10);
	}while(op&&(n<NC));
	printf("Agenda.\n");
	for(i=0; i<n; i++)
		printf("%s, %ld, %s\n", agenda[i].nombre, agenda[i].telefono, agenda[i].email);
	return 0;
}
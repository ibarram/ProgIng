/**
 * @file Ejemplo035.c
 * @brief Cifrado/descifrado XOR sobre letras (A–Z, a–z) usando una clave numérica.
 *
 * @details
 * Este programa implementa un cifrado didáctico:
 * - Solo modifica letras del alfabeto:
 *   - 'A'..'Z'  -> valores 0..25
 *   - 'a'..'z'  -> valores 26..51
 * - A ese valor se le aplica XOR con una clave `cl_c` (un byte).
 * - Después se “re-mapea” al rango de letras:
 *   - 0..25  -> 'A'..'Z'
 *   - 26..51 -> 'a'..'z'
 *
 * El programa imprime trazas numéricas por carácter para mostrar la transformación.
 *
 * @par Entrada estándar
 * 1) Una línea de texto (hasta N-1 caracteres) terminada con ENTER.
 * 2) Una clave entera (se trunca a 1 byte al convertirla a char).
 *
 * @par Salida estándar
 * - Mensaje original `MSG`
 * - Mensaje cifrado `MSG E`
 * - Mensaje descifrado `MSG D`
 * - Trazas por carácter con valores intermedios.
 *
 * @note
 * - Solo letras A–Z / a–z se cifran; otros caracteres se dejan igual.
 * - Es un ejemplo didáctico; no es criptografía segura.
 *
 * @code
 * gcc Ejemplo035.c -o Ejemplo035
 * ./Ejemplo035
 * @endcode
 */

#include <stdio.h>

#define N 100
#define	BIT(n)				(1<<(n))
#define	BIT_GET(x,n)		((x) & BIT(n))
#define	BIT_SET(x,n)		((x) |= BIT(n))
#define	BIT_CLEAR(x,n)	 	((x) &= ~BIT(n))

int main(int argc, char *argv[])
{
	char msg[N], msgE[N], msgD[N], cl_c, E;
	int i, j, cl_I, n;

	/* Leer mensaje hasta ENTER */
	i = 0;
	do{
		msg[i] = (char)getchar();
		i++;
	}while(i<N&&msg[i-1]!=10);
	msg[i-1] = '\0';
	n = i-1;

	/* Leer clave como entero y convertirla a un byte (char) */
	printf("Ingrese la clave: ");
	scanf("%d", &cl_I);
	cl_c = (char)cl_I;

	printf("MSG: %s\n", msg);

	/* ----------- CIFRADO ----------- */
	msgE[n] = '\0';
	for(i=0; i<n; i++)
	{
		printf("%d. %u\t", i, (unsigned int)(unsigned char)msg[i]);

		msgE[i] = msg[i];
		E = 0;

		/* Si es minúscula, mapear a 26..51 */
		if(msgE[i]>='a' && msgE[i]<='z')
		{
			msgE[i] -= 'a';
			msgE[i] += 26;
			printf("%u\t", (unsigned int)(unsigned char)msgE[i]);

			msgE[i] ^= cl_c; /* XOR con la clave */
			E = 1;
			printf("%u\t", (unsigned int)(unsigned char)msgE[i]);
		}
		/* Si es mayúscula, mapear a 0..25 */
		else if(msgE[i]>='A' && msgE[i]<='Z')
		{
			msgE[i] -= 'A';
			printf("%u\t", (unsigned int)(unsigned char)msgE[i]);

			msgE[i] ^= cl_c;
			E = 1;
			printf("%u\t", (unsigned int)(unsigned char)msgE[i]);
		}

		/* Re-mapeo a letra */
		if(E && (unsigned char)msgE[i] < 26)
		{
			msgE[i] += 'A';
			printf("%u\t", (unsigned int)(unsigned char)msgE[i]);
		}
		else if(E && (unsigned char)msgE[i] < 52)
		{
			msgE[i] -= 26;
			msgE[i] += 'a';
			printf("%u\t", (unsigned int)(unsigned char)msgE[i]);
		}

		printf("\n");
	}
	printf("MSG E: %s\n", msgE);

	/* ----------- DESCIFRADO ----------- */
	msgD[n] = '\0';
	for(i=0; i<n; i++)
	{
		printf("%d. %u\t", i, (unsigned int)(unsigned char)msgE[i]);

		msgD[i] = msgE[i];
		E = 0;

		if(msgD[i]>='a' && msgD[i]<='z')
		{
			msgD[i] -= 'a';
			msgD[i] += 26;
			printf("%u\t", (unsigned int)(unsigned char)msgD[i]);

			msgD[i] ^= cl_c;
			printf("%u\t", (unsigned int)(unsigned char)msgD[i]);
			E = 1;
		}
		else if(msgD[i]>='A' && msgD[i]<='Z')
		{
			msgD[i] -= 'A';
			printf("%u\t", (unsigned int)(unsigned char)msgD[i]);

			msgD[i] ^= cl_c;
			printf("%u\t", (unsigned int)(unsigned char)msgD[i]);
			E = 1;
		}

		if(E && (unsigned char)msgD[i] < 26)
		{
			msgD[i] += 'A';
			printf("%u\t", (unsigned int)(unsigned char)msgD[i]);
		}
		else if(E && (unsigned char)msgD[i] < 52)
		{
			msgD[i] -= 26;
			msgD[i] += 'a';
			printf("%u\t", (unsigned int)(unsigned char)msgD[i]);
		}

		printf("\n");
	}
	printf("MSG D: %s\n", msgD);

	return 0;
}
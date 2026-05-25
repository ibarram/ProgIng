/**
 * @file Ejemplo034_2.c
 * @brief Inserción de bytes de paridad en posiciones potencia de 2 (Hamming por bytes) y detección de un error de 1 bit.
 *
 * @details
 * Este programa implementa una codificación tipo Hamming sobre un mensaje ASCII, pero
 * trabajando a nivel de **bytes** (caracteres) y usando XOR (^) como operación de paridad.
 *
 * Flujo general:
 * 1) Lee un mensaje `msg` hasta ENTER.
 * 2) Calcula el número mínimo de paridades `np` que satisface:
 *      2^np >= n + np + 1
 * 3) Construye `msgP` (mensaje extendido) de longitud L = n + np:
 *    - en posiciones potencia de 2 (1,2,4,8,...) coloca bytes de paridad (inicialmente 0)
 *    - en el resto coloca los bytes del mensaje original.
 * 4) Calcula las paridades usando el patrón de “bloques” del código original.
 * 5) Simula un error: invierte un bit aleatorio en un byte aleatorio del código.
 * 6) Recalcula las paridades y construye:
 *    - `NC_V`: byte con error (0-based)
 *    - `NB_V`: bit con error (0..7)
 *
 * @par Entrada estándar
 * Una línea de texto (hasta N-1 caracteres) terminada con ENTER.
 *
 * @par Salida estándar
 * Mantiene exactamente la forma de impresión del original:
 * - MSG, MSG_P, NC/NB, MSG_E
 * - P_i
 * - NC_V y NB_V
 *
 * @warning
 * - La impresión `MSG_P: %s` y `MSG_E: %s` puede truncarse si aparecen bytes '\0'
 *   dentro de `msgP`. Se conserva esta impresión por compatibilidad con el original.
 *
 * @code
 * gcc Ejemplo034_2.c -o Ejemplo034_2 -lm
 * ./Ejemplo034_2
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100
#define P 7

/* Macros de bits (se usan para simular el error y construir el síndrome) */
#define	BIT(n)				(1U<<(n))
#define	BIT_GET(x,n)		((x) & BIT(n))
#define	BIT_SET(x,n)		((x) |= BIT(n))
#define	BIT_TOGGLE(x,n)		((x) ^= BIT(n))

/* True si una posición 1-based es potencia de 2: 1,2,4,8,... */
#define IS_POW2_POS(pos)    ((pos) && (((pos) & ((pos)-1U)) == 0U))

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

	/*
	  msg  : mensaje original (solo datos)
	  msgP : mensaje extendido (datos + bytes de paridad)
	  V    : verificaciones de paridad (una por cada bit de paridad i)
	         Se usa unsigned char para que XOR sea estable y no haya signos negativos.
	*/
	char msg[N], msgP[N+P];
	unsigned char V[P];

	/*
	  n   : longitud del mensaje original (bytes)
	  np  : número de paridades
	  nc  : índice (0-based) del byte donde se inyecta el error
	  nb  : índice del bit (0..7) que se invierte para simular el error
	  ncv : síndrome (posición 1-based del byte con error, luego se convierte a 0-based con ncv--)
	  nbv : máscara del bit alterado (potencia de 2), luego se convierte a índice con log2
	*/
	int i, j, k, n, np, nc, nb, ncv, nbv;
	float aux;

	srand(time(NULL));

	/* ------------------- Lectura del mensaje ------------------- */
	i = 0;
	do{
		msg[i] = getchar();
		i++;
	}while(i < N && msg[i-1] != 10); /* 10 == '\n' */

	msg[i-1] = '\0';
	n = i-1;

	/* Protección: mensaje vacío (evita rand()%0 y accesos inválidos) */
	if (n <= 0)
		return 0;

	/*
	  ------------------- Cálculo correcto de np -------------------
	  Condición mínima de Hamming:
	    2^np >= n + np + 1
	  Se acota con P para evitar desbordar el tamaño del arreglo msgP.
	*/
	np = 0;
	while (((1U << np) < (unsigned)(n + np + 1)) && np < P)
		np++;

	printf("n = %d\tnp = %d\n", n, np);
	printf("MSG: %s\n", msg);

	/*
	  ------------------- Construcción de msgP -------------------
	  Longitud del código:
	    L = n + np

	  Recorremos posiciones 1-based (pos = i+1):
	  - si pos es potencia de 2 => posición de paridad => msgP[i] = 0
	  - si no => posición de dato => copiar el siguiente byte del mensaje
	*/
	{
		int L = n + np;
		int data_idx = 0;

		for (i = 0; i < L; i++)
		{
			int pos = i + 1; /* 1-based */
			if (IS_POW2_POS((unsigned)pos))
				msgP[i] = 0;            /* paridad */
			else
				msgP[i] = msg[data_idx++];/* dato */
		}

		/* Terminador para imprimir con %s (misma práctica del original) */
		msgP[L] = '\0';
	}

	/*
	  ------------------- Cálculo de paridades (codificación) -------------------
	  Para cada bit de paridad i:
	    j = 2^i - 1  (índice 0-based donde vive esa paridad)
	  Se aplica el patrón de bloques del código original:
	    incluir (j+1) bytes, saltar (j+1) bytes, incluir, ...
	  y se acumula XOR en msgP[j].
	*/
	for (i = 0; i < np; i++)
	{
		j = (1 << i) - 1;
		for (k = j; k < (n + np); k++)
			if (((k - j) / (j + 1) + 1) % 2)
				msgP[j] ^= msgP[k];
	}

	printf("MSG_P: %s\n", msgP);

	/* ------------------- Simulación del error ------------------- */
	nc = rand() % (n + np);
	nb = rand() % 8;
	printf("NC = %d\tNB = %d\n", nc, nb);

	BIT_TOGGLE(msgP[nc], nb);

	printf("MSG_E: %s\n", msgP);

	/*
	  ------------------- Verificación de paridades -------------------
	  V[i] acumula el XOR del grupo de paridad i (debe ser 0 si todo es consistente).
	  Se conserva el mismo patrón de bloques (iniciando V[i] con msgP[j]).
	*/
	for (i = 0; i < np; i++)
	{
		j = (1 << i) - 1;

		for (k = j + 1, V[i] = (unsigned char)msgP[j]; k < (n + np); k++)
		{
			if (((k - j) / (j + 1) + 1) % 2)
				V[i] ^= (unsigned char)msgP[k];
		}

		printf("P_%d = %d\n", i, (int)V[i]);
	}

	/*
	  ------------------- Síndrome y bit de error -------------------
	  - ncv se arma con los bits i para los cuales V[i] != 0.
	    Eso da la posición 1-based del byte erróneo.
	  - nbv toma la máscara del bit (potencia de 2), del primer V[i] no nulo.
	*/
	for (i = 0, ncv = 0, nbv = 0; i < np; i++)
		if (V[i])
		{
			BIT_SET(ncv, i);
			if (!nbv)
				nbv = (int)V[i];
		}

	/* Convertir a 0-based (como el original) */
	ncv--;

	/*
	  Convertir máscara (potencia de 2) a índice de bit con log2.
	  Protección: log2(0) no es válido (aunque aquí normalmente hay error inyectado).
	*/
	if (nbv > 0)
	{
		aux = (float)log2((double)nbv);
		nbv = (int)aux;
	}
	else
	{
		nbv = 0;
	}

	printf("NC_V = %d\tNB_V = %d\n", ncv, nbv);

	/* Bloque de validación del original se conserva comentado */
	/*
	for(i=0, V=P; i<n; i++)
		V^=msgP[i];
	printf("Validacion: %c (", V);
	for(i=7; i>-1; i--)
		printf("%d ", BIT_GET(V, i)?1:0);
	printf(")\n");
	*/

	return 0;
}

/**
 * @file Ejemplo034.c
 * @brief Inserción de paridades (Hamming) en posiciones potencia de 2 y detección de error de 1 bit.
 *
 * @details
 * El programa:
 * 1) Lee un mensaje `msg` (hasta N-1 caracteres, termina al presionar ENTER).
 * 2) Calcula `np` (número de paridades) con la condición mínima de Hamming:
 *      2^np >= n + np + 1
 * 3) Construye `msgP` (longitud n+np) insertando bytes de paridad en posiciones 1,2,4,8,... (1-based).
 * 4) Calcula las paridades por XOR usando el patrón de “bloques” del código original.
 * 5) Simula un error: invierte un bit aleatorio en un byte aleatorio.
 * 6) Recalcula paridades y forma:
 *    - NC_V: posición del byte con error (0-based)
 *    - NB_V: índice del bit alterado (0..7) obtenido desde la máscara XOR (potencia de 2)
 *
 * @par Entrada estándar
 * Una línea de texto terminada con ENTER.
 *
 * @par Salida estándar
 * Mantiene la forma de impresión del programa original (MSG_P/MSG_E con %s, P_i, NC_V, NB_V).
 *
 * @warning
 * - `MSG_P: %s` puede truncarse si dentro de `msgP` aparece el byte 0 ('\0').
 *   Se conserva así para no cambiar la forma de impresión original.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100
#define P 7

#define	BIT(n)				(1U<<(n))
#define	BIT_GET(x,n)		((x) & BIT(n))
#define	BIT_SET(x,n)		((x) |= BIT(n))
#define	BIT_TOGGLE(x,n)		((x) ^= BIT(n))

/* True si pos (1-based) es potencia de 2: 1,2,4,8,... */
#define IS_POW2_POS(pos)    ((pos) && (((pos) & ((pos)-1U)) == 0U))

int main(int argc, char *argv[])
{
	/*
	  msg  : mensaje original (solo datos)
	  msgP : mensaje con espacios de paridad insertados (datos + paridades)
	  V    : vector de verificación de paridad por cada bit de paridad i
	  msgV : reservado (no se usa en esta versión; se conserva por estructura original)
	*/
	char msg[N], msgP[N+P], msgV[N];

	/*
	  ERROR CORREGIDO:
	  V debe indexarse por i (0..np-1). En el original V era char y se usaba con
	  índices derivados de j=(2^i-1), lo que podía desbordar o dejar valores sin inicializar.
	  Se usa unsigned char para evitar problemas de signo en XOR.
	*/
	unsigned char V[P];

	int i, j, k, n, np, nc, nb, l2, ncv, nbv;
	float l2f, aux;

	srand((unsigned)time(NULL));

	/* ---------- Leer mensaje hasta ENTER ---------- */
	i = 0;
	do{
		msg[i] = (char)getchar();
		i++;
	}while(i < N && msg[i-1] != 10);   /* 10 == '\n' */

	msg[i-1] = '\0';
	n = i-1;

	/*
	  ERROR CORREGIDO:
	  np no se calcula con aproximación logarítmica.
	  Condición de Hamming (mínimo np):
	    2^np >= n + np + 1
	  Esto garantiza suficientes posiciones de paridad para identificar la posición del error.
	*/
	np = 0;
	while( ((1U<<np) < (unsigned)(n + np + 1)) && np < P )
		np++;

	printf("n = %d\tnp = %d\n", n, np);
	printf("MSG: %s\n", msg);

	/*
	  ---------- Construir msgP con paridades ----------
	  Longitud total L = n + np.
	  Posiciones (1-based) potencia de 2 se reservan para paridad (byte 0).
	  El resto se llena con los bytes del mensaje original.
	*/
	{
		int L = n + np;
		int data_idx = 0;

		for(i = 0; i < L; i++)
		{
			int pos = i + 1; /* 1-based */

			if(IS_POW2_POS((unsigned)pos))
			{
				msgP[i] = 0;          /* placeholder de paridad */
			}
			else
			{
				msgP[i] = msg[data_idx++];  /* copiar dato */
			}
		}
		/* Terminador para impresión con %s (se mantiene como en el original) */
		msgP[L] = '\0';
	}

	/*
	  ---------- Cálculo de paridades (codificación) ----------
	  Para cada i:
	    j = 2^i - 1  (índice 0-based donde vive la paridad i)
	  Se aplica el patrón de bloques del código original:
	    incluir (j+1) bytes, saltar (j+1) bytes, incluir, ...
	  y se acumula XOR en msgP[j].
	*/
	for(i=0; i<np; i++)
	{
		j = (1<<i)-1;
		for(k=j; k<(n+np); k++)
			if(((k-j)/(j+1)+1)%2)
				msgP[j] ^= msgP[k];
	}

	/* Impresión original (puede truncarse si hay '\0' internos) */
	printf("MSG_P: %s\n", msgP);

	/* ---------- Simular error: voltear bit nb en byte nc ---------- */
	nc = rand()%(n+np);
	nb = rand()%8;
	printf("NC = %d\tNB = %d\n", nc, nb);

	BIT_TOGGLE(msgP[nc], nb);

	/* Impresión original */
	printf("MSG_E: %s\n", msgP);

	/*
	  ---------- Recalcular paridades (verificación) ----------
	  V[i] guarda el XOR del grupo de paridad i (debe ser 0 si no hay error).
	  Se mantiene el mismo patrón de bloques, pero guardando en V[i] (no V[j]).
	*/
	for(i=0; i<np; i++)
	{
		j = (1<<i)-1;

		/* Inicializar con el valor actual del byte de paridad */
		V[i] = (unsigned char)msgP[j];

		/* XOR sobre los bloques del grupo de paridad i */
		for(k=j+1; k<(n+np); k++)
		{
			if(((k-j)/(j+1)+1)%2)
				V[i] ^= (unsigned char)msgP[k];
		}

		/* Impresión original */
		printf("P_%d = %d\n", i, (int)V[i]);
	}

	/*
	  ---------- Síndrome ----------
	  ncv: se arma con bits i donde V[i] != 0.
	       Esto da la posición del byte erróneo en 1-based.
	  nbv: máscara del bit erróneo (potencia de 2), tomada del primer V[i] != 0.
	*/
	for(i=0, ncv=0, nbv=0; i<np; i++)
		if(V[i])
		{
			BIT_SET(ncv, i);
			if(!nbv)
				nbv = (int)V[i];
		}

	/* Mantener la conversión original a 0-based */
	ncv--;

	/*
	  Convertir máscara nbv (ej. 8) a índice de bit (3) con log2.
	  ERROR CORREGIDO: si nbv==0, log2 es inválido.
	*/
	if(nbv > 0)
	{
		aux = (float)log2((double)nbv);
		nbv = (int)aux;
	}
	else
	{
		aux = 0.0f;
		nbv = 0;
	}

	printf("NC_V = %d\tNB_V = %d\n", ncv, nbv);

	/* Validación original (comentada) se conserva tal cual */
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
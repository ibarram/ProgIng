/**
 * @file Ejemplo040.c
 * @brief Genera n números aleatorios en [min,max] y calcula la media.
 *
 * @details
 * Uso:
 *   ./Ejemplo040 n min max
 *
 * Donde:
 * - `n` es el número de muestras (1 <= n <= N).
 * - `min` y `max` definen el intervalo; si vienen invertidos, el programa los intercambia.
 *
 * El programa:
 * 1) Genera `n` valores:
 *      x[i] = ((max-min)*rand())/RAND_MAX + min
 * 2) Imprime cada valor.
 * 3) Calcula e imprime la media.
 *
 * @par Entrada
 * Argumentos por línea de comandos:
 * @code
 * ./Ejemplo040 n min max
 * @endcode
 *
 * @par Salida
 * - Imprime cada `X[i]`
 * - Imprime `Media = ...`
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(N).
 *
 * @note
 * Revisión mínima aplicada:
 * - `x[N]` se declara `static` para evitar problemas de stack por su tamaño (no cambia la salida).
 *
 * @code
 * gcc Ejemplo040.c -o Ejemplo040
 * ./Ejemplo040 5 0 10
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main(int argc, char *argv[])
{
    /* Arreglo grande: se deja en memoria estática para evitar stack overflow */
    static float x[N];

    float min, max, aux, media;
    int n, i;

    /* Se esperan 3 argumentos: n min max => argc = 4 */
    if (argc != 4)
        return 1;

    n   = atoi(argv[1]);
    min = (float)atof(argv[2]);
    max = (float)atof(argv[3]);

    if (n < 1 || n > N)
        return 2;

    /* Asegurar min <= max */
    if (max < min)
    {
        aux = max;
        max = min;
        min = aux;
    }

    srand((unsigned)time(NULL));

    /* Generar valores y acumular media */
    for (i = 0, media = 0.0f; i < n; i++)
    {
        x[i] = ((max - min) * rand()) / RAND_MAX + min;
        media += x[i];
        printf("X[%d] = %f\n", i + 1, x[i]);
    }

    media /= n;
    printf("Media = %f\n", media);

    return 0;
}

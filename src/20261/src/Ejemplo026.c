/**
 * @file Ejemplo026.c
 * @brief Ordenamiento por conteo (Counting Sort) para enteros en el rango [0, max].
 *
 * @details
 * Este programa genera un arreglo de `n` enteros aleatorios en el rango [0, max],
 * construye un histograma de frecuencias `h[]` y reconstruye el arreglo ordenado.
 *
 * Algoritmo (Counting Sort):
 * 1) Generar datos: x[i] ∈ [0, max]
 * 2) Inicializar histograma h[0..max] = 0
 * 3) Contar frecuencias: h[x[i]]++
 * 4) Reconstruir ordenado:
 *    - para cada valor j de 0..max, escribirlo h[j] veces en x[]
 *
 * @par Entrada estándar
 * - `n` (long int): número de elementos, 1 <= n <= N
 * - `max` (int): valor máximo permitido (1 <= max <= mx)
 *
 * @par Salida estándar
 * - Arreglo desordenado
 * - Arreglo ordenado
 *
 * @par Restricciones
 * - `N = 300000` (máximo tamaño del arreglo)
 * - `mx = 16384` (máximo rango permitido para histograma)
 * - Los valores generados están en [0, max].
 *
 * @par Complejidad
 * - Tiempo: O(n + max)
 * - Memoria: O(N + mx)
 *
 * @note
 * Se calcula `nd = ceil(log10(n))` para imprimir índices con ceros a la izquierda,
 * por ejemplo x[0001], x[0123], etc.
 *
 * @code
 * gcc Ejemplo026.c -o Ejemplo026 -lm
 * ./Ejemplo026
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 300000
#define mx 16384

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int max, x[N];
    long int n, h[mx], i, j, k;
    float nd;

    /* Leer n con validación */
    do {
        printf("Ingrese el numero de elementos: ");
        scanf("%ld", &n);
    } while (n < 1 || n > N);

    /* Semilla para números pseudoaleatorios */
    srand((unsigned)time(NULL));

    /* nd = número de dígitos aproximado para dar formato a los índices */
    nd = ceil(log10(n));

    /* Leer max con validación */
    do {
        printf("Ingrese l valor maximo: ");
        scanf("%d", &max);
    } while (max < 1 || max > mx);

    /* Generar e imprimir arreglo desordenado */
    printf("Desordenado\n");
    for (i = 0; i < n; i++)
    {
        /* Valores en [0, max] */
        x[i] = rand() % (max + 1);
        printf("x[%0*ld] = %d\n", (int)nd, i + 1, x[i]);
    }

    /* Inicializar histograma */
    for (i = 0; i <= max; i++)
        h[i] = 0;

    /* Contar frecuencias */
    for (i = 0; i < n; i++)
        h[x[i]]++;

    /*
      Reconstrucción del arreglo ordenado:
      - j recorre el dominio 0..max buscando valores con frecuencia > 0
      - escribe j h[j] veces
    */
    i = 0;
    j = 0;
    while (i < n)
    {
        while (!h[j]) /* saltar valores con frecuencia 0 */
            j++;

        for (k = 0; k < h[j]; k++)
            x[i++] = (int)j;

        j++;
    }

    /* Imprimir arreglo ordenado */
    printf("Ordenado\n");
    for (i = 0; i < n; i++)
        printf("x[%0*ld] = %d\n", (int)nd, i + 1, x[i]);

    return 0;
}

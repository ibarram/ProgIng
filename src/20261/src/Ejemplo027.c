/**
 * @file Ejemplo027.c
 * @brief Ordenamiento por conteo (Counting Sort) para enteros en el rango [min, max].
 *
 * @details
 * Este programa genera un arreglo de `n` enteros aleatorios en el rango [min, max],
 * usa un histograma `h[]` de tamaño (max-min+1) y reconstruye el arreglo ordenado.
 *
 * Se utiliza el desplazamiento:
 *   índice_hist = x[i] - min
 * para mapear [min, max] a [0, max-min].
 *
 * @par Entrada estándar
 * - `n` (long int): número de elementos, 1 <= n <= N
 * - `max` (int)
 * - `min` (int)
 *
 * @par Salida estándar
 * - Arreglo desordenado
 * - Arreglo ordenado
 *
 * @par Restricciones
 * - `N = 300000`
 * - `mx = 32768` (capacidad del histograma)
 * - Se requiere que (max - min) <= mx - 1 para no desbordar `h[]`.
 *
 * @par Complejidad
 * - Tiempo: O(n + (max-min))
 * - Memoria: O(N + mx)
 *
 * @code
 * gcc Ejemplo027.c -o Ejemplo027 -lm
 * ./Ejemplo027
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 300000
#define mx 32768

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int min, max, x[N], aux;
    long int n, h[mx], i, j, k;
    float nd;

    /* Leer n con validación */
    do {
        printf("Ingrese el numero de elementos: ");
        scanf("%ld", &n);
    } while (n < 1 || n > N);

    srand((unsigned)time(NULL));

    nd = ceil(log10(n));

    /* Leer rango */
    printf("Ingrese el valor maximo: ");
    scanf("%d", &max);
    printf("Ingrese el valor minimo: ");
    scanf("%d", &min);

    /* Asegurar min <= max */
    if (max < min)
    {
        aux = min;
        min = max;
        max = aux;
    }

    /* Generar e imprimir */
    printf("Desordenado\n");
    for (i = 0; i < n; i++)
    {
        x[i] = rand() % (max - min + 1) + min;
        printf("x[%0*ld] = %d\n", (int)nd, i + 1, x[i]);
    }

    /* Inicializar histograma de tamaño (max-min+1) */
    for (i = 0; i <= (max - min); i++)
        h[i] = 0;

    /* Contar (con desplazamiento por min) */
    for (i = 0; i < n; i++)
        h[x[i] - min]++;

    /* Reconstrucción */
    i = 0;
    j = 0;
    while (i < n)
    {
        while (!h[j])
            j++;

        for (k = 0; k < h[j]; k++)
            x[i++] = (int)(j + min);

        j++;
    }

    /* Imprimir ordenado */
    printf("Ordenado\n");
    for (i = 0; i < n; i++)
        printf("x[%0*ld] = %d\n", (int)nd, i + 1, x[i]);

    return 0;
}
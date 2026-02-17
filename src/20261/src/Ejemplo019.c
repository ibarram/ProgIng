/**
 * @file Ejemplo019.c
 * @brief Generación y ordenamiento de un arreglo de enteros aleatorios (orden ascendente).
 *
 * @details
 * El programa:
 * 1) Solicita `n` (1 <= n <= N), y los límites `min` y `max`.
 * 2) Si `min > max`, intercambia los valores.
 * 3) Genera un arreglo `x` de tamaño `n` con enteros aleatorios en [min, max].
 * 4) Muestra el arreglo “Desordenado”.
 * 5) Ordena el arreglo en orden ascendente mediante un algoritmo O(n^2) basado en
 *    comparación e intercambio (similar a selección/intercambio):
 *      - Para cada i, compara x[i] con x[j] (j>i) y si x[i] > x[j], intercambia.
 * 6) Muestra el arreglo “Ordenado”.
 *
 * @par Entrada estándar
 * - `n` (long int): número de elementos (1..N)
 * - `max` (int): valor máximo permitido
 * - `min` (int): valor mínimo permitido
 *
 * @par Salida estándar
 * - Arreglo desordenado (generado).
 * - Arreglo ordenado en forma ascendente.
 *
 * @par Restricciones
 * - `N = 100000` (capacidad máxima del arreglo).
 *
 * @par Complejidad
 * - Generación + despliegue: O(n)
 * - Ordenamiento: O(n^2) por los dos ciclos anidados
 * - Memoria: O(N)
 *
 * @note
 * Para n grande (cerca de 100000), O(n^2) será muy lento.
 * Este ejemplo se usa con propósitos didácticos para mostrar un ordenamiento básico.
 *
 * @code
 * gcc Ejemplo019.c -o Ejemplo019
 * ./Ejemplo019
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Tamaño máximo permitido del arreglo. */
#define N 100000

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    long int n, i, j;  /* n: tamaño; i,j: índices para recorrido/ordenamiento */
    int min, max;      /* límites del rango */
    int x[N];          /* arreglo */
    int aux;           /* auxiliar para intercambio */

    /* Leer n y validar. */
    do {
        printf("Ingrese el numero de elmentos: ");
        scanf("%ld", &n);
    } while (n < 1 || n > N);

    /* Leer límites (max y min). */
    printf("Ingrese el valor maximo: ");
    scanf("%d", &max);

    printf("Ingrese el valor minimo: ");
    scanf("%d", &min);

    /* Asegurar min <= max intercambiando si es necesario. */
    if (min > max)
    {
        max += min;
        min = max - min;
        max -= min;
    }

    /* Semilla para valores aleatorios distintos por ejecución. */
    srand(time(NULL));

    /* Generar e imprimir arreglo inicial (sin ordenar). */
    printf("Desordenado.\n");
    for (i = 0; i < n; i++)
    {
        x[i] = rand() % (max - min + 1) + min;
        printf("x[%ld] = %d\n", i + 1, x[i]);
    }

    /*
      Ordenamiento ascendente por comparación e intercambio:
      - Para cada i, se busca si existe algún x[j] (j>i) menor que x[i].
      - Si x[i] > x[j], se intercambian.
      Este patrón es similar a una selección por intercambios y tiene costo O(n^2).
    */
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (x[i] > x[j])
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }

    /* Imprimir arreglo ordenado. */
    printf("Ordenado.\n");
    for (i = 0; i < n; i++)
        printf("x[%ld] = %d\n", i + 1, x[i]);

    return 0;
}

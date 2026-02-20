/**
 * @file Ejemplo021.c
 * @brief Genera un arreglo de flotantes aleatorios y lo ordena con Selection Sort.
 *
 * @details
 * El programa:
 * 1) Lee `n` (1..N) y un rango real [min, max].
 * 2) Genera `n` flotantes uniformes (aprox.) en [min, max] usando:
 *    x[i] = ((max-min)*rand())/RAND_MAX + min
 * 3) Imprime el arreglo "Desordenado".
 * 4) Ordena con **Selection Sort**:
 *    - Primero ubica el mínimo global en x[0].
 *    - Después, para cada posición i, selecciona el mínimo del subarreglo [i..n-1]
 *      y lo intercambia con x[i].
 *
 * @par Entrada estándar
 * - `n` (long int): número de elementos (1..N)
 * - `max` (float): límite superior
 * - `min` (float): límite inferior
 *
 * @par Salida estándar
 * - Arreglo desordenado
 * - Arreglo ordenado (ascendente)
 *
 * @par Complejidad
 * - Generación/impresión: O(n)
 * - Selection Sort: O(n^2)
 * - Memoria: O(N)
 *
 * @warning
 * - El intercambio de flotantes se hace con multiplicación/división. Si alguno
 *   de los valores involucrados es 0, puede provocar división entre 0 o NaN/Inf.
 *   Para una versión robusta, usa una variable auxiliar (`aux`).
 * - También el intercambio inicial de min/max usa multiplicación/división y falla si min=0.
 *
 * @code
 * gcc Ejemplo021.c -o Ejemplo021
 * ./Ejemplo021
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    long int n, i, j, i_min;
    float min, max;
    float x[N];

    /* Leer n y validar */
    do {
        printf("Ingrese el numero de elmentos: ");
        scanf("%ld", &n);
    } while (n < 1 || n > N);

    /* Leer rango [min,max] */
    printf("Ingrese el valor maximo: ");
    scanf("%f", &max);
    printf("Ingrese el valor minimo: ");
    scanf("%f", &min);

    if (min > max)
    {
        /*
          Intercambio sin variable auxiliar usando multiplicación/división.
          WARNING: falla si min==0 o max==0 (división entre 0).
        */
        max *= min;
        min = max / min;
        max /= min;
    }

    srand(time(NULL));

    /* Generar e imprimir arreglo desordenado */
    printf("Desordenado.\n");
    for (i = 0; i < n; i++)
    {
        /* Escalamiento lineal a [min, max] */
        x[i] = ((max - min) * rand()) / RAND_MAX + min;
        printf("x[%ld] = %f\n", i + 1, x[i]);
    }

    /*
      Paso 1: localizar el mínimo global y ponerlo en x[0].
      Esto no es estrictamente necesario para Selection Sort, pero el código lo hace.
    */
    for (i = 1, i_min = 0; i < n; i++)
        if (x[i] < x[i_min])
            i_min = i;

    if (i_min)
    {
        /* Swap por multiplicación/división (WARNING: falla si x[0]==0 o x[i_min]==0) */
        x[i_min] *= x[0];
        x[0] = x[i_min] / x[0];
        x[i_min] /= x[0];
    }

    /*
      Paso 2: Selection Sort desde i=1:
      - en cada i, encontrar el mínimo en [i..n-1]
      - intercambiarlo con x[i]
    */
    for (i = 1; i < n - 1; i++)
    {
        for (j = i + 1, i_min = i; j < n; j++)
            if (x[j] < x[i_min])
                i_min = j;

        if (i_min != i)
        {
            /* Swap por multiplicación/división (mismas advertencias) */
            x[i_min] *= x[i];
            x[i] = x[i_min] / x[i];
            x[i_min] /= x[i];
        }
    }

    /* Imprimir arreglo ordenado */
    printf("Ordenado.\n");
    for (i = 0; i < n; i++)
        printf("x[%ld] = %f\n", i + 1, x[i]);

    return 0;
}
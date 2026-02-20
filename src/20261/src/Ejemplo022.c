/**
 * @file Ejemplo022.c
 * @brief Genera un arreglo de flotantes aleatorios y lo ordena con Insertion Sort.
 *
 * @details
 * El programa:
 * 1) Lee `n` (1..N) y un rango real [min, max].
 * 2) Genera `n` flotantes en [min,max].
 * 3) Imprime el arreglo "Desordenado".
 * 4) Ordena el arreglo con **Insertion Sort** (orden ascendente):
 *    - Recorre i = 1..n-1, toma x[i] como `aux`,
 *    - desplaza hacia la derecha todos los elementos mayores que `aux`,
 *    - inserta `aux` en la posición correcta.
 * 5) Imprime el arreglo "Ordenado".
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
 * - Insertion Sort: O(n^2) en el peor caso; O(n) si ya está casi ordenado.
 * - Memoria: O(N)
 *
 * @warning
 * - El intercambio de min/max se hace con multiplicación/división; falla si min==0.
 * - El arreglo `x[N]` vive en la pila; en algunos entornos con pila pequeña puede fallar.
 *
 * @code
 * gcc Ejemplo022.c -o Ejemplo022
 * ./Ejemplo022
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

    long int n, i, j;
    float min, max;
    float x[N], aux;

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
        /* Swap por multiplicación/división (WARNING: falla si min==0) */
        max *= min;
        min = max / min;
        max /= min;
    }

    srand(time(NULL));

    /* Generar e imprimir arreglo desordenado */
    printf("Desordenado.\n");
    for (i = 0; i < n; i++)
    {
        x[i] = ((max - min) * rand()) / RAND_MAX + min;
        printf("x[%ld] = %f\n", i + 1, x[i]);
    }

    /*
      INSERTION SORT:
      - i recorre desde 1 hasta n-1.
      - aux almacena el elemento actual a insertar.
      - j recorre hacia atrás desplazando elementos mayores que aux.
    */
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        aux = x[i];

        /* Desplazar hacia la derecha mientras x[j] > aux */
        while (x[j] > aux)
        {
            x[j + 1] = x[j];
            j--;

            /* Si j se vuelve negativo, se detiene para evitar acceder fuera de rango */
            if (j < 0)
                break;
        }

        /* Insertar aux en la posición correcta */
        x[j + 1] = aux;
    }

    /* Imprimir arreglo ordenado */
    printf("Ordenado.\n");
    for (i = 0; i < n; i++)
        printf("x[%ld] = %f\n", i + 1, x[i]);

    return 0;
}
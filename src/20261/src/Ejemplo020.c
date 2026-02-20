/**
 * @file Ejemplo020.c
 * @brief Genera un arreglo de enteros aleatorios y lo ordena con Odd–Even Sort (Brick Sort).
 *
 * @details
 * El programa:
 * 1) Lee el tamaño `n` (1 <= n <= N) y un rango entero [min, max].
 * 2) Genera `n` enteros pseudoaleatorios uniformes (aprox.) en [min, max].
 * 3) Imprime el arreglo "Desordenado".
 * 4) Ordena el arreglo con **Odd–Even Transposition Sort** (también llamado Brick Sort):
 *    - En pasadas alternadas, compara e intercambia pares adyacentes:
 *      - pasada par: (0,1), (2,3), (4,5), ...
 *      - pasada impar: (1,2), (3,4), (5,6), ...
 *    - Se realizan aproximadamente `n-1` pasadas.
 * 5) Imprime el arreglo "Ordenado".
 *
 * @par Entrada estándar
 * - `n` (long int): número de elementos (1..N)
 * - `max` (int): límite superior del rango
 * - `min` (int): límite inferior del rango
 *
 * @par Salida estándar
 * - Lista de valores "Desordenado"
 * - Lista de valores "Ordenado"
 *
 * @par Complejidad
 * - Generación/impresión: O(n)
 * - Ordenamiento (Odd–Even Sort): O(n^2)
 * - Memoria: O(N) (arreglo estático en pila)
 *
 * @warning
 * - El intercambio usa suma/resta (sin variable temporal). Puede desbordar si los
 *   enteros son muy grandes. Para un uso robusto conviene usar una variable auxiliar.
 * - `rand() % rango` puede introducir sesgo de módulo; suficiente para fines didácticos.
 *
 * @code
 * gcc Ejemplo020.c -o Ejemplo020
 * ./Ejemplo020
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
    long int i0, i1;   /* índices del par a comparar */
    int min, max;
    int x[N];          /* arreglo de enteros */

    /* Leer n y validar rango [1, N] */
    do {
        printf("Ingrese el numero de elmentos: ");
        scanf("%ld", &n);
    } while (n < 1 || n > N);

    /* Leer rango [min, max] (si viene invertido, se corrige) */
    printf("Ingrese el valor maximo: ");
    scanf("%d", &max);
    printf("Ingrese el valor minimo: ");
    scanf("%d", &min);

    if (min > max)
    {
        /* Intercambio max <-> min sin variable auxiliar (puede desbordar en casos extremos) */
        max += min;
        min = max - min;
        max -= min;
    }

    /* Semilla del generador pseudoaleatorio */
    srand(time(NULL));

    /* Generar e imprimir arreglo desordenado */
    printf("Desordenado.\n");
    for (i = 0; i < n; i++)
    {
        x[i] = rand() % (max - min + 1) + min;
        printf("x[%ld] = %d\n", i + 1, x[i]);
    }

    /*
      ODD–EVEN SORT (Brick Sort):
      - i representa la pasada (0..n-2).
      - si i es par: compara (0,1), (2,3), ...
      - si i es impar: compara (1,2), (3,4), ...

      Aquí se implementa mapeando un índice j de pares:
        i0 = 2*j - (i%2)
        i1 = i0 + 1
    */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i % 2; j < (n + i % 2) / 2; j++)
        {
            i0 = 2 * j - i % 2;
            i1 = 2 * j + 1 - i % 2;

            /* Compare-exchange: si están invertidos, intercambia */
            if (x[i0] > x[i1])
            {
                /* Swap por suma/resta (riesgo de overflow si valores grandes) */
                x[i0] += x[i1];
                x[i1] = x[i0] - x[i1];
                x[i0] -= x[i1];
            }
        }
    }

    /* Imprimir arreglo ordenado */
    printf("Ordenado.\n");
    for (i = 0; i < n; i++)
        printf("x[%ld] = %d\n", i + 1, x[i]);

    return 0;
}
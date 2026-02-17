/**
 * @file Ejemplo018.c
 * @brief Generación de un arreglo de enteros aleatorios en el rango [min, max].
 *
 * @details
 * El programa:
 * 1) Solicita al usuario el número de elementos `n` (1 <= n <= N).
 * 2) Solicita un valor máximo y un valor mínimo.
 * 3) Si el usuario ingresa min > max, los intercambia.
 * 4) Inicializa el generador pseudoaleatorio con `srand(time(NULL))`.
 * 5) Genera `n` enteros aleatorios uniformemente distribuidos (aprox.) en el intervalo
 *    [min, max] usando:
 *      rand() % (max - min + 1) + min
 * 6) Imprime todos los elementos generados.
 *
 * @par Entrada estándar
 * - `n` (long int): número de elementos (1..N)
 * - `max` (int): valor máximo permitido
 * - `min` (int): valor mínimo permitido
 *
 * @par Salida estándar
 * Imprime el arreglo generado:
 * @code
 * x[1] = ...
 * x[2] = ...
 * ...
 * x[n] = ...
 * @endcode
 *
 * @par Restricciones
 * - `N` es el tamaño máximo del arreglo (100000).
 * - Se asume que `max - min + 1` cabe en `int`.
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(N) por el arreglo estático.
 *
 * @note
 * - La operación `rand() % rango` puede introducir “sesgo de módulo” si el rango
 *   no divide a RAND_MAX. Para fines didácticos suele ser suficiente.
 *
 * @code
 * gcc Ejemplo018.c -o Ejemplo018
 * ./Ejemplo018
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

    long int n, i;      /* n: número de elementos, i: índice de recorrido */
    int min, max;       /* límites del rango */
    int x[N];           /* arreglo con capacidad máxima N */

    /* Leer n y validar que esté en el rango [1, N]. */
    do {
        printf("Ingrese el numero de elementos: ");
        scanf("%ld", &n);
    } while (n < 1 || n > N);

    /* Leer límites del rango. */
    printf("Ingrese el valor maximo: ");
    scanf("%d", &max);

    printf("Ingrese el valor minimo: ");
    scanf("%d", &min);

    /*
      Si el usuario capturó min > max, se intercambian.
      Se usa intercambio sin variable temporal (suma/resta).
      Nota: para valores extremos podría haber overflow; en uso típico es OK.
    */
    if (min > max)
    {
        max += min;
        min = max - min;
        max -= min;
    }

    /*
      Inicializar semilla del generador pseudoaleatorio.
      time(NULL) cambia cada segundo, así que los valores cambian en cada ejecución.
    */
    srand(time(NULL));

    /*
      Generación:
      rand() % (max - min + 1) produce valores en [0, max-min]
      luego + min desplaza al intervalo [min, max].
    */
    for (i = 0; i < n; i++)
    {
        x[i] = rand() % (max - min + 1) + min;
        printf("x[%ld] = %d\n", i + 1, x[i]); /* se imprime desde 1 por estética */
    }

    return 0;
}

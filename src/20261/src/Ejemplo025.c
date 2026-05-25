/**
 * @file Ejemplo025.c
 * @brief Ordenamiento alternado por selección: mínimo a la izquierda, máximo a la derecha (floats).
 *
 * @details
 * El programa genera `n` flotantes aleatorios en [min, max] y los ordena con un método
 * tipo **selección bidireccional alternada**:
 *
 * - En pasadas pares (i par): selecciona el **mínimo** del subarreglo actual y lo coloca
 *   al inicio (izquierda).
 * - En pasadas impares (i impar): selecciona el **máximo** del subarreglo actual y lo coloca
 *   al final (derecha).
 *
 * Los límites del subarreglo se van cerrando conforme avanza:
 * - izquierda = i/2
 * - derecha   = n-1 - i/2
 *
 * Implementación:
 * - Se usa una sola variable `i` para alternar entre mínimo y máximo (según i%2).
 * - `j` recorre el rango activo en dirección apropiada.
 *
 * @par Entrada estándar
 * - `n` (int): 1 <= n <= N
 * - `max` (float)
 * - `min` (float)
 *
 * @par Salida estándar
 * - Arreglo desordenado.
 * - Arreglo ordenado.
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(N).
 *
 * @warning
 * El intercambio de `min`/`max` se hace con multiplicación/división y puede fallar si min==0 o max==0.
 * Para una versión robusta, usar una variable auxiliar.
 *
 * @code
 * gcc Ejemplo025.c -o Ejemplo025
 * ./Ejemplo025
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100000

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, i, j;
    float min, max;
    float x[N], aux;

    /* Leer n */
    do {
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
    } while (n < 1 || n > N);

    /* Leer rango */
    printf("Ingrese el valor maximo: ");
    scanf("%f", &max);
    printf("Ingrese el valor minimo: ");
    scanf("%f", &min);

    /* Asegurar min <= max (swap por mult/div: no robusto si hay ceros) */
    if (min > max)
    {
        max *= min;
        min = max / min;
        max /= min;
    }

    srand(time(NULL));

    /* Generar datos */
    printf("Desordenado.\n");
    for (i = 0; i < n; i++)
    {
        x[i] = ((max - min) * rand()) / RAND_MAX + min;
        printf("x[%02d] = %f\n", i + 1, x[i]);
    }

    /*
      Ordenamiento alternado:
      - i recorre 0..n-2
      - si i es par:
          fija posición izquierda = i/2 y busca el mínimo en [izq..der]
      - si i es impar:
          fija posición derecha = n-1-i/2 y busca el máximo en [izq..der]

      Las expresiones ternarias compactan el índice objetivo:
        objetivo = (i%2 ? n-1-i/2 : i/2)

      y recorren j en dirección adecuada según el caso.
    */
    for (i = 0; i < (n - 1); i++)
        for (j = (i % 2 ? n - 2 - i/2 : i/2 + 1);
             (i % 2 ? j > (i/2)       : j < (n - i/2));
             (i % 2 ? j--              : j++))
        {
            /*
              Comparación:
              - i par (mínimo):     si x[j] < x[i/2]  -> swap con x[i/2]
              - i impar (máximo):   si x[n-1-i/2] < x[j] -> swap con x[n-1-i/2]
            */
            if (x[i%2 ? n - 1 - i/2 : j] < x[i%2 ? j : i/2])
            {
                /* Swap clásico con auxiliar */
                aux = x[j];
                x[j] = x[i%2 ? n - 1 - i/2 : i/2];
                x[i%2 ? n - 1 - i/2 : i/2] = aux;
            }
        }

    /* Imprimir resultado */
    printf("Ordenado.\n");
    for (i = 0; i < n; i++)
        printf("x[%02d] = %f\n", i + 1, x[i]);

    return 0;
}

/**
 * @file Ejemplo010.c
 * @brief Aproximación de exp(x) con Taylor usando producto incremental dentro del término.
 *
 * @details
 * Serie:
 *   exp(x) = sum_{i=0}^{∞} x^i / i!
 *
 * Este código calcula cada término i como:
 *   fct = Π_{j=0}^{i-1} ( x / (j+1) )
 * lo cual equivale exactamente a:
 *   fct = x^i / i!
 *
 * @par Entrada
 * - Un entero n >= 1 (términos).
 * - Un real x (float).
 *
 * @par Salida
 * Imprime:
 * @code
 * exp(x) = <aprox>
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2) (por el doble ciclo). Memoria: O(1).
 *
 * @note
 * Esta forma evita manejar factorial explícito como entero, pero sigue siendo O(n^2).
 */

#include <stdio.h>

/**
 * @brief Punto de entrada. Calcula exp(x) con Taylor y producto por término.
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si finaliza correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, i, j;
    float x, fct, ex;

    do {
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Ingrese el valor de x: ");
    scanf("%f", &x);

    /*
      Para cada i:
        fct = x^i / i!  calculado como producto:
          fct = (x/1)*(x/2)*...*(x/i)
      Luego:
        ex += fct
    */
    for (i = 0, ex = 0; i < n; i++)
    {
        for (j = 0, fct = 1; j < i; j++)
            fct *= (x / (j + 1)); /* multiplica por x/(j+1) */

        ex += fct;
    }

    printf("exp(%f) = %f\n", x, ex);
    return 0;
}

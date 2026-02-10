/**
 * @file Ejemplo009.c
 * @brief Aproximación de exp(x) con serie de Taylor (cálculo directo de potencias y factorial).
 *
 * @details
 * Usa la expansión:
 *   exp(x) = sum_{i=0}^{∞} x^i / i!
 *
 * Este programa aproxima con n términos:
 *   exp(x) ≈ sum_{i=0}^{n-1} x^i / i!
 *
 * Para cada término i, calcula:
 * - num = x^i   (multiplicando x repetidamente)
 * - den = i!    (multiplicando 1*2*...*i)
 *
 * @par Entrada
 * - Un entero n >= 1 (número de términos).
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
 * @warning
 * El factorial crece muy rápido; 'den' (long int) puede desbordarse para i moderados.
 * También puede perderse precisión por usar float.
 */

#include <stdio.h>

/**
 * @brief Punto de entrada. Calcula exp(x) con Taylor y cálculo “desde cero” de cada término.
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si finaliza correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, i, j;
    long int den;     /* factorial i! (puede desbordar para i grandes) */
    float x, num, ex; /* num = x^i, ex = acumulador */

    /* Leer n >= 1 */
    do {
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    /* Leer x */
    printf("Ingrese el valor de x: ");
    scanf("%f", &x);

    /*
      ex acumula la suma:
        ex = sum_{i=0}^{n-1} x^i / i!
    */
    for (i = 0, ex = 0; i < n; i++)
    {
        /*
          Para el término i:
            num = x^i
            den = i!

          Se reinician en 1 y se multiplican i veces.
        */
        for (j = 0, num = 1, den = 1; j < i; j++)
        {
            num *= x;        /* num = x^(j+1) al avanzar */
            den *= (j + 1);  /* den = (j+1)! al avanzar */
        }

        ex += (num / den);
    }

    printf("exp(%f) = %f\n", x, ex);
    return 0;
}

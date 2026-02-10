/**
 * @file Ejemplo013.c
 * @brief Aproximación de ln(x) con serie tipo atanh usando recurrencia entre términos.
 *
 * @details
 * Se usa la misma identidad que en Ejemplo012:
 *   ln(x) = 2 * sum_{i=0}^{∞} f^{2i+1}/(2i+1),
 *   f = (x - 1) / (x + 1),  x > 0.
 *
 * A diferencia del Ejemplo012, aquí NO se recalcula la potencia desde cero.
 * Se usa la recurrencia de términos:
 *   t_i     = f^{2i+1}/(2i+1)
 *   t_{i+1} = t_i * f^2 * (2i+1)/(2i+3)
 *
 * @par Entrada
 * - Un entero n >= 1.
 * - Un real x > 0.
 *
 * @par Salida
 * Imprime:
 * @code
 * ln(x) = valor
 * @endcode
 *
 * @par Precondiciones
 * - x > 0.
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @note
 * Converge más rápido cuando x está cerca de 1 (|f| pequeño).
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, i;
    float x;        /* valor para ln(x) */
    float lnx;      /* acumulador de la serie */
    float fct;      /* f = (x-1)/(x+1) */
    float fct2;     /* f^2 */
    float suma;     /* término actual t_i = f^{2i+1}/(2i+1) */

    /* Leer n >= 1 */
    do {
        printf("Ingres el numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    /* Leer x > 0 */
    do {
        printf("Ingrese el valor de x: ");
        scanf("%f", &x);
    } while (x <= 0);

    /*
      Inicialización:
        f = (x-1)/(x+1)
        f2 = f^2
        t0 = f^(1)/1 = f
        lnx = 0
    */
    for (i = 0, fct = (x - 1) / (x + 1), lnx = 0, fct2 = fct * fct, suma = fct;
         i < n;
         i++)
    {
        /* Acumular término t_i */
        lnx += suma;

        /*
          Actualizar al siguiente término:
            t_{i+1} = t_i * f^2 * (2i+1)/(2i+3)
          (evita recalcular potencias desde cero)
        */
        suma *= (fct2 * (2*i + 1)) / (2*i + 3);
    }

    /* ln(x) = 2 * serie */
    lnx *= 2;

    printf("ln(%f) = %f\n", x, lnx);
    return 0;
}

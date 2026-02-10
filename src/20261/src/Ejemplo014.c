/**
 * @file Ejemplo014.c
 * @brief Aproximación de sen(x) con serie de Taylor calculando potencia y factorial desde cero.
 *
 * @details
 * Serie de Taylor:
 *   sen(x) = sum_{i=0}^{∞} (-1)^i * x^{2i+1} / (2i+1)!
 *
 * Este programa aproxima con n términos:
 *   sen(x) ≈ sum_{i=0}^{n-1} (-1)^i * x^{2i+1} / (2i+1)!
 *
 * Implementación:
 * - Para cada i calcula num = x^{2i+1} y den = (2i+1)! con un ciclo interno.
 *
 * @par Entrada
 * - Un entero n >= 1.
 * - Un real x.
 *
 * @par Salida
 * Imprime:
 * @code
 * sen(x) = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * Para |x| grande, puede haber pérdida de precisión (no se hace reducción de rango).
 * Además, el factorial crece rápido (aquí se guarda en int).
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, i, j;
    int den;       /* (2i+1)! */
    int signo;     /* +1 o -1 */
    float x;
    float sx;      /* acumulador de sen(x) */
    float num;     /* x^(2i+1) */

    do {
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Ingrese el valor de x: ");
    scanf("%f", &x);

    for (i = 0, sx = 0; i < n; i++)
    {
        /* signo = +1 si i par, -1 si i impar */
        signo = 1 - 2*(i % 2);

        /*
          Calcular:
            num = x^(2i+1)
            den = (2i+1)!
          multiplicando desde cero en cada término.
        */
        for (j = 0, num = 1, den = 1; j < (2*i + 1); j++)
        {
            num *= x;        /* acumula potencia */
            den *= (j + 1);  /* acumula factorial */
        }

        /* Sumar el término: (-1)^i * num/den */
        sx += (signo * num / den);
    }

    printf("sen(%f) = %f\n", x, sx);
    return 0;
}

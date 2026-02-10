/**
 * @file Ejemplo015.c
 * @brief Aproximación de sen(x) con Taylor usando producto por término (sin factorial entero explícito).
 *
 * @details
 * Serie:
 *   sen(x) = sum_{i=0}^{∞} (-1)^i * x^{2i+1} / (2i+1)!
 *
 * Para cada i, el término:
 *   x^{2i+1}/(2i+1)! = Π_{k=1}^{2i+1} (x/k)
 *
 * Este programa calcula cada término como un producto:
 *   fct = (x/1)*(x/2)*...*(x/(2i+1))
 * y alterna el signo con (-1)^i.
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
 * @note
 * Evita factorial como entero, pero sigue recalculando cada término desde cero.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, i, j;
    int signo;
    float x;
    float sx;   /* acumulador */
    float fct;  /* término positivo: x^(2i+1)/(2i+1)! */

    do {
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Ingrese el valor de x: ");
    scanf("%f", &x);

    for (i = 0, sx = 0; i < n; i++)
    {
        signo = 1 - 2*(i % 2); /* +1, -1, +1, -1... */

        /*
          fct = Π_{k=1}^{2i+1} (x/k)
          Se implementa con j=0..2i:
            multiplica x/(j+1)
        */
        for (j = 0, fct = 1; j < (2*i + 1); j++)
            fct *= (x / (j + 1));

        sx += (signo * fct);
    }

    printf("sen(%f) = %f\n", x, sx);
    return 0;
}

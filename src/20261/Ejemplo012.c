/**
 * @file Ejemplo012.c
 * @brief Aproximación de ln(x) con serie tipo atanh calculando potencias desde cero.
 *
 * @details
 * Para x > 0 se usa la identidad:
 *   ln(x) = 2 * [ f + f^3/3 + f^5/5 + ... ]
 * donde:
 *   f = (x - 1) / (x + 1)
 *
 * Entonces:
 *   ln(x) ≈ 2 * sum_{i=0}^{n-1} f^{2i+1} / (2i+1)
 *
 * Este programa:
 * - Lee n (número de términos) y x (valor real positivo).
 * - Calcula f = (x-1)/(x+1).
 * - Para cada término i calcula explícitamente f^{2i+1} multiplicando f varias veces.
 *
 * @par Entrada
 * - Un entero n >= 1 (número de términos).
 * - Un real x > 0.
 *
 * @par Salida
 * Imprime la aproximación:
 * @code
 * ln(x) = valor
 * @endcode
 *
 * @par Precondiciones
 * - x debe ser positivo (ln(x) solo está definida para x > 0 en los reales).
 *
 * @par Complejidad
 * Tiempo: O(n^2) (por el doble ciclo al calcular potencias). Memoria: O(1).
 *
 * @note
 * La convergencia es mejor cuando x está cerca de 1 (porque |f| es pequeño).
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, i, j;
    int den;               /* denominador impar: 1,3,5,... */
    float x;               /* valor para evaluar ln(x) */
    float lnx;             /* acumulador de la serie */
    float fct;             /* f = (x-1)/(x+1) */
    float num;             /* potencia: f^{den} */

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
      f = (x - 1) / (x + 1)
      y la serie es:
        ln(x) = 2 * sum_{i=0}^{n-1} f^{2i+1}/(2i+1)
    */
    for (i = 0, fct = (x - 1) / (x + 1), lnx = 0; i < n; i++)
    {
        den = 2*i + 1;  /* 1, 3, 5, ... */

        /*
          Calcular num = fct^den multiplicando fct den veces:
            num = fct * fct * ... * fct  (den factores)
        */
        for (j = 0, num = 1; j < den; j++)
            num *= fct;

        /* Sumar el término: f^{den}/den */
        lnx += num / den;
    }

    /* Multiplicar por 2 según la identidad */
    lnx *= 2;

    printf("ln(%f) = %f\n", x, lnx);
    return 0;
}

/**
 * @file Ejemplo016.c
 * @brief Aproximación de sen(x) con Taylor usando recurrencia entre términos (O(n)).
 *
 * @details
 * Serie:
 *   sen(x) = sum_{i=0}^{∞} (-1)^i * x^{2i+1} / (2i+1)!
 *
 * Definimos el término positivo:
 *   t_i = x^{2i+1} / (2i+1)!
 * con recurrencia:
 *   t_0 = x
 *   t_{i+1} = t_i * (x^2) / [(2i+2)(2i+3)]
 *
 * Luego:
 *   sen(x) ≈ sum_{i=0}^{n-1} (-1)^i * t_i
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
 * Tiempo: O(n). Memoria: O(1).
 *
 * @note
 * Es la versión más eficiente (respecto a Ejemplo014 y Ejemplo015) porque
 * evita recalcular potencias/factoriales en cada término.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, i;
    int signo;   /* +1 o -1 alternando */
    float x;
    float sx;    /* acumulador */
    float fct;   /* término positivo t_i = x^(2i+1)/(2i+1)! */

    do {
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Ingrese el valor de x: ");
    scanf("%f", &x);

    /*
      Inicialización:
        t0 = x
        sx = 0
      En cada iteración:
        sx += (-1)^i * t_i
        t_{i+1} = t_i * (x^2)/[(2i+2)(2i+3)]
    */
    for (i = 0, sx = 0, fct = x; i < n; i++)
    {
        signo = 1 - 2*(i % 2);   /* +1 si i par; -1 si i impar */

        sx += (signo * fct);

        /* Actualizar al siguiente término positivo */
        fct *= (x / (2*i + 2)) * (x / (2*i + 3));
    }

    printf("sen(%f) = %f\n", x, sx);
    return 0;
}

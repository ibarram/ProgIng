/**
 * @file Ejemplo005.c
 * @brief Solución de la ecuación cuadrática con raíces reales o complejas.
 *
 * @details
 * Resuelve:
 *   a x^2 + b x + c = 0
 * usando el discriminante:
 *   Δ = b^2 - 4ac
 *
 * Casos:
 * - Δ > 0: dos raíces reales distintas
 * - Δ = 0: una raíz real doble
 * - Δ < 0: dos raíces complejas conjugadas
 *
 * Para Δ < 0:
 *   sqrt(Δ) = i*sqrt(-Δ)
 * y las raíces se expresan como:
 *   x = (-b ± i*sqrt(-Δ)) / (2a)
 *
 * @par Entrada
 * Tres valores float, leídos por consola (a, b, c).
 *
 * @par Salida
 * Imprime las dos raíces en forma:
 *   x = real + imag*i
 *
 * @warning
 * Si a = 0 la ecuación no es cuadrática; este programa divide entre (2a).
 *
 * @par Complejidad
 * Tiempo: O(1). Memoria: O(1).
 */

#include <stdio.h>
#include <math.h>   /* sqrt() */

/**
 * @brief Punto de entrada. Calcula y muestra raíces (reales o complejas).
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si finaliza correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    float a, b, c;          /* coeficientes */
    float r;                /* discriminante Δ */
    float x1r, x1i, x2r, x2i; /* partes real/imag de cada raíz */

    printf("Ingrese el termino cuadratico: ");
    scanf("%f", &a);

    printf("Ingrese el termino lineal: ");
    scanf("%f", &b);

    printf("Ingrese el termino independiente: ");
    scanf("%f", &c);

    /* Δ = b^2 - 4ac */
    r = b*b - 4*a*c;

    /*
      Para Δ >= 0:
        x1 = (-b + sqrt(Δ)) / (2a), parte imaginaria 0
        x2 = (-b - sqrt(Δ)) / (2a), parte imaginaria 0

      Para Δ < 0:
        parte real: (-b)/(2a)
        parte imag: ± sqrt(-Δ)/(2a)
    */
    x1r = (-b + (r >= 0 ? sqrt(r) : 0)) / (2*a);
    x1i = (r >= 0 ? 0 : sqrt(-r) / (2*a));

    x2r = (-b - (r >= 0 ? sqrt(r) : 0)) / (2*a);
    x2i = (r >= 0 ? 0 : -x1i); /* conjugada */

    printf("x1 = %.4f%+.4fi\n", x1r, x1i);
    printf("x2 = %.4f%+.4fi\n", x2r, x2i);

    return 0;
}

/**
 * @file Ejemplo011.c
 * @brief Aproximación de exp(x) con Taylor usando recurrencia entre términos (forma eficiente).
 *
 * @details
 * Serie:
 *   exp(x) = sum_{i=0}^{∞} x^i / i!
 *
 * Define el término:
 *   t_i = x^i / i!
 *
 * Recurrencia:
 *   t_0 = 1
 *   t_{i+1} = t_i * (x / (i+1))
 *
 * Con esto se calcula la suma con un solo ciclo:
 *   ex = t_0 + t_1 + ... + t_{n-1}
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
 * Tiempo: O(n). Memoria: O(1).
 *
 * @note
 * Esta es la versión más eficiente de (009–011) porque evita recalcular potencias/factoriales.
 */

#include <stdio.h>

/**
 * @brief Punto de entrada. Calcula exp(x) con Taylor usando recurrencia O(n).
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si finaliza correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, i;
    float x, fct, ex;

    do {
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Ingrese el valor de x: ");
    scanf("%f", &x);

    /*
      Inicialización:
        fct = t_0 = 1
        ex  = 0

      En cada iteración i:
        ex += fct      (acumula t_i)
        fct *= x/(i+1) (convierte t_i en t_{i+1})
    */
    for (i = 0, ex = 0, fct = 1; i < n; i++)
    {
        ex += fct;
        fct *= (x / (i + 1));
    }

    printf("exp(%f) = %f\n", x, ex);
    return 0;
}

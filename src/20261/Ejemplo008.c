/**
 * @file Ejemplo008.c
 * @brief Aproximación de π mediante la serie de Leibniz.
 *
 * @details
 * Usa la serie:
 *   π/4 = 1 - 1/3 + 1/5 - 1/7 + ...
 *
 * Con n términos:
 *   π ≈ 4 * sum_{i=0}^{n-1} (-1)^i / (2i+1)
 *
 * @par Entrada
 * Un entero n >= 1 (número de términos).
 *
 * @par Salida
 * Imprime el valor aproximado:
 * @code
 * PI = <valor>
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @note
 * La convergencia es lenta: para obtener muchos decimales se requieren muchos términos.
 */

#include <stdio.h>

/**
 * @brief Punto de entrada. Calcula una aproximación de π con n términos.
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si finaliza correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    float pi;     /* acumulador para π */
    int i, n;     /* i: índice; n: términos */
    int den;      /* denominador (2i+1) */
    int signo;    /* +1 o -1 alternando */

    /* Validar n >= 1 */
    do {
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    /*
      Inicialización:
        i = 0
        pi = 0 (acumulador de π/4 antes de multiplicar por 4)
    */
    for (i = 0, pi = 0; i < n; i++)
    {
        den = 2*i + 1;           /* 1, 3, 5, 7, ... */
        signo = 1 - 2*(i % 2);   /* i par -> +1, i impar -> -1 */
        pi += (signo * 1.0f / den);
    }

    pi *= 4; /* π = 4*(π/4) */
    printf("PI = %f\n", pi);

    return 0;
}

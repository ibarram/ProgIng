/**
 * @file Ejemplo039.c
 * @brief Suma dos números reales recibidos por línea de comandos.
 *
 * @details
 * - Requiere exactamente 2 argumentos numéricos:
 *     argv[1] = A
 *     argv[2] = B
 * - Convierte con `atof()` y calcula C = A + B.
 * - Imprime con formato:
 *     A(+/-)B=C
 *
 * @par Entrada
 * @code
 * ./Ejemplo039 A B
 * @endcode
 *
 * @par Salida
 * @code
 * 1.00+2.00=3.00
 * @endcode
 *
 * @warning
 * - Si `argc != 3` el programa termina con código 1 sin imprimir mensaje (se mantiene así).
 * - `atof()` no valida errores de conversión; para robustez se recomienda `strtod()`.
 *
 * @code
 * gcc Ejemplo039.c -o Ejemplo039
 * ./Ejemplo039 1.25 -3
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float A, B, C;

    /* Se esperan 2 argumentos numéricos => argc debe ser 3 (incluye nombre del programa) */
    if (argc != 3)
        return 1;

    /* Convertir cadenas a float */
    A = (float)atof(argv[1]);
    B = (float)atof(argv[2]);

    /* Sumar */
    C = A + B;

    /* Mostrar: A(+/-)B=C */
    printf("%.2f%+.2f=%.2f\n", A, B, C);

    return 0;
}

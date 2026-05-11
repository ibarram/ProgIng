/**
 * @file Ejemplo032.c
 * @brief Demostración de macros para manipulación de bits en un entero.
 *
 * @details
 * El programa:
 * 1) Lee un entero `x`.
 * 2) Imprime su representación binaria (desde el bit más significativo).
 * 3) Permite aplicar operaciones sobre un bit `nb`:
 *    - SET: poner el bit en 1
 *    - CLEAR: poner el bit en 0
 *    - TOGGLE: invertir el bit
 *    - WRITE: escribir 0 o 1 según el valor `v`
 *
 * @par Entrada estándar
 * - `x` (int)
 * - `nb` (int): índice del bit (0..(bits-1))
 * - `v` (int): valor 0/1 (solo para WRITE)
 *
 * @par Salida estándar
 * - Representación binaria después de cada operación y el valor decimal de `x`.
 *
 * @par Complejidad
 * Tiempo: O(w) por impresión, donde w = número de bits del entero. Memoria: O(1).
 *
 * @warning
 * - Se valida que `nb` esté dentro del rango permitido para evitar desplazamientos inválidos.
 *
 * @code
 * gcc Ejemplo032.c -o Ejemplo032
 * ./Ejemplo032
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>

/* Usar 1U evita problemas de signo al desplazar */
#define BIT(n)              (1U << (n))
#define BIT_GET(x,n)        (((unsigned)(x) & BIT(n)) != 0U)
#define BIT_SET(x,n)        ((x) |=  (int)BIT(n))
#define BIT_CLEAR(x,n)      ((x) &= ~(int)BIT(n))
#define BIT_TOGGLE(x,n)     ((x) ^=  (int)BIT(n))
#define BIT_WRITE(x,n,v)    ((v) ? BIT_SET(x,n) : BIT_CLEAR(x,n))

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int x, i, nbits, nb, v;

    nbits = 8 * (int)sizeof(x);

    printf("X = ");
    scanf("%d", &x);

    /* Imprimir bits de x */
    for (i = nbits - 1; i > -1; i--)
        printf("%d ", BIT_GET(x, i) ? 1 : 0);
    printf("\n");

    /* SET */
    printf("Bit set.\n");
    do {
        printf("Numero de bit (0..%d): ", nbits - 1);
        scanf("%d", &nb);
    } while (nb < 0 || nb >= nbits);

    BIT_SET(x, nb);

    for (i = nbits - 1; i > -1; i--)
        printf("%d ", BIT_GET(x, i) ? 1 : 0);
    printf("\n");
    printf("x = %d\n", x);

    /* CLEAR */
    printf("Bit clear.\n");
    do {
        printf("Numero de bit (0..%d): ", nbits - 1);
        scanf("%d", &nb);
    } while (nb < 0 || nb >= nbits);

    BIT_CLEAR(x, nb);

    for (i = nbits - 1; i > -1; i--)
        printf("%d ", BIT_GET(x, i) ? 1 : 0);
    printf("\n");
    printf("x = %d\n", x);

    /* TOGGLE */
    printf("Bit toggle.\n");
    do {
        printf("Numero de bit (0..%d): ", nbits - 1);
        scanf("%d", &nb);
    } while (nb < 0 || nb >= nbits);

    BIT_TOGGLE(x, nb);

    for (i = nbits - 1; i > -1; i--)
        printf("%d ", BIT_GET(x, i) ? 1 : 0);
    printf("\n");
    printf("x = %d\n", x);

    /* WRITE */
    printf("Bit write.\n");
    do {
        printf("Numero de bit (0..%d): ", nbits - 1);
        scanf("%d", &nb);
    } while (nb < 0 || nb >= nbits);

    do {
        printf("Valor del bit (0/1): ");
        scanf("%d", &v);
    } while (v != 0 && v != 1);

    BIT_WRITE(x, nb, v);

    for (i = nbits - 1; i > -1; i--)
        printf("%d ", BIT_GET(x, i) ? 1 : 0);
    printf("\n");
    printf("x = %d\n", x);

    return 0;
}
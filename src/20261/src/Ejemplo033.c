/**
 * @file Ejemplo033.c
 * @brief Cálculo de paridad XOR de un mensaje y simulación de error (flip) en un bit aleatorio.
 *
 * @details
 * El programa lee una línea de texto (hasta N-1 caracteres), calcula su **paridad** como:
 * \f[
 * P = m_0 \oplus m_1 \oplus \cdots \oplus m_{n-1}
 * \f]
 * (XOR byte a byte).
 *
 * Luego simula un error de transmisión:
 * - selecciona un carácter aleatorio `nc` y un bit aleatorio `nb` (0..7)
 * - invierte ese bit del mensaje
 *
 * Después valida recalculando:
 * \f[
 * V = P \oplus m'_0 \oplus m'_1 \oplus \cdots \oplus m'_{n-1}
 * \f]
 * Si no hubo error, típicamente `V==0`. Si hubo un flip, `V` será distinto de 0.
 *
 * @par Entrada estándar
 * - Una línea de texto (puede incluir espacios), terminada en ENTER.
 *
 * @par Salida estándar
 * - Mensaje original, paridad P (en bits)
 * - Posición y bit alterados
 * - Mensaje alterado, validación V (en bits)
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(N).
 *
 * @warning
 * - Se maneja el caso de mensaje vacío para evitar `rand()%0`.
 *
 * @code
 * gcc Ejemplo033.c -o Ejemplo033
 * ./Ejemplo033
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

#define BIT(n)              (1U << (n))
#define BIT_GET(x,n)        (((unsigned)(x) & BIT(n)) != 0U)
#define BIT_TOGGLE_BYTE(x,n) ((x) ^= (unsigned char)BIT(n))

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    char msg[N];
    unsigned char P, V; /* usar unsigned evita problemas de signo */
    int i, n, nc, nb;

    srand((unsigned)time(NULL));

    /* Leer línea hasta ENTER o hasta N-1 caracteres */
    i = 0;
    do {
        msg[i] = (char)getchar();
        i++;
    } while (i < N && msg[i - 1] != '\n');

    /* Reemplazar '\n' por terminador */
    msg[i - 1] = '\0';
    n = i - 1;

    /* Caso especial: mensaje vacío */
    if (n <= 0)
    {
        printf("MSG vacio.\n");
        return 0;
    }

    /* Paridad XOR de todos los bytes */
    for (i = 0, P = 0; i < n; i++)
        P ^= (unsigned char)msg[i];

    printf("MSG: %s\n", msg);

    printf("Paridad: %u (", (unsigned)P);
    for (i = 7; i > -1; i--)
        printf("%d ", BIT_GET(P, i) ? 1 : 0);
    printf(")\n");

    /* Elegir carácter y bit a voltear */
    nc = rand() % n;
    nb = rand() % 8;
    printf("NC = %d\tNB = %d\n", nc, nb);

    /* Simular error: invertir ese bit del carácter seleccionado */
    BIT_TOGGLE_BYTE(msg[nc], nb);

    printf("MSG: %s\n", msg);

    /* Validación: V = P XOR XOR(mensaje_modificado) */
    for (i = 0, V = P; i < n; i++)
        V ^= (unsigned char)msg[i];

    printf("Validacion: %u (", (unsigned)V);
    for (i = 7; i > -1; i--)
        printf("%d ", BIT_GET(V, i) ? 1 : 0);
    printf(")\n");

    return 0;
}

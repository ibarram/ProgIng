/**
 * @file Ejemplo028.c
 * @brief Resta de matrices: C = A - B para matrices reales de tamaño n×m.
 *
 * @details
 * El programa:
 * 1) Lee las dimensiones n (renglones) y m (columnas), limitadas por N y M.
 * 2) Captura los elementos de A y B.
 * 3) Calcula C[i][j] = A[i][j] - B[i][j].
 * 4) Imprime C.
 *
 * @par Entrada estándar
 * - `n` (int): renglones, 1 <= n <= N
 * - `m` (int): columnas, 1 <= m <= M
 * - `A[i][j]` (float): n*m valores
 * - `B[i][j]` (float): n*m valores
 *
 * @par Salida estándar
 * - `C[i][j]` (float): n*m valores
 *
 * @par Complejidad
 * Tiempo: O(n*m). Memoria: O(N*M).
 *
 * @code
 * gcc Ejemplo028.c -o Ejemplo028
 * ./Ejemplo028
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 10

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, m, i, j;
    float A[N][M], B[N][M], C[N][M];

    /* Leer dimensiones */
    do {
        printf("Ingrese el numero de rengles: ");
        scanf("%d", &n);
    } while (n < 1 || n > N);

    do {
        printf("Ingrese el numero de columnas: ");
        scanf("%d", &m);
    } while (m < 1 || m > M);

    /* Capturar A */
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }

    /* Capturar B */
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            printf("B[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &B[i][j]);
        }

    /* C = A - B */
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            C[i][j] = A[i][j] - B[i][j];

    /* Imprimir C */
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            printf("C[%d][%d] = %f\n", i + 1, j + 1, C[i][j]);

    return 0;
}
/**
 * @file Ejemplo029.c
 * @brief Multiplicación de matrices: C = A * B con verificación de dimensiones.
 *
 * @details
 * El programa:
 * 1) Lee dimensiones de A: nA×mA y de B: nB×mB.
 * 2) Verifica condición de multiplicación:
 *      mA == nB
 *    Si no se cumple, termina con error.
 * 3) Captura elementos de A y B.
 * 4) Calcula C (nA×mB) usando:
 *      C[i][j] = sum_{k=0..mA-1} A[i][k] * B[k][j]
 * 5) Imprime C.
 *
 * @par Entrada estándar
 * - Dimensiones: nA, mA, nB, mB (1..N/M)
 * - Elementos de A y B (float)
 *
 * @par Salida estándar
 * - `C[i][j]` (float) para i=1..nA y j=1..mB
 *
 * @par Complejidad
 * Tiempo: O(nA*mB*mA). Memoria: O(N*M).
 *
 * @code
 * gcc Ejemplo029.c -o Ejemplo029
 * ./Ejemplo029
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

    int nA, mA, nB, mB, i, j, k;
    float A[N][M], B[N][M], C[N][M];

    /* Dimensiones */
    do {
        printf("Ingrese el numero de rengles de A: ");
        scanf("%d", &nA);
    } while (nA < 1 || nA > N);

    do {
        printf("Ingrese el numero de columnas de A: ");
        scanf("%d", &mA);
    } while (mA < 1 || mA > M);

    do {
        printf("Ingrese el numero de rengles de B: ");
        scanf("%d", &nB);
    } while (nB < 1 || nB > N);

    do {
        printf("Ingrese el numero de columnas de B: ");
        scanf("%d", &mB);
    } while (mB < 1 || mB > M);

    /* Condición para multiplicación */
    if (mA != nB)
    {
        printf("Error las columnas de A no son iguales a los renglones de B.\n");
        return 1;
    }

    /* Capturar A */
    for (i = 0; i < nA; i++)
        for (j = 0; j < mA; j++)
        {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }

    /* Capturar B */
    for (i = 0; i < nB; i++)
        for (j = 0; j < mB; j++)
        {
            printf("B[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &B[i][j]);
        }

    /* Multiplicación C = A*B */
    for (i = 0; i < nA; i++)
        for (j = 0; j < mB; j++)
            for (k = 0, C[i][j] = 0; k < mA; k++)
                C[i][j] += A[i][k] * B[k][j];

    /* Imprimir C */
    for (i = 0; i < nA; i++)
        for (j = 0; j < mB; j++)
            printf("C[%d][%d] = %f\n", i + 1, j + 1, C[i][j]);

    return 0;
}

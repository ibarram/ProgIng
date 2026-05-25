/**
 * @file Ejemplo030.c
 * @brief Resolución de un sistema lineal Ax=b por eliminación de Gauss (sin pivoteo) y sustitución hacia atrás.
 *
 * @details
 * El programa resuelve el sistema:
 *   A x = b
 * para `n` variables (n < N) usando:
 *
 * 1) Eliminación hacia adelante (triangularización):
 *    Para cada pivote i, elimina A[j][i] para j>i:
 *      fct = A[j][i] / A[i][i]
 *      fila_j = fila_j - fct * fila_i
 *      b[j]   = b[j]   - fct * b[i]
 *
 * 2) Muestra la matriz aumentada resultante [A|b] (ya triangular superior).
 *
 * 3) Sustitución hacia atrás:
 *    Recorre i = n-1 .. 0 y calcula x[i].
 *
 * @par Entrada estándar
 * - `n` (int): número de variables, 1 <= n < N
 * - Matriz A (float): n×n valores
 * - Vector b (float): n valores
 *
 * @par Salida estándar
 * - Matriz aumentada triangularizada (impresa con 4 decimales)
 * - Solución x[i]
 *
 * @par Complejidad
 * - Eliminación: O(n^3)
 * - Sustitución: O(n^2)
 * - Memoria: O(N^2)
 *
 * @warning
 * - No hay pivoteo parcial: si A[i][i] == 0 (o muy pequeño), puede haber división por cero
 *   o inestabilidad numérica. En implementación robusta se usa pivoteo.
 *
 * @code
 * gcc Ejemplo030.c -o Ejemplo030
 * ./Ejemplo030
 * @endcode
 */

#include <stdio.h>

#define N 10

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, i, j, k;
    float A[N][N], b[N], fct, x[N];

    /* Leer n con validación (nota: aquí exige n < N) */
    do {
        printf("Ingrese el numero de variables: ");
        scanf("%d", &n);
    } while (1 > n || n >= N);

    /* Capturar A y b; inicializar x */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }
        printf("b[%d] = ", i + 1);
        scanf("%f", &b[i]);
        x[i] = 0;
    }

    /*
      Eliminación hacia adelante:
      Convierte A en una matriz triangular superior.
    */
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
        {
            /* factor = A[j][i]/A[i][i] */
            for (k = 0, fct = A[j][i] / A[i][i]; k < n; k++)
                A[j][k] -= (fct * A[i][k]);

            b[j] -= (fct * b[i]);
        }

    /* Imprimir matriz aumentada [A|b] ya triangularizada */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%+.4f\t", A[i][j]);
        printf("%+.4f\n", b[i]);
    }

    /*
      Sustitución hacia atrás:
      Recorre desde la última ecuación hacia la primera.
      Nota: el código resta x[j]*A[i][j] para todo j != i.
      Como x[j] para j<i aún vale 0 en ese momento, no afecta el resultado.
    */
    for (i = n - 1; i > -1; i--)
    {
        x[i] = b[i];

        for (j = 0; j < n; j++)
            if (i != j)
                x[i] -= x[j] * A[i][j];

        x[i] /= A[i][i];
    }

    /* Imprimir solución */
    for (i = 0; i < n; i++)
        printf("x[%d] = %f\n", i + 1, x[i]);

    return 0;
}

/**
 * @file Ejemplo037.c
 * @brief Calcula la suma de OddD(k) en un intervalo [A,B] usando recursión.
 *
 * @details
 * El programa lee un entero `n` (número de casos) y, por cada caso, lee dos enteros `A` y `B`.
 * Luego imprime:
 *   Suma = SoddD(A,B)
 *
 * Donde:
 * - `OddD(X)` devuelve el "componente impar" de X:
 *   divide X entre 2 repetidamente hasta que sea impar.
 *   Ejemplo: OddD(12)=3, OddD(40)=5, OddD(8)=1.
 * - `SoddD(A,B)` suma OddD(k) para k desde A hasta B (intervalo inclusivo).
 *
 * @par Entrada estándar
 * @code
 * n
 * A1 B1
 * A2 B2
 * ...
 * An Bn
 * @endcode
 *
 * @par Salida estándar
 * Por cada caso:
 * @code
 * Suma = <valor>
 * @endcode
 *
 * @par Precondiciones
 * - Se asume A y B enteros. Si A > B, se intercambian para evitar recursión infinita.
 * - `OddD(X)` está definido en este ejemplo solo para X > 0 (para X <= 0 devuelve 0).
 *
 * @par Complejidad
 * - `OddD(X)`: O(log2(X)) en promedio (divisiones entre 2).
 * - `SoddD(A,B)`: O(|B-A|) llamadas recursivas (puede desbordar la pila si el rango es grande).
 *
 * @warning
 * Para rangos muy grandes, esta versión recursiva puede provocar stack overflow.
 *
 * @code
 * gcc Ejemplo037.c -o Ejemplo037
 * ./Ejemplo037
 * @endcode
 */

#include <stdio.h>

int OddD(int X);
int SoddD(int A, int B);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n, A, B, i, S;

    /* Lee el número de casos */
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        /* Lee el intervalo [A,B] */
        scanf("%d", &A);
        scanf("%d", &B);

        /* Calcula suma de OddD en el intervalo */
        S = SoddD(A, B);

        printf("Suma = %d\n", S);
    }

    return 0;
}

/**
 * @brief Suma OddD(k) para k en [A,B] (intervalo inclusivo).
 *
 * @details
 * Implementación recursiva:
 *   SoddD(A,B) = OddD(A) + SoddD(A+1,B), si A < B
 *   SoddD(A,B) = OddD(A),              si A == B
 *
 * Se agrega una corrección mínima:
 * - si A > B, se intercambian para evitar recursión infinita.
 *
 * @param A Límite inferior (puede venir mayor que B, se corrige).
 * @param B Límite superior.
 * @return Suma de OddD(k) para k en [A,B].
 */
int SoddD(int A, int B)
{
    /* Corrección mínima: si el usuario da A>B, se intercambia */
    if (A > B) {
        int tmp = A;
        A = B;
        B = tmp;
    }

    return OddD(A) + (A == B ? 0 : SoddD(A + 1, B));
}

/**
 * @brief Devuelve el “componente impar” de X.
 *
 * @details
 * - Si X <= 0: devuelve 0 (convención de este ejemplo).
 * - Si X es potencia de 2: devuelve 1 rápidamente.
 * - Si X es impar: devuelve X.
 * - Si X es par: devuelve OddD(X/2).
 *
 * @param X Entero.
 * @return Componente impar de X (o 0 si X<=0).
 */
int OddD(int X)
{
    /* Evita recursión infinita y define comportamiento para no-positivos */
    if (X <= 0) return 0;

    /* Si X es potencia de 2 (1,2,4,8,...) su componente impar es 1 */
    if ((X & (X - 1)) == 0)
        return 1;

    /* Si es impar, termina; si es par, divide entre 2 y continúa */
    return (X % 2) ? X : OddD(X / 2);
}

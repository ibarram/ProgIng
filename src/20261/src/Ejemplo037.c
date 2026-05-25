/**
 * @file Ejemplo037.c
 * @brief Función recursiva OddD: obtiene el “componente impar” de un entero.
 *
 * @details
 * La función `OddD(X)` devuelve el resultado de dividir X entre 2 repetidamente
 * hasta que el valor sea impar.
 *
 * Formalmente, si:
 * \f[
 * X = 2^k \cdot m,\quad \text{con } m \text{ impar}
 * \f]
 * entonces:
 * \f[
 * OddD(X) = m
 * \f]
 *
 * Ejemplos:
 * - OddD(12) = 3   (12 = 2^2 * 3)
 * - OddD(40) = 5   (40 = 2^3 * 5)
 * - OddD(7)  = 7
 *
 * @par Entrada estándar
 * Un entero A.
 *
 * @par Salida estándar
 * Imprime:
 * @code
 * OddD(A) = D
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(log2(X)) en promedio (por divisiones entre 2). Memoria: O(log2(X)) por recursión.
 *
 * @warning
 * - Si A = 0, el original entraba en recursión infinita. Aquí se corrige devolviendo 0.
 *
 * @code
 * gcc Ejemplo037.c -o Ejemplo037
 * ./Ejemplo037
 * @endcode
 */

#include <stdio.h>

int OddD(int X);

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	int A, D;

	/* Leer entero */
	scanf("%d", &A);

	/* Calcular componente impar */
	D = OddD(A);

	printf("OddD(%d) = %d", A, D);
	return 0;
}

/**
 * @brief Devuelve el resultado de dividir X entre 2 hasta obtener un número impar.
 *
 * @param X Entero.
 * @return Si X==0 devuelve 0; si X es impar devuelve X; si X es par devuelve OddD(X/2).
 */
int OddD(int X)
{
	/* Corrección mínima: evita recursión infinita para X==0 */
	if (X == 0) return 0;

	/* Caso base: si X es impar, ya terminamos */
	return (X % 2) ? X : OddD(X / 2);
}
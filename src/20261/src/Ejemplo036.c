/**
 * @file Ejemplo036.c
 * @brief Comparación de implementaciones de potencia, factorial y aproximación de exp(x).
 *
 * @details
 * Este programa ilustra distintas formas de calcular:
 * - Potencia: x^n
 *   - `pot()`  : iterativa (for)
 *   - `pot2()` : recursiva
 * - Factorial: n!
 *   - `facto()` : iterativa
 * - Aproximación de exp(x) con serie de Taylor (Maclaurin):
 *   \f[
 *     e^x = \sum_{k=0}^{\infty}\frac{x^k}{k!}
 *   \f]
 *   - `exp1(x,n)` : suma n términos (k=0..n-1) usando potencia iterativa y factorial iterativo
 *   - `exp3(x,n)` : suma n+1 términos (k=0..n) de forma recursiva usando `pot2()` y `facto()`
 *   - `exp4(x,n)` : suma n+1 términos (k=0..n) recursiva usando `fct()` que genera x^n/n!
 *
 * @par Entrada estándar
 * - `x` (float): valor real
 * - `n` (int): número de términos / exponente (n >= 0)
 *
 * @par Salida estándar
 * - x^n calculado por dos métodos
 * - n! (factorial)
 * - exp(x) aproximado por tres métodos
 *
 * @par Complejidad
 * - `pot`: O(n), `pot2`: O(n)
 * - `facto`: O(n)
 * - `exp1`: O(n^2) (por potencia+factorial dentro del ciclo)
 * - `exp3`: O(n^2) (recursión + llamadas repetidas a pot2/facto)
 * - `exp4`: O(n^2) (recursión + `fct` recursivo)
 *
 * @warning
 * - Las funciones recursivas pueden desbordar pila si n es muy grande.
 * - Para aproximar exp(x) con buena precisión se requieren más términos, especialmente si |x| es grande.
 *
 * @code
 * gcc Ejemplo036.c -o Ejemplo036
 * ./Ejemplo036
 * @endcode
 */

#include <stdio.h>

/* Prototipos */
float exp1(float x, int n);
float exp3(float x, int n);
float exp4(float x, int n);
float pot(float x, int n);
float pot2(float x, int n);
float facto(int n);
float fct(float x, int n);

/**
 * @brief Punto de entrada. Lee x y n, calcula y muestra potencia, factorial y aproximaciones de exp(x).
 */
int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;

	float x, xn, xn2, fn, ex, ex2, ex3;
	int n;

	printf("Ingrese el valor de x: ");
	scanf("%f", &x);

	/* n debe ser >= 0 para potencia, factorial y serie */
	do {
		printf("Ingrese el valor de n: ");
		scanf("%d", &n);
	} while (n < 0);

	/* x^n por dos métodos */
	xn  = pot(x, n);   /* iterativo */
	xn2 = pot2(x, n);  /* recursivo */

	/* n! */
	fn = facto(n);

	/* exp(x) por tres métodos */
	ex  = exp1(x, n);  /* suma k=0..n-1 (n términos) */
	ex2 = exp3(x, n);  /* suma k=0..n   (n+1 términos) */
	ex3 = exp4(x, n);  /* suma k=0..n   (n+1 términos) */

	printf("%f^%d = %f\n", x, n, xn);
	printf("%f^%d = %f\n", x, n, xn2);
	printf("%d! = %f\n", n, fn);
	printf("exp(%f) = %f\n", x, ex);
	printf("exp(%f) = %f\n", x, ex2);
	printf("exp(%f) = %f\n", x, ex3);

	return 0;
}

/**
 * @brief Calcula el término \f$\frac{x^n}{n!}\f$ de forma recursiva.
 *
 * @details
 * Se usa la recurrencia:
 * \f[
 * fct(x,n) = fct(x,n-1)\cdot \frac{x}{n}, \quad fct(x,0)=1
 * \f]
 *
 * @param x Valor real.
 * @param n Entero n>=0.
 * @return Valor de \f$x^n/n!\f$.
 */
float fct(float x, int n)
{
	return n ? fct(x, n-1) * (x / n) : 1.0f;
}

/**
 * @brief Aproxima exp(x) sumando términos desde 0 hasta n (incluye el término n).
 *
 * @details
 * Implementa:
 * \f[
 * e^x \approx \sum_{k=0}^{n}\frac{x^k}{k!}
 * \f]
 * usando recursión:
 * \f[
 * exp4(x,n) = exp4(x,n-1) + fct(x,n),\quad exp4(x,0)=1
 * \f]
 *
 * @param x Valor real.
 * @param n Entero n>=0.
 * @return Aproximación de exp(x).
 */
float exp4(float x, int n)
{
	return n ? exp4(x, n-1) + fct(x, n) : 1.0f;
}

/**
 * @brief Aproxima exp(x) sumando términos desde 0 hasta n (incluye el término n).
 *
 * @details
 * Implementa:
 * \f[
 * e^x \approx \sum_{k=0}^{n}\frac{x^k}{k!}
 * \f]
 * usando recursión:
 * \f[
 * exp3(x,n) = exp3(x,n-1) + \frac{x^n}{n!},\quad exp3(x,0)=1
 * \f]
 *
 * @param x Valor real.
 * @param n Entero n>=0.
 * @return Aproximación de exp(x).
 */
float exp3(float x, int n)
{
	return n ? exp3(x, n-1) + pot2(x, n) / facto(n) : 1.0f;
}

/**
 * @brief Aproxima exp(x) con n términos de la serie de Taylor (k=0..n-1).
 *
 * @details
 * Implementa:
 * \f[
 * e^x \approx \sum_{k=0}^{n-1}\frac{x^k}{k!}
 * \f]
 *
 * @param x Valor real.
 * @param n Número de términos (n>=0). Si n=0, la suma queda 0.
 * @return Aproximación de exp(x).
 */
float exp1(float x, int n)
{
	float ex;
	int i;

	for(i = 0, ex = 0.0f; i < n; i++)
		ex += pot(x, i) / facto(i);

	return ex;
}

/**
 * @brief Calcula x^n de forma recursiva.
 *
 * @param x Base.
 * @param n Exponente entero n>=0.
 * @return x^n.
 */
float pot2(float x, int n)
{
	return (n ? pot2(x, n-1) * x : 1.0f);
}

/**
 * @brief Calcula x^n de forma iterativa.
 *
 * @param x Base.
 * @param n Exponente entero n>=0.
 * @return x^n.
 */
float pot(float x, int n)
{
	float px;
	int i;

	for(i = 0, px = 1.0f; i < n; i++)
		px *= x;

	return px;
}

/**
 * @brief Calcula n! de forma iterativa.
 *
 * @param n Entero n>=0.
 * @return n! como float.
 */
float facto(int n)
{
	float fn;
	int i;

	for(i = 0, fn = 1.0f; i < n; i++)
		fn *= (i + 1);

	return fn;
}
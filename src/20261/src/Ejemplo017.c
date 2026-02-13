/**
 * @file Ejemplo017.c
 * @brief Aproximación de \f$\arcsin(x)\f$ mediante serie de Taylor (Maclaurin) para \f$|x|<1\f$.
 *
 * @details
 * Este programa aproxima el seno inverso (arcoseno):
 * \f[
 * \arcsin(x)
 * \f]
 * usando la serie de Maclaurin (Taylor alrededor de 0), válida para \f$|x|<1\f$:
 *
 * \f[
 * \arcsin(x) = \sum_{i=0}^{\infty}
 * \frac{(2i)!}{4^i (i!)^2 (2i+1)}\, x^{2i+1}, \qquad |x| < 1.
 * \f]
 *
 * En lugar de calcular factoriales grandes, la implementación construye cada término
 * de forma incremental:
 * - `num` acumula la potencia \f$x^{2i+1}\f$ a partir de la anterior (\f$\times x^2\f$).
 * - `fct` acumula el coeficiente \f$C_i=\frac{(2i)!}{4^i(i!)^2}\f$ mediante la recurrencia:
 *   \f[
 *   C_i = C_{i-1}\cdot\frac{2i-1}{2i}.
 *   \f]
 *
 * Cada iteración suma:
 * \f[
 * \frac{C_i\,x^{2i+1}}{2i+1}.
 * \f]
 *
 * @par Entrada estándar
 * 1) Un entero `n` (número de términos), con `n >= 1`  
 * 2) Un real `x` con `-1 < x < 1`
 *
 * @par Salida estándar
 * Imprime la aproximación:
 * @code
 * asen(x) = valor
 * @endcode
 *
 * @par Precondiciones
 * - Se requiere `-1 < x < 1`. La serie converge más lentamente cuando \f$|x|\to 1\f$.
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @note
 * - El programa usa `float`; si se desea mayor precisión, usar `double`.
 * - El nombre impreso es `asen(x)` (arcoseno).
 */

#include <stdio.h>

/**
 * @brief Punto de entrada. Aproxima \f$\arcsin(x)\f$ con `n` términos de la serie.
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si finaliza correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    /*
      n   : número de términos de la serie (n >= 1)
      i   : índice del término (inicia en 1 porque el término i=0 se inicializa con asx=x)
      den : denominador impar (2i+1) del término
      x   : valor para evaluar arcsin(x), con -1 < x < 1
      asx : acumulador de la suma (aproximación final)
      num : potencia acumulada x^(2i+1)
      fct : coeficiente acumulado C_i = (2i)! / (4^i (i!)^2)
    */
    int n, i, den;
    float x, asx, num, fct;

    /* Leer n >= 1 */
    do {
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    /* Leer x con -1 < x < 1 */
    do {
        printf("Ingrese el valor de x: ");
        scanf("%f", &x);
    } while (-1 >= x || x >= 1);

    /*
      Término inicial (i = 0):
        C_0 = 1
        x^(2*0+1) = x
        (2*0+1) = 1
      => arcsin(x) ≈ x
    */
    for (i = 1, asx = x, num = x, fct = 1; i < n; i++)
    {
        /*
          Actualizar coeficiente:
            C_i = C_{i-1} * (2i-1)/(2i)
          Se usa 2*i - 1.0f para forzar división en punto flotante.
        */
        fct *= ((2*i - 1.0f) / (2*i));

        /*
          Actualizar potencia:
            x^(2i+1) = x^(2i-1) * x^2
        */
        num *= (x * x);

        /* Denominador del término: (2i + 1) */
        den = (2*i + 1);

        /* Sumar término: (C_i * x^(2i+1)) / (2i+1) */
        asx += (fct * num / den);
    }

    printf("asen(%f) = %f\n", x, asx);
    return 0;
}

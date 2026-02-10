/**
 * @file Ejemplo007.c
 * @brief Cálculo del entero i tal que 1+3+5+...+(2i-1) >= n (relación con sqrt(n)).
 *
 * @details
 * El programa usa la identidad:
 *   1 + 3 + 5 + ... + (2i-1) = i^2
 *
 * Restando números impares consecutivos a rn (inicialmente rn=n), el contador i
 * se incrementa hasta que rn <= 0.
 *
 * Interpretación:
 * - Si n es un cuadrado perfecto (n = m^2), entonces al final i = m y rn llega a 0.
 * - Si n NO es cuadrado perfecto, el algoritmo termina con i = ceil(sqrt(n)).
 *
 * @par Entrada
 * Un entero n > 0.
 *
 * @par Salida
 * Imprime una línea con el formato:
 * @code
 * i^2 = n
 * @endcode
 *
 * @warning
 * El texto impreso sugiere igualdad exacta, pero si n no es cuadrado perfecto,
 * i^2 != n. El valor i corresponde a ceil(sqrt(n)).
 *
 * @par Complejidad
 * Tiempo: O(sqrt(n)). Memoria: O(1).
 */

#include <stdio.h>

/**
 * @brief Punto de entrada. Calcula i restando impares consecutivos.
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si finaliza correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n;   /* número de entrada */
    int rn;  /* “residuo” que se va reduciendo restando impares */
    int i;   /* contador de impares restados */

    /* Validar que n sea positivo */
    do {
        printf("Ingrese el valor de n: ");
        scanf("%d", &n);
    } while (n <= 0);

    rn = n;
    i = 0;

    /*
      En cada iteración se resta el siguiente impar:
        1, 3, 5, 7, ... que corresponde a (2*i+1) cuando i inicia en 0.
      Después de k iteraciones:
        rn = n - (1+3+...+(2k-1)) = n - k^2
    */
    while (rn > 0)
    {
        rn -= (2*i + 1); /* resta impar actual */
        i++;             /* incrementa contador */
    }

    /* Nota: i será sqrt(n) si n es cuadrado perfecto; si no, i = ceil(sqrt(n)) */
    printf("%d^2 = %d\n", i, n);

    return 0;
}

/**
 * @file Ejemplo004.c
 * @brief Mínimo y máximo posible de niños en equipo rojo tras exactamente K cambios.
 *
 * @details
 * N niños se dividen en dos equipos: R en rojo y N-R en azul. Exactamente K niños
 * se cambian de equipo (cada niño como máximo una vez). Se pide:
 *  - mínimo posible de niños en rojo al final
 *  - máximo posible de niños en rojo al final
 *
 * Modelado:
 * Sea x = # que cambian de rojo->azul. Entonces K-x cambian de azul->rojo.
 * Rojo final:
 *   R_final = R - x + (K - x) = R + K - 2x
 * con restricciones:
 *   0 <= x <= R
 *   0 <= K-x <= N-R
 *
 * @par Entrada
 * @code
 * N R K
 * @endcode
 *
 * @par Salida
 * Dos enteros: mínimo y máximo posibles en rojo.
 *
 * @par Restricciones
 * 1 ≤ N ≤ 1e5, 0 ≤ R,K ≤ N.
 *
 * @par Complejidad
 * Tiempo: O(1). Memoria: O(1).
 */

#include <stdio.h>

/**
 * @brief Punto de entrada. Calcula mínimo y máximo tamaño del equipo rojo.
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si finaliza correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int N, R, K, Rmn, Rmx;

    scanf("%d %d %d", &N, &R, &K);

    /*
      Mínimo:
        Se logra maximizando x (tantos rojos como sea posible se van a azul).
        x_max = min(K, R)
        Rmn = R + K - 2*x_max
        Esto equivale a |R - K|.
      El código implementa |R-K| sin if usando el signo:
        (2*(R>=K)-1) es +1 si R>=K, -1 si R<K.
    */
    Rmn = (2*(R >= K) - 1) * (R - K);

    /*
      Máximo:
        Se logra minimizando x (que se vayan lo menos posible del rojo).
        x_min = max(0, K - (N - R))
        Si K <= (N - R): Rmx = R + K
        Si K >  (N - R): Rmx = 2N - (R + K)
      El código evita if usando booleanos.
    */
    Rmx = ((N - R) < K) * 2 * N
        + (2 * ((N - R) >= K) - 1) * (R + K);

    printf("%d\t%d\n", Rmn, Rmx);
    return 0;
}

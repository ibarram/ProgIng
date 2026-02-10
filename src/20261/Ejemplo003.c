/**
 * @file Ejemplo003.c
 * @brief Máximo número de Pokémon que pueden evolucionarse con venta de no evolucionados.
 *
 * @details
 * Se tienen N Pokémon y M barras de dulce. Evolucionar un Pokémon cuesta X dulces.
 * Vender un Pokémon NO evolucionado produce Y dulces. No se puede vender un Pokémon
 * evolucionado. Se pide el máximo número de evoluciones posibles.
 *
 * Este código calcula una cota óptima usando la desigualdad:
 *   M + (N - P)·Y >= P·X
 * que se transforma en:
 *   P <= (M + N·Y) / (X + Y)
 * y finalmente P = min(N, floor((M + N·Y)/(X+Y))).
 *
 * @par Entrada
 * El enunciado indica:
 * @code
 * N M X Y
 * @endcode
 *
 * @warning
 * Este programa lee en el orden:
 * @code
 * M N X Y
 * @endcode
 * (intercambia N y M respecto al enunciado). Si vas a usar la entrada como está
 * definida en el problema, ajusta el scanf o el orden de variables.
 *
 * @par Salida
 * Un entero: máximo número de Pokémon que se pueden evolucionar.
 *
 * @par Restricciones
 * 1 ≤ N, M, X, Y ≤ 1e9.
 *
 * @note
 * Con límites de 1e9, productos como N*Y pueden exceder 32 bits. Conviene usar
 * tipos de 64 bits (long long) si se requiere robustez numérica.
 *
 * @par Complejidad
 * Tiempo: O(1). Memoria: O(1).
 */

#include <stdio.h>

/**
 * @brief Punto de entrada. Calcula el máximo de evoluciones.
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si finaliza correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    /*
      VARIABLES (según como ESTE código está leyendo la entrada):
        M = cantidad de Pokémon capturados        (enunciado lo llama N)
        N = cantidad de barras de dulce (candies) (enunciado lo llama M)
        X = costo en dulces para evolucionar 1 Pokémon
        Y = dulces que se ganan al vender 1 Pokémon (NO evolucionado)
        P = número máximo de Pokémon que se pueden evolucionar (respuesta)
    */
    int M, N, X, Y, P;

    /* Lee: M N X Y (nota: el enunciado usualmente pide N M X Y). */
    scanf("%d %d %d %d", &M, &N, &X, &Y);

    /*
      Si evolucionamos P Pokémon y vendemos los (M - P) restantes:
        dulces disponibles = N + (M - P)*Y
      Requisito para evolucionar P:
        N + (M - P)*Y >= P*X
      => N + M*Y >= P*(X + Y)
      => P <= floor((N + M*Y)/(X + Y))

      Además, P no puede ser mayor que M (no puedes evolucionar más Pokémon de los que tienes).
    */
    P = (N + Y * M) / (X + Y);

    /* Imprime min(P, M). */
    printf("%d\n", P > M ? M : P);
    return 0;
}

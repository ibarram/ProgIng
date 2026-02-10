/**
 * @file Ejemplo002.c
 * @brief Codificador de prioridad de interrupción para 4 dispositivos (D1..D4).
 *
 * @details
 * Se reciben 4 solicitudes de interrupción (una por dispositivo). La prioridad se asigna
 * de manera que el dispositivo con número más bajo tiene mayor prioridad:
 *   D1 > D2 > D3 > D4.
 *
 * La salida es el número del dispositivo seleccionado codificado en binario (3 bits):
 *   - Ninguno -> 0  (000)
 *   - D1      -> 1  (001)
 *   - D2      -> 2  (010)
 *   - D3      -> 3  (011)
 *   - D4      -> 4  (100)
 *
 * @par Entrada
 * Cuatro enteros (0/1) en este orden:
 * @code
 * D4 D3 D2 D1
 * @endcode
 *
 * @par Salida
 * Un renglón con:
 * - el valor decimal seleccionado (0..4)
 * - y los bits de salida (b2 b1 b0) solo como depuración.
 *
 * @par Precondiciones
 * Las entradas deben ser booleanas (0 o 1) para que el comportamiento sea el esperado.
 *
 * @par Complejidad
 * Tiempo: O(1). Memoria: O(1).
 */

#include <stdio.h>

/**
 * @brief Punto de entrada. Implementa el codificador de prioridad 4→3 bits.
 * @param argc Cantidad de argumentos de línea de comandos (no se usa).
 * @param argv Argumentos de línea de comandos (no se usa).
 * @return 0 si finaliza correctamente; 1 si falla la lectura.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    /* Entradas: solicitud de interrupción por dispositivo (0/1). */
    int D4, D3, D2, D1;

    /* Bits de salida: b2 b1 b0 (representan 0..4). */
    int b2, b1, b0;

    /* Salida decimal equivalente a (b2 b1 b0). */
    int salida;

    /* Se leen las entradas en el orden: D4 D3 D2 D1. */
    if (scanf("%d %d %d %d", &D4, &D3, &D2, &D1) != 4) {
        printf("Error: se esperaban 4 valores (D4 D3 D2 D1).\n");
        return 1;
    }

    /*
      Lógica de prioridad (D1 mayor prioridad):

      Para “habilitar” un dispositivo de menor prioridad, se exige que NO haya
      dispositivos de mayor prioridad activos.

      b2 debe ser 1 solo cuando gana D4 (100):
        b2 = D4 · ¬D3 · ¬D2 · ¬D1
    */
    b2 = D4 && (!D3) && (!D2) && (!D1);

    /*
      b1 es 1 cuando la salida es 2 (010) o 3 (011):
        - Para 3: D3 · ¬D2 · ¬D1
        - Para 2: D2 · ¬D1
      => b1 = (D3 · ¬D2 · ¬D1) + (D2 · ¬D1)
    */
    b1 = (D3 && (!D2) && (!D1)) || (D2 && (!D1));

    /*
      b0 es 1 cuando la salida es 1 (001) o 3 (011):
        - Para 1: D1
        - Para 3: D3 · ¬D2 · ¬D1
      => b0 = D1 + (D3 · ¬D2 · ¬D1)
    */
    b0 = (D1) || (D3 && (!D2) && (!D1));

    /* Convertir (b2 b1 b0) a decimal: salida = b2*4 + b1*2 + b0. */
    salida = (b2 << 2) | (b1 << 1) | b0;

    printf("Salida = %d (%1d %1d %1d)\n", salida, b2, b1, b0);
    return 0;
}

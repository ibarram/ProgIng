/**
 * @file Ejemplo001.c
 * @brief Hola mundo mínimo: imprime un mensaje en consola.
 *
 * @details
 * Programa introductorio en C para verificar compilación y ejecución.
 *
 * @par Entrada
 * Ninguna.
 *
 * @par Salida
 * Imprime la cadena "Universidad de Guanajuato" seguida de salto de línea.
 *
 * @par Complejidad
 * Tiempo: O(1). Memoria: O(1).
 *
 * @note
 * Compilación sugerida:
 * @code
 * gcc Ejemplo001.c -o Ejemplo001
 * ./Ejemplo001
 * @endcode
 */

#include <stdio.h>

/**
 * @brief Punto de entrada del programa.
 * @param argc Cantidad de argumentos de línea de comandos.
 * @param argv Arreglo de cadenas con argumentos.
 * @return 0 si termina correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    printf("Universidad de Guanajuato\n");
    return 0;
}

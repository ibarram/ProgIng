/**
 * @file Ejemplo038.c
 * @brief Imprime la cantidad de argumentos y lista argv[i].
 *
 * @details
 * Programa demostrativo del uso de parámetros de línea de comandos:
 * - `argc`: número de argumentos (incluye el nombre del programa).
 * - `argv`: arreglo de cadenas con cada argumento.
 *
 * @par Entrada
 * Argumentos en la línea de comandos.
 *
 * @par Salida
 * Imprime `argc` y luego cada `argv[i]`.
 *
 * @code
 * gcc Ejemplo038.c -o Ejemplo038
 * ./Ejemplo038 uno dos tres
 * @endcode
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    printf("# argumentos: %d\n", argc);

    for (i = 0; i < argc; i++)
        printf("%d. %s\n", i, argv[i]);

    return 0;
}

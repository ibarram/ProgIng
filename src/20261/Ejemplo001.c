/**
 * @file Ejemplo001.c
 * @brief Programa mínimo en C que imprime un mensaje en pantalla.
 *
 * Este programa muestra la cadena "Universidad de Guanajuato" y termina.
 */

#include <stdio.h>  // Biblioteca estándar de entrada/salida: habilita printf(), scanf(), etc.

/**
 * @brief Función principal (punto de entrada) del programa.
 *
 * En C, la ejecución inicia en main().
 *
 * @param argc  "argument count": número de argumentos recibidos desde la línea de comandos.
 *              - Siempre es >= 1, porque incluye el nombre del programa.
 * @param argv  "argument vector": arreglo de cadenas (char*) con los argumentos.
 *              - argv[0] suele ser el nombre o ruta del ejecutable.
 *
 * @return 0 si el programa terminó correctamente (convención en C/Unix).
 */
int main(int argc, char *argv[])
{
    // (Opcional) Evitar advertencias de compilación si no usamos argc/argv
    (void)argc;
    (void)argv;

    /**
     * printf() imprime texto en la salida estándar (la consola).
     * "\n" es un salto de línea para que el cursor baje a la siguiente línea.
     */
    printf("Universidad de Guanajuato\n");

    // Termina el programa indicando "éxito".
    return 0;
}

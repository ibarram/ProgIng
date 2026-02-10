/**
 * @file Ejemplo006.c
 * @brief Etiquetado de una temperatura T usando 4 umbrales (T1<T2<T3<T4) y 5 categorías.
 *
 * @details
 * El programa lee cuatro umbrales de temperatura (T1, T2, T3, T4) y luego una
 * temperatura T que se desea clasificar. Se generan 5 regiones:
 *
 *  1) T <  T1           -> "Muy baja"
 *  2) T1 <= T < T2      -> "Baja"
 *  3) T2 <= T < T3      -> "Templada"
 *  4) T3 <= T < T4      -> "Alta"
 *  5) T >= T4           -> "Muy alta"
 *
 * La clasificación se implementa con 4 banderas booleanas (B1..B4) y se empaquetan
 * en un código de 4 bits (B4B3B2B1) para seleccionar el mensaje mediante switch().
 *
 * @par Entrada
 * Dos lecturas desde stdin:
 * @code
 * T1 T2 T3 T4
 * T
 * @endcode
 *
 * @par Salida
 * Imprime un código de depuración B (y sus bits) y una etiqueta textual:
 * "muy baja", "baja", "templada", "alta" o "muy alta".
 *
 * @par Precondiciones
 * - Se asume el orden: T1 < T2 < T3 < T4.
 *
 * @par Complejidad
 * Tiempo: O(1). Memoria: O(1).
 *
 * @note
 * Si los umbrales no están ordenados, pueden aparecer códigos no contemplados
 * y el programa podría no imprimir etiqueta (cae en default).
 */

#include <stdio.h>

/**
 * @brief Punto de entrada. Clasifica la temperatura T en 5 regiones usando umbrales.
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si termina correctamente.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    /*
      T1, T2, T3, T4: Umbrales de temperatura que delimitan 5 regiones.
        - T1: umbral inferior (más frío)
        - T4: umbral superior (más caliente)
        - Se asume el orden: T1 < T2 < T3 < T4

      T: temperatura a clasificar (etiquetar).
    */
    float T1, T2, T3, T4, T;

    /*
      B1..B4 son banderas (booleanos como enteros 0/1) que indican si T es menor
      que cada umbral, usando comparaciones del tipo (Ti > T).

      Ejemplo:
        B1 = (T1 > T)  -> 1 si T es menor que T1
                         0 si T es mayor o igual que T1
    */
    int B1, B2, B3, B4;

    /*
      B será un "código" de 4 bits (B4 B3 B2 B1) que identifica en qué intervalo cae T.
      Luego se usa switch(B) para imprimir la etiqueta.
    */
    int B;

    /* --- Lectura de umbrales --- */
    printf("Ingrese los rangos de temperaturas: ");
    scanf("%f %f %f %f", &T1, &T2, &T3, &T4);

    /* --- Lectura de la temperatura a evaluar --- */
    printf("Ingrese la tempratura: ");
    scanf("%f", &T);

    /*
      Se calcula cada bandera:
      - B1 = 1 si T < T1
      - B2 = 1 si T < T2
      - B3 = 1 si T < T3
      - B4 = 1 si T < T4

      (Usa Ti > T, que es equivalente a T < Ti)
    */
    B1 = (T1 > T);
    B2 = (T2 > T);
    B3 = (T3 > T);
    B4 = (T4 > T);

    /*
      Empaquetar (B4 B3 B2 B1) en un entero B usando desplazamientos:
        B4 << 3  coloca B4 en el bit 3 (valor 8)
        B3 << 2  coloca B3 en el bit 2 (valor 4)
        B2 << 1  coloca B2 en el bit 1 (valor 2)
        B1       queda en el bit 0 (valor 1)

      Resultado:
        B = (B4*8) + (B3*4) + (B2*2) + (B1*1)
    */
    B = (B4 << 3) | (B3 << 2) | (B2 << 1) | (B1);

    /* Depuración: imprime B y sus bits B4B3B2B1 */
    printf("%d (%d%d%d%d)\n", B, B4, B3, B2, B1);

    printf("La temperatura es ");

    /*
      Para T1<T2<T3<T4, los códigos típicos son:
        T < T1        -> 1111 (15) -> "muy baja"
        T1<=T<T2      -> 1110 (14) -> "baja"
        T2<=T<T3      -> 1100 (12) -> "templada"
        T3<=T<T4      -> 1000 ( 8) -> "alta"
        T>=T4         -> 0000 ( 0) -> "muy alta"
    */
    switch (B)
    {
        case 15:
            printf("muy ");
            /* fall-through intencional: completa con "baja" */
        case 14:
            printf("baja\n");
            break;

        case 12:
            printf("templada\n");
            break;

        case 0:
            printf("muy ");
            /* fall-through intencional: completa con "alta" */
        case 8:
            printf("alta\n");
            break;

        default:
            /* Código no contemplado (p.ej. umbrales desordenados) */
            break;
    }

    printf("\n");
    return 0;
}

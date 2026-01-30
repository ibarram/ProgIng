#include <stdio.h>

int main(int argc, char *argv[])
{
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
        B1 = (T1 > T)  -> 1 si T es menor que T1 (muy fría)
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
    B1 = T1 > T;
    B2 = T2 > T;
    B3 = T3 > T;
    B4 = T4 > T;

    /*
      Empaquetar (B4 B3 B2 B1) en un entero B usando desplazamientos:
        B4 << 3  coloca B4 en el bit 3 (valor 8)
        B3 << 2  coloca B3 en el bit 2 (valor 4)
        B2 << 1  coloca B2 en el bit 1 (valor 2)
        B1       queda en el bit 0 (valor 1)

      Operador | (OR bit a bit) combina los bits en un solo número.

      Resultado:
        B = (B4*8) + (B3*4) + (B2*2) + (B1*1)

      Esto produce códigos distintos dependiendo del intervalo de T.
    */
    B = (B4 << 3) | (B3 << 2) | (B2 << 1) | (B1);

    /* Imprimir el valor de B y su forma binaria (B4B3B2B1) para depuración */
    printf("%d (%d%d%d%d)\n", B, B4, B3, B2, B1);

    printf("La temperatura es ");

    /*
      Interpretación de los códigos más relevantes si T1<T2<T3<T4:

      1) T < T1:
         T es menor que todos los umbrales
         B1=B2=B3=B4=1  -> (1111)b = 15
         Etiqueta: "muy baja"

      2) T1 <= T < T2:
         - Ya no se cumple T < T1, pero sí T < T2, T < T3, T < T4
         B1=0, B2=1, B3=1, B4=1 -> (1110)b = 14
         Etiqueta: "baja"

      3) T2 <= T < T3:
         B1=0, B2=0, B3=1, B4=1 -> (1100)b = 12
         Etiqueta: "templada"

      4) T3 <= T < T4:
         B1=0, B2=0, B3=0, B4=1 -> (1000)b = 8
         Etiqueta: "alta"

      5) T >= T4:
         - T no es menor que ningún umbral
         B1=B2=B3=B4=0 -> (0000)b = 0
         Etiqueta: "muy alta"
    */

    switch (B)
    {
        /*
          Caso 15 (1111): T < T1  -> "muy baja"
          Nota: NO hay break a propósito después de imprimir "muy "
          para que "caiga" al caso 14 e imprima "baja".
        */
        case 15:
            printf("muy ");   // imprime "muy "
            /* fall-through intencional */
        case 14:
            printf("baja\n"); // completa "baja"
            break;

        /* Caso 12 (1100): T2 <= T < T3 -> "templada" */
        case 12:
            printf("templada\n");
            break;

        /*
          Caso 0 (0000): T >= T4 -> "muy alta"
          Igual que antes: se imprime "muy " y cae al caso 8 para imprimir "alta".
        */
        case 0:
            printf("muy ");   // imprime "muy "
            /* fall-through intencional */
        case 8:
            printf("alta\n"); // completa "alta"
            break;

        /*
          default: si los umbrales no están ordenados (o hay igualdad rara),
          podría aparecer un código no contemplado (por ejemplo 10, 6, etc.).
          En ese caso, no imprime etiqueta.
        */
        default:
            break;
    }

    printf("\n");
    return 0;
}

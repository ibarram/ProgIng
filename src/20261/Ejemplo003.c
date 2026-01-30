#include <stdio.h>

int main(int argc, char *argv[])
{
    /*
      VARIABLES (según como ESTE código está leyendo la entrada):
        M = cantidad de Pokémon capturados        (enunciado lo llama N)
        N = cantidad de barras de dulce (candies) (enunciado lo llama M)
        X = costo en dulces para evolucionar 1 Pokémon
        Y = dulces que se ganan al vender 1 Pokémon (NO evolucionado)
        P = número máximo de Pokémon que se pueden evolucionar (respuesta)
    */
    int N, M, X, Y, P;

    /*
      LECTURA:
      Aquí se leen 4 enteros en este orden:
         N M X Y
    */
    scanf("%d %d %d %d", &N, &M, &X, &Y);

    /*
      IDEA MATEMÁTICA / RAZONAMIENTO:

      Queremos maximizar P = #evoluciones.

      - Evolucionar cuesta X dulces por Pokémon.
      - Vender (solo no evolucionados) da Y dulces por Pokémon vendido.
      - No podemos vender un Pokémon evolucionado.

      Si evolucionamos P Pokémon:
        - Nos quedan (M - P) Pokémon NO evolucionados.
        - Para maximizar dulces disponibles, podemos vender TODOS esos (M - P).
          (No tiene desventaja si ya decidimos que no los vamos a evolucionar.)

      Dulces disponibles si vendemos todos los no evolucionados:
        dulces_totales = N + (M - P)*Y

      Para poder evolucionar P Pokémon debe cumplirse:
        N + (M - P)*Y  >=  P*X

      Reacomodando:
        N + M*Y - P*Y >= P*X
        N + M*Y       >= P*(X + Y)

      Entonces:
        P <= (N + M*Y) / (X + Y)

      Como P debe ser entero:
        P_max = floor((N + M*Y) / (X + Y))

      Además, no puedes evolucionar más Pokémon de los que tienes:
        P_max <= M
    */

    // Cálculo directo usando división entera (equivale a floor).
    P = (N + Y * M) / (X + Y);

    /*
      Impresión de la respuesta:

      La expresión  (P > M ? M : P)  significa:
        - si P es mayor que M, imprime M
        - si no, imprime P

      O sea, imprime min(P, M).
    */
    printf("%d\n", P > M ? M : P);

    return 0;
}

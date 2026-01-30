#include <stdio.h>

int main(int argc, char *argv[])
{
    /*
      Problema:
      - Hay N niños.
      - Inicialmente R están en el equipo rojo.
      - Entonces (N - R) están en el equipo azul.
      - Exactamente K niños cambian de equipo (cada niño a lo más una vez).

      Se pide:
      - El mínimo posible de niños en rojo después de los K cambios.
      - El máximo posible de niños en rojo después de los K cambios.
    */

    int N, R, K;     // N: total, R: rojos iniciales, K: número exacto de cambios
    int Rmn, Rmx;    // Rmn: mínimo rojos posibles, Rmx: máximo rojos posibles

    scanf("%d %d %d", &N, &R, &K);

    /*
      IDEA CLAVE:
      Sea x = número de niños que cambian de ROJO -> AZUL.
      Entonces, como en total cambian K niños, el resto (K - x) cambian de AZUL -> ROJO.

      Rojo final:
        R_final = R - x + (K - x) = R + K - 2x

      Restricciones para x:
        - No pueden salir más rojos de los que existen: x <= R
        - No pueden entrar más azules de los que existen: (K - x) <= (N - R)

      Así, x está acotado por:
        x_min = max(0, K - (N - R))     // mínimo rojos que "tienen que" salir si faltan azules
        x_max = min(K, R)              // máximo rojos que pueden salir

      Como R_final = R + K - 2x:
        - Para MINIMIZAR R_final, conviene MAXIMIZAR x  -> usar x_max
        - Para MAXIMIZAR R_final, conviene MINIMIZAR x  -> usar x_min
    */

    /* ------------------------------------------------------------
       CÁLCULO DEL MÍNIMO (Rmn)
       ------------------------------------------------------------
       Rmn = R + K - 2*x_max, con x_max = min(K, R)

       Si K <= R  => x_max = K  => Rmn = R + K - 2K = R - K
       Si K >  R  => x_max = R  => Rmn = R + K - 2R = K - R

       En resumen:
         Rmn = |R - K|

       El código evita usar if y calcula |R-K| usando un truco:
         (R>=K) es 1 si true, 0 si false
         2*(R>=K) - 1 produce:
            +1 si R>=K
            -1 si R<K

         Entonces:
           (2*(R>=K)-1)*(R-K) = (signo)*(R-K) = |R-K|
    */
    Rmn = (2*(R>=K)-1) * (R-K);

    /* ------------------------------------------------------------
       CÁLCULO DEL MÁXIMO (Rmx)
       ------------------------------------------------------------
       Rmx = R + K - 2*x_min, con x_min = max(0, K - (N - R))

       Sea B = N - R  (azules iniciales).

       Caso 1) Si K <= B:
           x_min = 0
           Rmx = R + K
           (se puede hacer que todos los que cambian sean azules->rojos)

       Caso 2) Si K > B:
           No hay suficientes azules para que todos entren al rojo.
           Forzosamente deben salir rojos para completar K cambios.
           x_min = K - B

           Rmx = R + K - 2*(K - B)
               = R + K - 2K + 2B
               = R - K + 2(N - R)
               = 2N - (R + K)

       El código vuelve a evitar if usando booleanos:

         ((N-R) < K) es 1 si B<K, 0 si no.
         (2*((N-R)>=K) - 1) vale:
             +1 si B>=K
             -1 si B<K

       Entonces:
         - Si B>=K:
             primer término = 0
             segundo término = +1*(R+K)
             => Rmx = R+K
         - Si B<K:
             primer término = 2N
             segundo término = -1*(R+K)
             => Rmx = 2N - (R+K)
    */
    Rmx = ((N-R) < K) * 2*N
        + (2*((N-R) >= K) - 1) * (R + K);

    /*
      Imprime:
      - mínimo posible en rojo (Rmn)
      - máximo posible en rojo (Rmx)
      separados por tabulación.
    */
    printf("%d\t%d\n", Rmn, Rmx);

    return 0;
}

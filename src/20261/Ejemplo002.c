#include <stdio.h>

/*
  Problema:
  Diseñar un codificador de prioridad de interrupción con 4 entradas (D1..D4).
  - D1 tiene la prioridad más alta (número más bajo).
  - D4 tiene la prioridad más baja (número más alto).
  - La salida debe ser el número del dispositivo en binario:
        Ninguno -> 0  (000)
        D1      -> 1  (001)
        D2      -> 2  (010)
        D3      -> 3  (011)
        D4      -> 4  (100)

  Convención de entrada en este programa:
  Se leen 4 enteros en este orden: D4 D3 D2 D1
  (así lo define tu scanf original).
*/

int main(int argc, char *argv[])
{
    (void)argc;  // No se usan argumentos de línea de comandos
    (void)argv;

    // D1..D4 representan si cada dispositivo está solicitando interrupción:
    // 0 = no solicita, 1 = solicita.
    int D4, D3, D2, D1;

    // Bits de salida (b2 b1 b0) para representar el número del dispositivo ganador.
    int b2, b1, b0;

    // Salida decimal (equivalente a los bits b2b1b0).
    int salida;

    // Leer las entradas. Ejemplo de entrada:
    // 0 1 0 0  -> D4=0 D3=1 D2=0 D1=0  (ganaría D3 -> salida 3)
    if (scanf("%d %d %d %d", &D4, &D3, &D2, &D1) != 4) {
        printf("Error: se esperaban 4 valores (D4 D3 D2 D1).\n");
        return 1;
    }

    /*
      Idea del codificador de prioridad:

      Queremos que gane el dispositivo de menor número:
      - Si D1=1, la salida debe ser 1 sin importar D2,D3,D4.
      - Si D1=0 y D2=1, la salida debe ser 2 (aunque D3,D4 estén en 1).
      - Si D1=0, D2=0 y D3=1, la salida debe ser 3.
      - Si D1=0, D2=0, D3=0 y D4=1, la salida debe ser 4.
      - Si todos son 0, la salida es 0.

      Para implementar eso en forma “lógica combinacional”, se habilita cada
      dispositivo solo si NO existe uno de mayor prioridad activo.
    */

    /*
      b2 debe ser 1 solo para el número 4 (100), es decir:
      - D4 activo
      - y ninguno de los de mayor prioridad (D1,D2,D3) activo
      b2 = D4 · ¬D3 · ¬D2 · ¬D1
    */
    b2 = D4 && (!D3) && (!D2) && (!D1);

    /*
      b1 es 1 para números 2 (010) y 3 (011).
      Casos:
      - Para 3: D3 activo y NO hay D1 ni D2 activos
               D3 · ¬D2 · ¬D1
      - Para 2: D2 activo y NO hay D1 activo
               D2 · ¬D1
      Entonces:
      b1 = (D3 · ¬D2 · ¬D1) + (D2 · ¬D1)
    */
    b1 = (D3 && (!D2) && (!D1)) || (D2 && (!D1));

    /*
      b0 es 1 para números 1 (001) y 3 (011).
      Casos:
      - Para 1: D1 activo (gana siempre)
               D1
      - Para 3: D3 activo y NO hay D1 ni D2 activos
               D3 · ¬D2 · ¬D1
      Entonces:
      b0 = D1 + (D3 · ¬D2 · ¬D1)
    */
    b0 = (D1) || (D3 && (!D2) && (!D1));

    /*
      Convertir (b2 b1 b0) a decimal:
      salida = b2*4 + b1*2 + b0*1
      Usamos desplazamientos para que se vea “binario”:
    */
    salida = (b2 << 2) | (b1 << 1) | b0;

    // Mostrar resultado en decimal y en bits.
    printf("Salida = %d (%1d %1d %1d)\n", salida, b2, b1, b0);

    return 0;
}

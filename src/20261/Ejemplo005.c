#include <stdio.h>
#include <math.h>   // sqrt()

int main(int argc, char *argv[])
{
    /*
      a, b, c: coeficientes de la ecuación cuadrática
          a*x^2 + b*x + c = 0

      r: discriminante (también llamado Δ)
          r = b^2 - 4ac

      x1r, x1i: parte real e imaginaria de la raíz x1
      x2r, x2i: parte real e imaginaria de la raíz x2

      Nota: se usan float (precisión simple). Para mejor precisión numérica,
      suele preferirse double en problemas reales.
    */
    float a, b, c;
    float r;
    float x1r, x1i, x2r, x2i;

    /* --- Lectura de coeficientes --- */
    printf("Ingrese el termino cuadratico: ");   // coeficiente 'a'
    scanf("%f", &a);

    printf("Ingrese el termino lineal: ");       // coeficiente 'b'
    scanf("%f", &b);

    printf("Ingrese el termino independiente: "); // coeficiente 'c'
    scanf("%f", &c);

    /*
      Discriminante:
        r = b^2 - 4ac

      - Si r > 0: dos raíces reales distintas
      - Si r = 0: una raíz real doble (ambas iguales)
      - Si r < 0: dos raíces complejas conjugadas
    */
    r = b*b - 4*a*c;

    /*
      Fórmula general:
        x = (-b ± sqrt(r)) / (2a)

      Cuando r < 0, sqrt(r) no es real. Se usa:
        sqrt(r) = i * sqrt(-r)

      Entonces:
        x = (-b ± i*sqrt(-r)) / (2a)

      El código maneja ambos casos con un operador ternario:

      - Si r >= 0: usa sqrt(r) en la parte real y parte imaginaria = 0
      - Si r < 0 : NO suma sqrt(r) (porque no existe real), y calcula la parte
                   imaginaria con sqrt(-r)/(2a)
    */

    /* -------------------------------
       Raíz 1 (x1 = x1r + i*x1i)
       ------------------------------- */

    /*
      Parte real de x1:
      - Si r >= 0: (-b + sqrt(r)) / (2a)
      - Si r < 0 : (-b + 0)       / (2a) = (-b)/(2a)
    */
    x1r = (-b + (r >= 0 ? sqrt(r) : 0)) / (2*a);

    /*
      Parte imaginaria de x1:
      - Si r >= 0: 0
      - Si r < 0 : sqrt(-r) / (2a)
        (esto implementa:  i*sqrt(-r)/(2a)  como “coeficiente” de i)
    */
    x1i = (r >= 0 ? 0 : sqrt(-r) / (2*a));

    /* -------------------------------
       Raíz 2 (x2 = x2r + i*x2i)
       ------------------------------- */

    /*
      Parte real de x2:
      - Si r >= 0: (-b - sqrt(r)) / (2a)
      - Si r < 0 : (-b - 0)       / (2a) = (-b)/(2a)
    */
    x2r = (-b - (r >= 0 ? sqrt(r) : 0)) / (2*a);

    /*
      Parte imaginaria de x2:
      - Si r >= 0: 0
      - Si r < 0 : -x1i  (conjugada de x1)
        Porque cuando las raíces son complejas, vienen en pares conjugados:
          (p + qi) y (p - qi)
    */
    x2i = (r >= 0 ? 0 : -x1i);

    /*
      Impresión:
      "%.4f%+.4fi" imprime:
      - parte real con 4 decimales
      - parte imaginaria con signo explícito (+ o -) y 4 decimales

      Ejemplo:
        x1 = 1.5000+0.0000i
        x1 = -2.0000-3.0000i
    */
    printf("x1 = %.4f%+.4fi\n", x1r, x1i);
    printf("x2 = %.4f%+.4fi\n", x2r, x2i);

    return 0;
}

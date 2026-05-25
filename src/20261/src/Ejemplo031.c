/**
 * @file Ejemplo031.c
 * @brief Generación de datos aleatorios y transformación por centrado/normalización (min–max o z-score).
 *
 * @details
 * Este programa genera un arreglo `x[]` con `n` valores aleatorios en el rango [mn_X, mx_X] y
 * calcula estadísticas básicas: mínimo, máximo, media y varianza (poblacional).
 *
 * Posteriormente genera un arreglo `z[]` aplicando una transformación opcional:
 *
 * - **Centrar**: restar un valor de referencia `a`
 * - **Normalizar**: dividir entre un factor de escala `b`
 *
 * De modo que:
 * \f[
 * z_i = \frac{x_i - a}{b}
 * \f]
 *
 * Métodos disponibles:
 * 1) **Máximo–Mínimo**
 *    - Centrar:  a = min
 *    - Normalizar: b = (max - min)
 *    - Con ambas opciones: z = (x - min)/(max-min)
 *
 * 2) **z-score**
 *    - Centrar:  a = media
 *    - Normalizar: b = sqrt(varianza)
 *    - Con ambas opciones: z = (x - media)/std
 *
 * @par Entrada estándar
 * - `n` (int): número de elementos, 1 <= n <= N
 * - `mx_X` (float): valor máximo del rango de generación
 * - `mn_X` (float): valor mínimo del rango de generación
 * - `op1` (int): ¿Quieres centrar? (0/1)
 * - `op2` (int): ¿Quieres normalizar? (0/1)
 * - `op3` (int): método (1=Max–Min, 2=z-score) si op1 u op2 son 1
 *
 * @par Salida estándar
 * - Máximo, mínimo, media y varianza
 * - Tabla con: índice, x[i] y z[i]
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(N).
 *
 * @warning
 * - Si `max==min` (rango 0) o `varianza==0`, entonces `b` puede ser 0 y la división no es válida.
 *   (Este ejemplo asume datos suficientemente variados; en uso robusto conviene validar `b`.)
 *
 * @code
 * gcc Ejemplo031.c -o Ejemplo031 -lm
 * ./Ejemplo031
 * @endcode
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 10000

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    float x[N], z[N];
    float mx_X, mn_X;          /* rango de generación */
    float min, max, media, varianza;
    float a, b;                /* parámetros de la transformación z=(x-a)/b */

    int i, n;
    int bandera;               /* máscara de bits para elegir a y b */
    int op1, op2, op3 = 0;     /* op3 se inicializa para evitar uso sin definir */

    srand((unsigned int)time(NULL));

    /* Leer n */
    do {
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
    } while (n < 1 || n > N);

    /* Leer rango [mn_X, mx_X] */
    printf("Ingrese el valor maximo: ");
    scanf("%f", &mx_X);
    printf("Ingrese el valor minimo: ");
    scanf("%f", &mn_X);

    /*
      Asegurar mn_X <= mx_X.
      El intercambio usa multiplicación/división con casos especiales para ceros.
    */
    if (mx_X < mn_X)
    {
        if (mx_X && mn_X)
        {
            mx_X *= mn_X;
            mn_X = mx_X / mn_X;
            mx_X /= mn_X;
        }
        else if (mx_X)
        {
            mn_X = mx_X;
            mx_X = 0;
        }
        else if (mn_X)
        {
            mx_X = mn_X;
            mn_X = 0;
        }
        else
            mx_X = mn_X + 1; /* ambos eran 0: fuerza un rango no degenerado */
    }

    /* Opciones del usuario */
    printf("¿Quieres centrar?: ");
    scanf("%d", &op1);
    printf("¿Quieres normalizar?: ");
    scanf("%d", &op2);

    if (op1 || op2)
    {
        printf("Menu:\n");
        printf("1. Maximo-Minimo.\n");
        printf("2. z-score.\n");
        printf("Opción: ");
        scanf("%d", &op3);
    }

    /*
      'bandera' codifica qué usar para (a,b):
        bit 0 (1):  a = min
        bit 2 (4):  a = media
        bit 1 (2):  b = max-min
        bit 3 (8):  b = sqrt(varianza)

      Se arma a partir de (op1, op2, op3) con una tabla compacta (switch).
    */
    switch (8*op1 + 4*op2 + op3)
    {
        case  5: bandera =  2; break;  /* normalizar con max-min, sin centrar */
        case  6: bandera =  8; break;  /* normalizar con std, sin centrar */
        case  9: bandera =  1; break;  /* centrar con min */
        case 10: bandera =  4; break;  /* centrar con media */
        case 13: bandera =  3; break;  /* (x-min)/(max-min) */
        case 14: bandera = 12; break;  /* (x-media)/std */
        default: bandera =  0;
    }

    /* Generar datos aleatorios */
    for (i = 0; i < n; i++)
        x[i] = (((mx_X - mn_X) * rand()) / RAND_MAX) + mn_X;

    /* Calcular min y max */
    for (i = 1, max = x[0], min = x[0]; i < n; i++)
    {
        if (max < x[i]) max = x[i];
        if (min > x[i]) min = x[i];
    }

    /* Calcular media y varianza poblacional: Var = E[x^2] - (E[x])^2 */
    for (i = 1, media = x[0], varianza = x[0]*x[0]; i < n; i++)
    {
        media += x[i];
        varianza += (x[i] * x[i]);
    }
    media /= n;
    varianza /= n;
    varianza -= (media * media);

    /* Elegir a (offset) según bandera */
    if (bandera & 1)       a = min;
    else if (bandera & 4)  a = media;
    else                   a = 0;

    /* Elegir b (escala) según bandera */
    if (bandera & 2)       b = max - min;
    else if (bandera & 8)  b = sqrtf(varianza);
    else                   b = 1;

    /* Transformación */
    for (i = 0; i < n; i++)
        z[i] = (x[i] - a) / b;

    /* Reporte */
    printf("Maximo: %f\n", max);
    printf("Minimo: %f\n", min);
    printf("Media: %f\n", media);
    printf("Varianza: %f\n", varianza);

    for (i = 0; i < n; i++)
        printf("%d\t%f\t%f\n", i + 1, x[i], z[i]);

    return 0;
}

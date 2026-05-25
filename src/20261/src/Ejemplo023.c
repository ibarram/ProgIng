/**
 * @file Ejemplo023.c
 * @brief Ordenamiento tipo Bucket Sort (distribución por casilleros) + ordenamiento interno por selección.
 *
 * @details
 * Este programa genera `n` números aleatorios (float) en el rango [min, max] y los ordena
 * usando una estrategia tipo **Bucket Sort**:
 *
 * 1) Define el número de casilleros (buckets) como:
 *    \f[
 *      nd = \lfloor \sqrt{n} \rfloor
 *    \f]
 *
 * 2) Divide el rango [min, max] en `nd` intervalos de ancho:
 *    \f[
 *      Dx = \frac{max - min}{nd}
 *    \f]
 *
 * 3) Para cada valor `x[i]`, calcula el casillero:
 *    \f[
 *      j = \left\lfloor \frac{x[i]-min}{Dx} \right\rfloor
 *    \f]
 *    y se hace un ajuste para el caso `x[i] == max` para evitar `j == nd` (fuera de rango).
 *
 * 4) Usa un arreglo auxiliar `c[]` como estructura compacta:
 *    - `c[0 .. nd-1]`        : conteo de elementos por casillero
 *    - `c[nd .. 2*nd-1]`     : posiciones de escritura (inician como prefijos y luego se incrementan)
 *    - `c[2*nd .. 3*nd-1]`   : copia de los prefijos (inicio fijo de cada casillero en `xc`)
 *
 * 5) Distribuye los datos en un arreglo `xc[]` agrupado por casilleros.
 *
 * 6) Finalmente **ordena cada casillero internamente**:
 *    - 0 o 1 elemento: no hace nada
 *    - 2 elementos: una comparación e intercambio
 *    - >=3 elementos: Selection Sort dentro del segmento del casillero
 *
 * El resultado `xc[]` queda totalmente ordenado (ascendente) si cada casillero se ordena.
 *
 * @par Entrada estándar
 * - `n` (int): número de elementos, 1 <= n <= N
 * - `max` (float): límite superior del rango
 * - `min` (float): límite inferior del rango
 *
 * @par Salida estándar
 * Imprime (modo “didáctico”, muy verboso):
 * - Arreglo desordenado.
 * - Configuración de buckets (`nd`, `rango`, `Dx`).
 * - Intervalos por casillero.
 * - Elementos con su casillero.
 * - Conteos/prefijos.
 * - Arreglo `xc` tras distribución.
 * - Arreglo `xc` ya ordenado.
 *
 * @par Precondiciones
 * - Idealmente `min <= max`. Si `min > max`, el código los intercambia.
 *
 * @par Complejidad
 * - Generación + distribución: O(n)
 * - Prefijos: O(nd)
 * - Ordenamiento por casillero (Selection Sort): peor caso O(n^2) si todo cae en un solo bucket,
 *   típico mejor si los datos se reparten.
 * - Memoria: O(N)
 *
 * @warning
 * - `x[i] == max` se fuerza a `j = nd-1` para evitar `j == nd`.
 * - `c[]` se declara con tamaño N y se indexa hasta ~ `3*nd`; como `nd = sqrt(n)`,
 *   se mantiene seguro para `n <= 100000`.
 *
 * @code
 * gcc Ejemplo023.c -o Ejemplo023 -lm
 * ./Ejemplo023
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100000

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    /* n: cantidad de datos, nd: número de casilleros */
    int n, i, j, k, id_min, nd, c[N];

    /* Rango [min, max] */
    float min, max;

    /* x[]: arreglo original, xc[]: arreglo tras distribución y ordenamiento */
    float x[N], rango, Dx, xc[N], aux;

    /* Leer n con validación */
    do {
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
    } while (n < 1 || n > N);

    /* Leer rango */
    printf("Ingrese el valor maximo: ");
    scanf("%f", &max);
    printf("Ingrese el valor minimo: ");
    scanf("%f", &min);

    /*
      Asegurar min <= max. El código contempla casos con cero para evitar división entre cero
      en el intercambio por multiplicación/división.
    */
    if (min > max)
    {
        if (!min)           /* min == 0 */
        {
            min = max;
            max = 0;
        }
        else if (!max)      /* max == 0 */
        {
            max = min;
            min = 0;
        }
        else
        {
            /* Intercambio por multiplicación/división */
            max *= min;
            min = max / min;
            max /= min;
        }
    }

    srand(time(NULL));

    /* Generar datos aleatorios y limpiar c[i] (solo una parte; nd <= n así que alcanza) */
    printf("Desordenado.\n");
    for (i = 0; i < n; i++)
    {
        /* Escalamiento lineal de rand() a [min, max] */
        x[i] = ((max - min) * rand()) / RAND_MAX + min;

        /* Inicializar contadores a cero (al menos hasta n) */
        c[i] = 0;

        printf("x[%02d] = %f\n", i + 1, x[i]);
    }

    /* Definir buckets como sqrt(n) */
    nd = (int)sqrt((double)n);

    /* Tamaño de bucket */
    rango = max - min;
    Dx = rango / nd;

    printf("ND = %d\tRango = %f\tDx = %f\n", nd, rango, Dx);

    /* Mostrar intervalos por bucket (solo informativo) */
    for (i = 0; i < nd; i++)
        printf("%d. [%f, %f]\n", i, min + i*Dx, min + (i+1)*Dx);

    /*
      1) Conteo por casillero (histograma):
         j = floor((x[i]-min)/Dx), pero si x[i]==max forzamos j=nd-1.
    */
    printf("Desordenado con numero de casillero.\n");
    for (i = 0; i < n; i++)
    {
        j = (x[i] == max ? nd - 1 : (int)((x[i] - min) / Dx));
        printf("x[%02d] = %f\t%d\n", i + 1, x[i], j);
        c[j]++; /* c[j] = cantidad de elementos del bucket j */
    }

    /*
      2) Prefijos:
         Construye posiciones iniciales del bucket i en xc[].
         - c[i + nd]     guarda la posición "corriente" de escritura del bucket i.
         - c[i + 2*nd]   guarda una copia del prefijo (inicio fijo del bucket i).
    */
    for (i = 1; i < nd; i++)
    {
        c[i + nd]    = c[i + nd - 1] + c[i - 1]; /* prefijo */
        c[i + 2*nd]  = c[i + nd];                /* copia del prefijo */
    }

    /* Mostrar resumen por bucket: intervalo, conteo, prefijo */
    for (i = 0; i < nd; i++)
        printf("%d. [%+f, %+f]\t%d\t%d\n",
               i, min + i*Dx, min + (i+1)*Dx, c[i], c[i + nd]);

    /*
      3) Distribución a xc:
         Se inserta cada x[i] en xc según su prefijo, incrementando la posición de escritura.
    */
    for (i = 0; i < n; i++)
    {
        j = (x[i] == max ? nd - 1 : (int)((x[i] - min) / Dx));
        xc[c[j + nd]] = x[i];
        c[j + nd]++; /* avanzar posición de escritura del bucket */
    }

    /* Imprimir xc con su bucket (informativo) */
    for (i = 0; i < n; i++)
    {
        j = (int)((xc[i] - min) / Dx);
        printf("x[%02d] = %f\t%d\n", i + 1, xc[i], j);
    }

    /*
      4) Ordenar internamente cada bucket.
         El inicio del bucket i está en c[i + 2*nd].
         El tamaño del bucket i está en c[i].
    */
    for (i = 0; i < nd; i++)
    {
        switch (c[i])
        {
            case 0:
            case 1:
                /* 0 o 1 elemento: ya está ordenado */
                break;

            case 2:
                /* 2 elementos: una sola comparación */
                if (xc[c[i + 2*nd]] > xc[c[i + 2*nd] + 1])
                {
                    aux = xc[c[i + 2*nd]];
                    xc[c[i + 2*nd]] = xc[c[i + 2*nd] + 1];
                    xc[c[i + 2*nd] + 1] = aux;
                }
                break;

            default:
                /*
                  >= 3 elementos: Selection Sort dentro del segmento del bucket
                  [start, start + c[i] - 1], con start = c[i + 2*nd].
                */
                for (j = 0; j < (c[i] - 1); j++)
                {
                    for (k = j + 1, id_min = j; k < c[i]; k++)
                        if (xc[id_min + c[i + 2*nd]] > xc[k + c[i + 2*nd]])
                            id_min = k;

                    if (id_min != j)
                    {
                        aux = xc[j + c[i + 2*nd]];
                        xc[j + c[i + 2*nd]] = xc[id_min + c[i + 2*nd]];
                        xc[id_min + c[i + 2*nd]] = aux;
                    }
                }
                break;
        }
    }

    /* Resultado final */
    printf("Ordenado.\n");
    for (i = 0; i < n; i++)
        printf("x[%02d] = %f\n", i + 1, xc[i]);

    return 0;
}

/**
 * @file Ejemplo024.c
 * @brief Bucket Sort (distribución por casilleros) + ordenamiento interno por selección (versión compacta).
 *
 * @details
 * Versión menos verbosa que Ejemplo023:
 * - Genera `n` números aleatorios en [min, max].
 * - Define `nd = floor(sqrt(n))` buckets y `Dx = (max-min)/nd`.
 * - Cuenta por bucket, calcula prefijos y distribuye a `xc`.
 * - Ordena internamente cada bucket con Selection Sort (casos 0/1/2 optimizados).
 *
 * A diferencia de Ejemplo023, aquí no se imprimen intervalos por bucket ni
 * depuración detallada; solo muestra el arreglo final ordenado.
 *
 * @par Entrada estándar
 * - `n` (int): 1 <= n <= N
 * - `max` (float)
 * - `min` (float)
 *
 * @par Salida estándar
 * - Arreglo desordenado.
 * - Arreglo ordenado.
 *
 * @par Complejidad
 * Distribución: O(n) + O(nd). Ordenamiento interno: depende de la distribución;
 * peor caso O(n^2). Memoria: O(N).
 *
 * @code
 * gcc Ejemplo024.c -o Ejemplo024 -lm
 * ./Ejemplo024
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

    int n, i, j, k, id_min, nd, c[N];
    float min, max;
    float x[N], rango, Dx, xc[N], aux;

    do {
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
    } while (n < 1 || n > N);

    printf("Ingrese el valor maximo: ");
    scanf("%f", &max);
    printf("Ingrese el valor minimo: ");
    scanf("%f", &min);

    /* Asegurar min <= max (con manejo de ceros) */
    if (min > max)
    {
        if (!min) { min = max; max = 0; }
        else if (!max) { max = min; min = 0; }
        else { max *= min; min = max / min; max /= min; }
    }

    srand(time(NULL));

    printf("Desordenado.\n");
    for (i = 0; i < n; i++)
    {
        x[i] = ((max - min) * rand()) / RAND_MAX + min;
        c[i] = 0;
        printf("x[%02d] = %f\n", i + 1, x[i]);
    }

    /* Configuración de buckets */
    nd = (int)sqrt((double)n);
    rango = max - min;
    Dx = rango / nd;

    /* Conteo por bucket */
    for (i = 0; i < n; i++)
    {
        j = (x[i] == max ? nd - 1 : (int)((x[i] - min) / Dx));
        c[j]++;
    }

    /* Prefijos: c[nd..] y copia de prefijos en c[2*nd..] */
    for (i = 1; i < nd; i++)
    {
        c[i + nd] = c[i + nd - 1] + c[i - 1];
        c[i + 2*nd] = c[i + nd];
    }

    /* Distribución a xc */
    for (i = 0; i < n; i++)
    {
        j = (x[i] == max ? nd - 1 : (int)((x[i] - min) / Dx));
        xc[c[j + nd]] = x[i];
        c[j + nd]++;
    }

    /* Ordenar internamente cada bucket */
    for (i = 0; i < nd; i++)
    {
        switch (c[i])
        {
            case 0:
            case 1:
                break;

            case 2:
                if (xc[c[i + 2*nd]] > xc[c[i + 2*nd] + 1])
                {
                    aux = xc[c[i + 2*nd]];
                    xc[c[i + 2*nd]] = xc[c[i + 2*nd] + 1];
                    xc[c[i + 2*nd] + 1] = aux;
                }
                break;

            default:
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

    /* Resultado */
    printf("Ordenado.\n");
    for (i = 0; i < n; i++)
        printf("x[%02d] = %f\n", i + 1, xc[i]);

    return 0;
}
/**
 * @file Ejemplo023.c
 * @brief Clasificación por “casilleros” (bucket/distribution) de números reales en un rango [min, max].
 *
 * @details
 * Este programa genera `n` números aleatorios (float) dentro del rango [min, max] y los
 * reordena usando un enfoque tipo **bucket / distribution sort**:
 *
 * 1) Se elige el número de divisiones (casilleros) como:
 *      nd = floor(sqrt(n))
 *
 * 2) Se calcula el tamaño de casillero:
 *      rango = max - min
 *      Dx    = rango / nd
 *
 * 3) Para cada valor x[i] se calcula el índice del casillero:
 *      j = floor( (x[i] - min) / Dx )
 *
 * 4) Se cuenta cuántos elementos caen en cada casillero (histograma).
 *
 * 5) Se calcula un arreglo de posiciones iniciales (prefijos) y se construye un nuevo
 *    arreglo `xc[]` colocando cada elemento en su casillero correspondiente.
 *
 * El arreglo `xc` queda **agrupado por intervalos** (primero todos los del casillero 0,
 * luego los del 1, etc.). **No ordena dentro de cada casillero**, por lo que NO es un
 * ordenamiento total, sino una etapa típica de un bucket sort (faltaría ordenar cada bucket).
 *
 * @par Entrada estándar
 * - `n` (int): número de elementos, 1 <= n <= N
 * - `max` (float): valor máximo del rango
 * - `min` (float): valor mínimo del rango
 *
 * @par Salida estándar
 * - Imprime los valores generados (“Desordenado”).
 * - Imprime el número de casilleros `nd`, rango y `Dx`.
 * - Imprime los intervalos de cada casillero.
 * - Imprime cada elemento con su índice de casillero.
 * - Imprime conteos y prefijos por casillero.
 * - Imprime el arreglo `xc` (reordenado por casilleros) con su casillero.
 *
 * @par Precondiciones
 * - Se espera que `min <= max`. Si `min > max`, se intercambian.
 * - `nd > 0` y `Dx > 0` (se cumple si `n >= 1` y `max > min`).
 *
 * @par Complejidad
 * - Conteo por casilleros: O(n)
 * - Cálculo de prefijos: O(nd)
 * - Distribución a `xc`: O(n)
 * - Memoria: O(N)
 *
 * @warning
 * 1) El intercambio `min/max` se hace con multiplicación/división: si alguno es 0,
 *    puede fallar (división entre 0). Para robustez usa una variable auxiliar.
 * 2) Cuando x[i] == max, el índice j puede resultar igual a nd (fuera del rango 0..nd-1).
 *    En código de producción conviene “clamp”:
 *      if (j >= nd) j = nd - 1;
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

/**
 * @brief Punto de entrada. Genera valores y los agrupa por casilleros.
 * @param argc No usado.
 * @param argv No usado.
 * @return 0 si finaliza correctamente.
 */
int main(int argc, char *argv[])
{
    /*
      n   : número de elementos a generar (1..N)
      i,j : índices auxiliares
      nd  : número de divisiones/casilleros (≈ sqrt(n))

      c[] : arreglo de enteros usado en dos zonas:
            - c[0..nd-1]      = conteos por casillero (histograma)
            - c[nd..2*nd-1]   = posiciones iniciales/prefijos (índices de escritura en xc)
     */
    int n, i, j, nd, c[N];

    /*
      min, max : rango de generación
      x[]      : arreglo original “desordenado”
      xc[]     : arreglo reordenado por casilleros
      rango    : max - min
      Dx       : ancho de cada casillero (rango/nd)
     */
    float min, max;
    float x[N], rango, Dx, xc[N];

    /* Leer n */
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
      Si el usuario capturó min > max, se intercambian.
      WARNING: este intercambio por multiplicación/división puede fallar si min==0 o max==0.
    */
    if (min > max)
    {
        max *= min;
        min = max / min;
        max /= min;
    }

    srand(time(NULL));

    /* Generar arreglo original y (por simplicidad) inicializar c[i]=0 para i<n */
    printf("Desordenado.\n");
    for (i = 0; i < n; i++)
    {
        /* Genera valores en [min, max] (puede incluir max si rand()==RAND_MAX) */
        x[i] = ((max - min) * rand()) / RAND_MAX + min;

        /* Inicialización (basta con 0..2*nd-1, pero aquí se inicializa 0..n-1) */
        c[i] = 0;

        printf("x[%02d] = %f\n", i + 1, x[i]);
    }

    /* Definir número de casilleros */
    nd = (int)sqrt((double)n);

    /* Calcular rango y ancho de casillero */
    rango = max - min;
    Dx = rango / nd;

    printf("ND = %d\tRango = %f\tDx = %f\n", nd, rango, Dx);

    /* Mostrar intervalos de los casilleros */
    for (i = 0; i < nd; i++)
        printf("%d. [%f, %f]\n", i, min + i*Dx, min + (i+1)*Dx);

    /*
      1) Conteo por casillero:
         j = floor((x[i]-min)/Dx)
         c[j]++
    */
    printf("Desordenado con numero de casillero.\n");
    for (i = 0; i < n; i++)
    {
        j = (int)((x[i] - min) / Dx);

        /*
          WARNING: si x[i] == max, j puede ser nd. Para robustez:
          if (j >= nd) j = nd - 1;
        */

        printf("x[%02d] = %f\t%d\n", i + 1, x[i], j);
        c[j]++;
    }

    /*
      2) Prefijos / posiciones iniciales:
         Se construye en la zona c[nd..2*nd-1]:
           c[nd]     = 0
           c[nd+1]   = c[0]
           c[nd+2]   = c[0] + c[1]
           ...
         donde c[nd+k] es el índice de inicio para escribir el casillero k en xc[].
     */
    for (i = 1; i < nd; i++)
        c[i + nd] = c[i + nd - 1] + c[i - 1];

    /* Mostrar conteos y prefijos */
    for (i = 0; i < nd; i++)
        printf("%d. [%+f, %+f]\t%d\t%d\n",
               i, min + i*Dx, min + (i+1)*Dx, c[i], c[i + nd]);

    /*
      3) Distribución a xc:
         - Se vuelve a calcular el casillero j para cada x[i]
         - Se coloca x[i] en la siguiente posición libre del casillero j:
             xc[ c[nd + j] ] = x[i]
           y se incrementa esa posición para el siguiente elemento del mismo casillero.
     */
    for (i = 0; i < n; i++)
    {
        j = (int)((x[i] - min) / Dx);

        /* WARNING: clamp recomendado para evitar j==nd */
        /* if (j >= nd) j = nd - 1; */

        xc[c[j + nd]] = x[i];
        c[j + nd]++;
    }

    /* Mostrar arreglo reordenado por casilleros */
    for (i = 0; i < n; i++)
    {
        j = (int)((xc[i] - min) / Dx);
        /* if (j >= nd) j = nd - 1; */
        printf("x[%02d] = %f\t%d\n", i + 1, xc[i], j);
    }

    return 0;
}
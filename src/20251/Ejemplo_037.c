#include<stdio.h>
#include<stdlib.h>

/* Multiplicacion de matrices */
/* A: mA x nA */
/* B: mB x nB */
/* C: mA x nB */
/* A matriz ordenada */
/* B matriz dispersa */
/* C matriz ordenada */
/* fp archivo de salida de C */

int main(void)
{
  float **A, **B, **C, *pA, *pC;
  int nA, mA, nB, mB, i, j, k;
  FILE *fp;
  do{
    printf("Ingrese el numero de columnas de A: ");
    scanf("%d", &nA);
    printf("Ingrese el numro de renglones de A: ");
    scanf("%d", &mA);
  }while(nA<1||mA<1);
  do{
    printf("Ingrese el numero de columnas de B: ");
    scanf("%d", &nB);
    printf("Ingrese el numro de renglones de B: ");
    scanf("%d", &mB);
  }while(nB<1||mB<1||nB!=mA);
  pA = (float*)malloc(nA*mA*sizeof(float));
  if(pA==NULL)
    return 1;
  A = (float**)malloc(nA*sizeof(float*));
  if(A==NULL)
  {
    free(pA);
    return 2;
  }
  for(i=0; i<nA; i++)
    A[i] = pA+i*mA;
  B = (float**)malloc(nB*sizeof(float*));
  if(B==NULL)
  {
    free(pA);
    free(A);
    return 3;
  }
  for(i=0; i<nB; i++)
  {
    B[i] = (float*)malloc(mB*sizeof(float));
    if(B[i]== NULL)
    {
      free(pA);
      free(A);
      for(--i; i>-1; i--)
        free(B[i]);
      free(B);
      return 4;
    }
  }
  pC = (float*)malloc(nA*mB*sizeof(float));
  if(pC==NULL)
  {
    free(pA);
    free(A);
    for(i=0; i<nB; i++)
      free(B[i]);
    free(B);
    return 5;
  }
  C = (float**)malloc(nA*sizeof(float*));
  if(C==NULL)
  {
    free(pA);
    free(A);
    for(i=0; i<nB; i++)
      free(B[i]);
    free(B);
    free(pC);
    return 6;
  }
  for(i=0; i<nA; i++)
    C[i] = pC+i*mB;
  for(i=0; i<nA; i++)
    for(j=0; j<mA; j++)
    {
      printf("A[%d][%d] = ", i+1, j+1);
      scanf("%f", A[i]+j);
    }
  for(i=0; i<nB; i++)
    for(j=0; j<mB; j++)
    {
      printf("B[%d][%d] = ", i+1, j+1);
      scanf("%f", B[i]+j);
    }
  for(i=0; i<nA; i++)
    for(j=0; j<mB; j++)
      for(k=0, C[i][j]=0; k<nB; k++)
        C[i][j] += A[i][k]*B[k][j];
  for(i=0; i<nA; i++)
    for(j=0; j<mB; j++)
      printf("C[%d][%d] = %f\n", i+1, j+1, C[i][j]);
  fp = fopen("Matriz.txt", "w");
  if(fp==NULL)
  {
    free(pC);
    free(C);
    for(i=0; i<nB; i++)
      free(B[i]);
    free(B);
    free(pA);
    free(A);
    return 7;
  }
  for(i=0; i<nA; i++)
    for(j=0; j<mB; j++)
      fprintf(fp, "%f ", C[i][j]);
  fclose(fp);
  free(pC);
  free(C);
  for(i=0; i<nB; i++)
    free(B[i]);
  free(B);
  free(pA);
  free(A);
  return 0;
}
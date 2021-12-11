#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Imprimir(int *vetor, int tamanho)
{
  int i;
  for (i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}
int Particione(int A[], int p, int r)
{
  int x = A[r];
  int i = p - 1;
  int j;
  for (j = p; j <= r - 1; j++)
  {
    if (A[j] <= x)
    {
      i += 1;
      int tmp = A[j];
      A[j] = A[i];
      A[i] = tmp;
    }
  }
  A[r] = A[i + 1];
  A[i + 1] = x;
  return i + 1;
}
int QuickFind(int *vetor, int esq, int dir, int k)
{
  if (esq <= dir)
  {
    int q = Particione(vetor, esq, dir);
    if (q == k)
    {
      return vetor[k];
    }
    else if (q < k)
      QuickFind(vetor, q + 1, dir, k);
    else
      QuickFind(vetor, esq, q - 1, k);
  }
}

/*Função principal.*/
int main(int argc, char *argv[])
{
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  int i;

  //int tamanho = 10;
  //int *vetor = (int *)malloc(tamanho * sizeof(int));
  //for (i = 0; i < tamanho; i++) {
  //   vetor[i] = rand() % (tamanho+1);
  //}

  int tamanho = 8;
  int vetor[] = {7, 1, 3, 10, 17, 2, 21, 9};

  Imprimir(vetor, tamanho);
  start = clock();
  int pos = 4;
  printf("O elemento procurado na posicao %d eh %d\n", pos, QuickFind(vetor, 0, tamanho - 1, pos));
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  //free (vetor);
  return 0;
}

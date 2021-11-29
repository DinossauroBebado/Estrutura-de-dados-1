#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *vetor, int num)
{
  int i, j, temp;
  i = num;
  if (i > 0)
  {
    for (j = 0; j < num - 1; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
    BubbleSort(vetor, num - 1);
  }
  else
  {
    return;
  }
}

void SelectionSort(int *vetor, int i, int tamanho)
{
  int min, j, temp;
  min = i;
  for (j = i + 1; j < tamanho; j++)
  {
    if (vetor[j] < vetor[min])
    {
      min = j;
    }
  }

  temp = vetor[i];
  vetor[i] = vetor[min];
  vetor[min] = temp;

  if (i + 1 < tamanho)
  {
    SelectionSort(vetor, i + 1, tamanho);
  }
}

void InsertionSort(int *vetor, int tamanho)
{

  if (tamanho <= 1)
    return;

  InsertionSort(vetor, tamanho - 1);

  int last = vetor[tamanho - 1];
  int j = tamanho - 2;

  while (j >= 0 && vetor[j] > last)
  {
    vetor[j + 1] = vetor[j];
    j--;
  }
  vetor[j + 1] = last;
}

void Imprimir(int *A, int tamanho)
{
  int i;
  for (i = 0; i < tamanho; i++)
  {
    printf("%d, ", A[i]);
  }
  printf("\n");
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao(int *A, int tamanho)
{
  int i;
  for (i = 0; i < tamanho - 1; i++)
  {
    if (A[i] > A[i + 1])
    {
      return 0;
    }
  }
  return 1;
}

int main()
{

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;

  int tamanho = 10;

  int *v1 = (int *)malloc(tamanho * sizeof(int));
  int *v2 = (int *)malloc(tamanho * sizeof(int));
  int *v3 = (int *)malloc(tamanho * sizeof(int));

  for (i = 0; i < tamanho; i++)
  {
    v1[i] = rand() % (tamanho + 1);
    v2[i] = rand() % (tamanho + 1);
    v3[i] = rand() % (tamanho + 1);
  }

  start = clock();
  Imprimir(v1, tamanho);
  BubbleSort(v1, tamanho);
  Imprimir(v1, tamanho);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Tempo de execucao (BubbleSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v1, tamanho))
  {
    printf("Erro: a ordenacao do BubbleSort não está correta!\n");
  }

  start = clock();
  Imprimir(v2, tamanho);
  SelectionSort(v2, 0, tamanho);
  Imprimir(v2, tamanho);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Tempo de execucao (SelectionSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v2, tamanho))
  {
    printf("Erro: a ordenacao do SelectionSort não está correta!\n");
  }

  start = clock();
  Imprimir(v3, tamanho);
  InsertionSort(v3, tamanho);
  Imprimir(v3, tamanho);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Tempo de execucao (InsertionSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v3, tamanho))
  {
    printf("Erro: a ordenacao do InsertionSort não está correta!\n");
  }
  free(v1);
  free(v2);
  free(v3);

  return 0;
}

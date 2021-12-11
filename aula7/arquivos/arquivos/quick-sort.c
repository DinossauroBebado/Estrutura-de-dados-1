#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao(int *vetor, int tamanho)
{
  int i;
  for (i = 0; i < tamanho - 1; i++)
  {
    if (vetor[i] > vetor[i + 1])
    {
      return 0;
    }
  }
  return 1;
}

void Imprimir(int *vetor, int tamanho)
{
  int i;
  for (i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

void QuickSort(int *vetor, int esq, int dir)
{
  int i, j, x, y;

  i = esq;
  j = dir;
  x = vetor[(esq + dir) / 2];

  while (i <= j)
  {
    while (vetor[i] < x && i < dir)
    {
      i++;
    }
    while (vetor[j] > x && j > esq)
    {
      j--;
    }
    if (i <= j)
    {
      y = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = y;
      i++;
      j--;
    }
  }

  if (j > esq)
  {
    QuickSort(vetor, esq, j);
  }
  if (i < dir)
  {
    QuickSort(vetor, i, dir);
  }
}

/*Função principal.*/
int main(int argc, char *argv[])
{
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  int i;
  int tamanho = 100000;
  int *vetor = (int *)malloc(tamanho * sizeof(int));
  for (i = 0; i < tamanho; i++)
  {
    vetor[i] = rand() % (tamanho + 1);
  }
  Imprimir(vetor, tamanho);
  start = clock();
  QuickSort(vetor, 0, tamanho - 1);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(vetor, tamanho))
  {
    printf("Erro: a ordenação não está correta!\n");
  }
  //Imprimir(vetor, tamanho);
  free(vetor);
  return 0;
}

//1000000:  0.01
//resto : 0.0
//Isso ocorre pois o algoritmo depende de uma organização previa
// para ser eficiente quanto mais distante da ordem desejada mais ineficiente ele sera
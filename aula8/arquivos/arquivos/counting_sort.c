#include <stdio.h>
#include <stdlib.h>

/* TERMINAR */

void CountingSort(int A[], int B[], int n)
{

  int x = A[0];
  for (int i = 1; i < n; i++)
  {
    if (A[i] > x)
      x = A[i];
  }

  int count_arr[10];

  for (int i = 0; i <= x; ++i)
  {
    count_arr[i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    count_arr[A[i]]++;
  }

  for (int i = 1; i <= x; i++)
  {
    count_arr[i] += count_arr[i - 1];
  }

  for (int i = n - 1; i >= 0; i--)
  {
    B[count_arr[A[i]] - 1] = A[i];
    count_arr[A[i]]--;
  }

  for (int i = 0; i < n; i++)
  {
    A[i] = B[i];
  }
}

void Imprimir(int A[], int n)
{
  int i;
  printf("Vetor: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main()
{

  int i, n;
  printf("Digite a quantidade de elementos: ");
  scanf("%d", &n);
  int *A = (int *)malloc(n * sizeof(int));
  int *B = (int *)malloc(n * sizeof(int));
  int k = 10; /*número máximo limite a ser sorteado!*/
  for (i = 0; i < n; i++)
  {
    A[i] = rand() % k; /*Sorteio de elementos até limite k-1*/
  }
  Imprimir(A, n);

  CountingSort(A, B, n);
  Imprimir(B, n);
  return 0;
}

// 2) Não o algoritmo não funciona corretamente

//3) O algoritimo de pre processamento seria muito simular ao counting_sort iniciando
// por pegar contar as repetições de numeros e armazenar em um vetor , então somar esses numeros
// a diferença se da que o ultimo numero sera a soma da reptições daquele numero e então retornara//
// esse vetor para fazer a consulta simplesmente olha a valor da posição do numero inicial e subtrai com a
//possição do numero final do vetor com isso tera a quantidade de numeros no itervalo
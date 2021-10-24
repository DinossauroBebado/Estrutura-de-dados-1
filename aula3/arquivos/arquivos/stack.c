#include "stack.h"

/*Função para criar uma pilha!*/
Stack *create_stack(int tam)
{
  Stack *p = (Stack *)malloc(sizeof(Stack));
  p->topo = 0;
  p->tam = tam;
  p->vetor = (int *)malloc(tam * sizeof(int));
  return p;
}

/*Função para empilhar um elemento!*/
void push(Stack *p, int elem)
{
  if (full_stack(p))
  {
    printf("Stack cheia\n");
    exit(1);
  }
  p->vetor[p->topo] = elem;
  p->topo++;
}

/*Função para desempilhar um elemento!*/
int pop(Stack *p)
{
  if (empty_stack(p))
  {
    //printf("Stack vazia\n");
    return -1;
  }
  p->topo--;
  return p->vetor[p->topo];
}

/*Função para liberar a memória alocada.*/
int empty_stack(Stack *p)
{
  return (p->topo == 0);
}

/*Funão para testar se a pilha está cheia!*/
int full_stack(Stack *p)
{
  return (p->topo == p->tam);
}

/*Funão para testar se a pilha está vazia!*/
void free_stack(Stack *p)
{
  free(p->vetor);
  free(p);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
  int topo;
  int tam;
  int *vetor;
} Stack;

Stack *create_stack(int tam);

void push(Stack *p, int elem);

int pop(Stack *p);

int empty_stack(Stack *p);

int full_stack(Stack *p);

void free_stack(Stack *p);

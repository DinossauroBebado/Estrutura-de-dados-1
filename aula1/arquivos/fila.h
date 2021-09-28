#include <stdio.h>
#include <stdlib.h>

//essencia da fila

typedef struct{
    int ini ;
    int fim ;
    int tam ;
    int *vetor;
} Fila; //dois nomes pra msm struct


void enqueue(int elem, Fila *f);

int dequeu(Fila *f);

Fila* init(int tam);

void destroy(Fila *f);

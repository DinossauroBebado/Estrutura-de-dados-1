#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
   int info;
   struct _no *next;
} Lista;

Lista* criar_lista (void);

Lista* inserir (Lista *lista, int elem);

void imprimir_lista (Lista *lista);

void imprimir_lista_rec (Lista *lista);

void destruir_lista (Lista *l);

Lista *remover (Lista *l, int elem);

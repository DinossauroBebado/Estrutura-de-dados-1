#include "lista.h"

/*Função para criar uma lista encadeada vazia!*/
Lista* criar_lista (void) {
   return NULL;
}

/*Função para inserir um elemento na cabeça de uma lista encadeada!*/
Lista* inserir (Lista *lista, int elem) {
   Lista *novo =(Lista*)malloc(sizeof(Lista));
   novo->info = elem;
   novo->next = lista;
   return novo;
}

/*Função para imprimir uma lista encadeada!*/
void imprimir_lista (Lista *lista) {
   printf("Lista: ");
   for (; lista != NULL; lista = lista->next) {
      printf("%d ", lista->info);
   }
   printf("\n");
}

void imprimir_lista_rec (Lista *lista) {
   if (lista != NULL) {
      printf("%d ", lista->info);
      imprimir_lista_rec (lista->next);
   }
   else {
      printf("\n");
   }   
}



/*Função para remover um elemento da lista encadeada em qq posição!*/
Lista *remover (Lista *l, int elem) {
   Lista *prev = NULL, *v = l;
   while ( (v != NULL) && (v->info != elem) ) {
      prev = v;
      v = v->next;
   }
   if (v == NULL) {
      return l;
   }
   else if (prev == NULL) {
      l = v->next;
   }
   else {
      prev->next = v->next;
   }
   free (v);
   return l;
}


Lista *remover_rec (Lista *l, int elem) {
   if (l == NULL) {
      return l;	   
   }
   else {
      if (l->info == elem) {
	 Lista *prox = l->next;
         free (l);
         return prox;	 
      }
      else 
	 l->next = remover_rec (l->next, elem);      
   }
}


/*Função para desalocar uma lista encadeda!*/
void destruir_lista (Lista *l) {
  Lista *aux;
  while (l != NULL) {
    aux = l->next;
    free(l);
    l = aux;
  }
}



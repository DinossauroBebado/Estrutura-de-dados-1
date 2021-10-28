#include "lista.h"

int conta_nos_itr(Lista *lista)
{
   Lista *v; /*var. para percorrer a lista*/
   int size = 0;
   for (v = lista; v != NULL; v = v->next)
   {
      size++;
   }
   return size;
}

int conta_nos_rec(Lista *lista)
{

   if (lista == NULL)
   {
      return 0;
   }
   else
   {
      return 1 + conta_nos_rec(lista->next);
   }
}

int procura_itr(Lista *lista, int elemento)
{
   Lista *v; /*var. para percorrer a lista*/
   int pos = 0;
   for (v = lista; v != NULL; v = v->next)
   {
      if (v->info == elemento)
      {

         return pos;
      }
      pos++;
   }
   return -1;
}

int procura_rec(Lista *lista, int elemento)
{

   if (lista == NULL)
   {
      return -1;
   }

   if (lista->info == elemento)
   {
      return 0;
   }

   int n = procura_rec(lista->next, elemento);
   return (n < 0 ? -1 : n + 1);
}

int lista_max_itr(Lista *lista)
{
   Lista *v; /*var. para percorrer a lista*/
   int max = INT_MIN;
   for (v = lista; v != NULL; v = v->next)
   {
      if (v->info > max)
      {

         max = v->info;
      }
   }
   return max;
}

/*Você pode usar outras funções aqui se achar necessário!*/
int lista_max_rec(Lista *lista)
{

   if (lista == NULL)
   {
      return INT_MIN;
   }
   else
   {
      if (lista->info > lista_max_rec(lista->next))
      {
         return lista->info;
      }
      else
      {
         return lista_max_rec(lista->next);
      }
   }
}

int lista_soma_itr(Lista *lista)
{
   Lista *v; /*var. para percorrer a lista*/
   int sum = 0;
   for (v = lista; v != NULL; v = v->next)
   {
      sum = sum + v->info;
   }
   return sum;
}

int lista_soma_rec(Lista *lista)
{

   if (lista == NULL)
   {
      return 0;
   }
   else
   {
      return lista->info + lista_soma_rec(lista->next);
   }
}

/*Você pode usar outras funções aqui se achar necessário!*/
void imprimir_invertida_itr(Lista *lista)
{
   Lista *lista_inv = criar_lista();
   Lista *v; /*var. para percorrer a lista*/

   for (v = lista; v != NULL; v = v->next)
   {
      lista_inv = inserir(lista_inv, v->info);
   }
   imprimir_lista(lista_inv);
}

void imprimir_invertida_rec(Lista *lista)
{
   if (lista == NULL)
   {
      return;
   }
   imprimir_invertida_rec(lista->next);
   printf("%d ", lista->info);
}

/*Função para criar uma lista encadeada vazia!*/
Lista *criar_lista(void)
{
   return NULL;
}

/*Função para inserir um elemento na cabeça de uma lista encadeada!*/
Lista *inserir(Lista *lista, int elem)
{
   Lista *novo = (Lista *)malloc(sizeof(Lista));
   novo->info = elem;
   novo->next = lista;
   return novo;
}

/*Função para imprimir uma lista encadeada!*/
void imprimir_lista(Lista *lista)
{
   Lista *v; /*var. para percorrer a lista*/
   printf("Lista: ");
   for (v = lista; v != NULL; v = v->next)
   {
      printf("%d ", v->info);
   }
   printf("\n");
}

/*Função para desalocar uma lista encadeda!*/
void destruir_lista(Lista *l)
{
   Lista *aux;
   while (l != NULL)
   {
      aux = l->next;
      free(l);
      l = aux;
   }
}

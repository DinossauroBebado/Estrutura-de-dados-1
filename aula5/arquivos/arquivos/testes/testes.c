#include "lista.c"

/*Função que insere o valor -1 antes da primeira ocorrência de {elemento}
 *ou caso {elemento} não exista, a lista deve permanecer inalterada! */
List *inserir_antes(List *lista, int elemento)
{
   List *aux = buscar(lista, elemento);
   if (aux == NULL)
   {
      return lista;
   }
   else
   {

      List *no = (List *)malloc(sizeof(List));
      no->info = -1;
      no->prev = aux->prev;
      no->next = aux;
      aux->prev = no;
      if (no->prev != NULL)
      {
         no->prev->next = no;
      }
      if (no->prev == NULL)
      {
         return no;
      }
      return lista;
   }
}

/*Função que insere o valor -1 depois da primeira ocorrência de {elemento}
 *ou caso {elemento} não exista, a lista deve permanecer inalterada! */
List *inserir_depois(List *lista, int elemento)
{

   List *aux = buscar(lista, elemento);
   if (aux == NULL)
   {
      return lista;
   }
   else
   {

      List *no = (List *)malloc(sizeof(List));
      no->info = -1;
      no->prev = aux;
      no->next = aux->next;
      aux->next = no;
      if (no->next != NULL)
      {
         no->next->prev = no;
      }
      if (no->prev == NULL)
      {
         return no;
      }
      return lista;
   }
}

int main()
{

   List *lista1 = criar();
   List *lista2 = criar();

   int i;
   for (i = 0; i < 5; i++)
   {
      lista1 = inserir_frente(lista1, i);
      lista2 = inserir_frente(lista2, i);
   }

   imprimir(lista1);
   //printf("%d \n", buscar(lista1, 3)->info);
   //printf("%d \n", buscar(lista1, 3)->prev->info);
   //printf("%d \n", buscar(lista1, 3)->next->info);
   printf("----------------\n");
   lista1 = inserir_antes(lista1, 4);
   lista1 = inserir_antes(lista1, 10);
   lista1 = inserir_antes(lista1, 0);

   imprimir(lista1);
   imprimir(lista2);
   printf("----------------\n");
   lista2 = inserir_depois(lista2, 4);
   lista2 = inserir_depois(lista2, 10);
   lista2 = inserir_depois(lista2, 0);

   imprimir(lista2);

   return 0;
}

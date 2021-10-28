#include "lista.c"

int main()
{
   Lista *lista;
   lista = criar_lista();
   lista = inserir(lista, 1);
   lista = inserir(lista, 2);
   lista = inserir(lista, 4);
   imprimir_lista_rec(lista);
   lista = remover(lista, 2);
   imprimir_lista_rec(lista);
   lista = remover(lista, 1);
   imprimir_lista_rec(lista);
   lista = remover(lista, 4);
   imprimir_lista_rec(lista);
   destruir_lista(lista);
   return 0;
}

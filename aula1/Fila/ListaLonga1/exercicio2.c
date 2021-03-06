#include <stdio.h>
#include <stdlib.h>

typedef struct _fila {
   int ini;
   int fim;
   int tam;
   int *vetor;
} Fila;

Fila* criar_fila (int tamanho) {
   /*Para implementar uma fila sem struct era necessário um malloc para alocar
   o vetor com os elementos. Note que agora são necessários dois mallocs, um
   para a estrutura tipo fila e outro para o vetor que a fila contém!*/
   Fila *f = (Fila*)malloc(sizeof(Fila)) ;

   f->ini = 0;
   f->fim = 0;
   f->tam = tamanho ;
   f->vetor = (int*)malloc(tamanho*sizeof(int));

   return f;
}

void destruir_fila (Fila *f) {
   /*Para cada malloc da função criar_fila é necessário um free!*/

   free(f->vetor);
   free(f);
}

void enqueue (Fila *f, int elemento) {
   /*Criar uma lógica para armazenar o elemento na posição
   fim (que está dentro da variável tipo fila f e dentro do
   vetor que também está dentro da variável f)!
   Lembre de deixar a variável fim apontando
   para a próximo posição livre na fila.*/

   if( f->ini < f->tam){
        f->vetor[f->fim] = elemento;
        (f->fim)++; //fim da fila é outro
   }else{
        printf("erro 01 :Fila cheia\n");

   }

}

int dequeue (Fila *f) {
   /*Criar uma lógica para remover o elemento na posição
   ini (que está dentro da variável tipo fila f e dentro do
   vetor que também está dentro da variável f) e retornar
   este valor! Lembre de deixar a variável ini apontando
   para o próximo elemento da fila.*/

   if(f->ini < f->fim){ //verifica sem tem elemento na fila
        int atendimento = f->vetor[f->ini];
        (f->ini)++; // a fila começa em outro lugar
        return atendimento;
   }else{
        printf("erro 02 :Fila vazia\n");
        }
}

int main () {

   /*Inicializando a estrutura de dados fila!*/
   Fila *fila = criar_fila (10);

   /*Tentando inserir o elemento 1 na fila!*/
   int elem = 1;
   enqueue (fila, elem);

   /*Tentando inserir o elemento 2 na fila!*/
   elem = 2;
   enqueue (fila, elem);

   /*Tentando inserir o elemento 3 na fila!*/
   elem = 3;
   enqueue (fila, elem);

   /*Tentando inserir o elemento 4 na fila!*/
   elem = 4;
   enqueue (fila, elem);

   /*Tentando retirar e imprimir o elemento 1 na fila!*/
   printf("%d\n", dequeue (fila));

   /*Tentando retirar e imprimir o elemento 2 na fila!*/
   printf("%d\n", dequeue (fila));

   destruir_fila (fila);

   return 0;
}

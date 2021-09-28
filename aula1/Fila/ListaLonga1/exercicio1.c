#include <stdio.h>
#include <stdlib.h>

/*NAO USE VARIAVEIS GLOBAIS!!!!!!!!!!!!!*/

/*Função para enfileirar um dado elemento em um vetor: */
void enqueue (int vetor[], int elemento, int tamanho,int *ini, int*fim) {
   /*As entradas na funcao sao suficientes para inserir
    *um elemento na fila? Precisa de mais alguma coisa?*/

   /*Como voce faz para inserir um elemento na fila? Veja
    *nos slides a logica. Em qual posicao voce insere?*/
    if(*fim < tamanho){
        vetor[*fim]= elemento ;
        (*fim)++;
    }else{
        printf("erro 01 :Fila cheia\n");

   }


}

/*Função para desenfileirar um dado elemento em um vetor: */
int dequeue (int vetor[], int tamanho,int *ini,int *fim) {
   /*As entradas na funcao sao suficientes para retirar
    *um elemento da fila? Precisa de mais alguma coisa?*/

   /*Como voce faz para remover um elemento na fila? Veja
    *nos slides a logica. De qual posicao voce remove?*/
    if(*ini<*fim){
        int atendimento = vetor[*ini];
        (*ini)++;
        return atendimento;
    }else {
         printf("erro 02 :Fila vazia\n");
    }
}

int main () {

   int elem;
   int ini = 0 ;
   int fim = 0 ;
   /*Determinando o tamanho da fila!*/
   int fila_tamanho = 10;
   /*Reservando o espaco para o vetor na memoria!*/
   int *fila = (int *)malloc(fila_tamanho * sizeof(int));

   /*Tentando inserir o elemento 1 na fila!*/
   elem = 1;
   enqueue (fila, elem, fila_tamanho,&ini,&fim);

   /*Tentando inserir o elemento 2 na fila!*/
   elem = 2;
   enqueue (fila, elem, fila_tamanho,&ini,&fim);

   /*Tentando inserir o elemento 3 na fila!*/
   elem = 3;
   enqueue (fila, elem, fila_tamanho,&ini,&fim);

   /*Tentando inserir o elemento 4 na fila!*/
   elem = 4;
   enqueue (fila, elem, fila_tamanho,&ini,&fim);

   /*Tentando retirar e imprimir o elemento 1 na fila!*/
   printf("%d\n", dequeue (fila, fila_tamanho,&ini,&fim));

   /*Tentando retirar e imprimir o elemento 2 na fila!*/
   printf("%d\n", dequeue (fila, fila_tamanho,&ini,&fim));

   free(fila);

   return 0;
}


#include "prog.c"
#include "fila.h"

void enqueue(int elem, Fila *f){
    if(f->fim< f->tam){
        f->vetor[f->fim] = elem;
        (f->fim)++;
    }else{
        printf("fila cheia\n");
        }
}

int dequeu(Fila *f){
    if(f->ini<f->fim){
        int atendimento = f->vetor[f->ini];
        (f->ini)++;
        return atendimento ;
    }else{
        printf("fila vazia\n");
    }
}

Fila* init(int tam){ //passa ja como um ponteiro para nao ter que passar os ponteiros depois
    Fila *f =(Fila *)malloc(sizeof(Fila));
    f->ini = 0;
    f->fim = 0;
    f->tam = tam;
    f->vetor = (int*)malloc(tam*sizeof(int));
    return f;

}

void destroy(Fila *f){
    free(f->vetor);
    free(f);

}




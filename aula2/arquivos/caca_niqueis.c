#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Initialization, should only be called once.

#include "queue.c"

#define size 11
#define spin 8
int main()
{

   /*TERMINAR*/
   /*Criar três filas para simular uma máquina caça-níqueis!*/
   /*Obrigatório usar as funções vistas em aula!*/
   /*Pode criar funções na TAD fila caso seja necessário, por exemplo, mostrar primeiro elemento da fila!*/
   /*Pode criar funções adicionais para girar uma fila!*/
   /*...*/
   srand(time(NULL));

   Fila *f1 = create_queue(size);
   Fila *f2 = create_queue(size);
   Fila *f3 = create_queue(size);

   int r1 = (rand() % (9 - 1)) + 1;
   int r2 = (rand() % (9 - 1)) + 1;
   int r3 = (rand() % (9 - 1)) + 1;

   for (int i = 1; i < 10; i++)
   {
      enqueue(f1, i);
      enqueue(f2, i);
      enqueue(f3, i);
   }
   for (int p = 0; p < spin; p++)
   {
      spinn(f1, r1);
      spinn(f2, r2);
      spinn(f3, r3);

      printf("%d", show_first(f1));
      printf("%d", show_first(f2));
      printf("%d\n", show_first(f3));
   }

   if (show_first(f1) == show_first(f2) && show_first(f2) == show_first(f3))
   {
      printf("-------------------| You WIN |-----------------------\n");
   }
   else
   {
      printf("-------------------| Play Again ? |-----------------------\n");
   }

   free_queue(f1);
   free_queue(f2);
   free_queue(f3);
   return 0;
}

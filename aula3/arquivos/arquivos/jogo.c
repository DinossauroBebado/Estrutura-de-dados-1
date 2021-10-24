#include "stack.c"
#include <time.h>
#define N 20

int main()
{
    srand(time(NULL));
    Stack *p1 = create_stack(N);
    Stack *p2 = create_stack(N);
    for (int i = 0; i < N / 2; i++)
    { //preenche a lista com numeros aleatorios(1 - 9)
        push(p1, (rand() % (9 - 1)) + 1);
        push(p2, (rand() % (9 - 1)) + 1);
    }

    while (!empty_stack(p1) && !empty_stack(p2)) //jogadas
    {
        int n_one = pop(p1);
        int n_two = pop(p2);
        printf("p1 %d - ", n_one);
        printf("p2 %d\n", n_two);
        if (n_one > n_two)
        { //p1 ganha
            int n = n_one - n_two;
            for (int i = 0; i < n; i++)
            {
                int aux = pop(p1);
                if (aux < 0)
                {
                    break;
                }
                push(p2, aux);
            }
        }
        if (n_two > n_one)
        { //p2 ganha
            int n = n_two - n_one;
            for (int i = 0; i < n; i++)
            {
                int aux = pop(p2);
                if (aux < 0)
                {
                    break;
                }
                push(p1, aux);
            }
        }
    }
    printf(empty_stack(p1) ? "Jogador 1 ganhou" : "Jogador 2 ganhou");
    free_stack(p1);
    free_stack(p2);
    return 0;
}

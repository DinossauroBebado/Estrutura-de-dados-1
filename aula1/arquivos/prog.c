
#include "fila.h"

int main(){
    int tam = 2;
    Fila* f1 = init(2);
    for(int i=0; i<tam;i++){
        enqueue(i, f1);
    }

    printf("%d\n",dequeu(f1));
    printf("%d\n",dequeu(f1));

    destroy(f1);

    return 0;
}

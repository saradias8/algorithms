#include <stdio.h>
#include <stdlib.h>

#define MaxH 6

typedef struct mHeap {
    int tamanho;
    int heap[MaxH];
} MinHeap;

int maior(MinHeap h) {
    int maior = h.heap[h.tamanho-1];
    int limite = h.tamanho / 2;

    for(int i = h.tamanho-1; i > limite; i--)
        //os maiores elementos estão na segunda metade (contém todas as folhas da aŕvore)
        if(h.heap[i] > maior) maior = h.heap[i];
    return maior;
}

int main() {
    MinHeap h;
    h.tamanho = 6;
    h.heap[0] = 1; h.heap[1] = 2; h.heap[2] = 4;
    h.heap[3] = 7; h.heap[4] = 8; h.heap[5] = 61;

    printf("maior elemento é %d\n", maior(h));
    return 0;
}

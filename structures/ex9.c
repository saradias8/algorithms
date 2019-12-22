#include <stdio.h>
#include <stdlib.h>

#define MaxH 10

typedef struct mHeap {
    int tamanho;
    int heap[MaxH];
} *MinHeap;

void swap(int h[], int x, int y) {
    int tmp = h[x];
    h[x] = h[y];
    h[y] = tmp;
}

void bubbleUp(int heap[], int i) { // recebe o array e a posição que foi trocada
    int pai = (i-1)/2; // pai de i
    if(i <= 0) return;
    if(heap[pai] > heap[i]) swap(heap, pai, i);
    bubbleUp(heap,pai);
}

void bubbleDown(MinHeap h, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    while(left < h->tamanho && right < h->tamanho
          && (h->heap[i] > left || h->heap[i] > right)) {

        if(left < right) {
            swap(h->heap, left, i);
            i = left;
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
        else {
            swap(h->heap, right, i);
            i = right;
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
    }
    if(left < h->tamanho && h->heap[i] > left) swap(h->heap, left, i);
}

MinHeap muda (MinHeap h, int pos, int valor) {
    int inicial = h->heap[pos];
    h->heap[pos] = valor;
    if(valor < inicial) bubbleUp(h->heap,pos);
    else if(valor > inicial) bubbleDown(h,pos);
    return h;
}

int main() {
    MinHeap heap;
    heap = malloc(sizeof(MinHeap));
    heap->tamanho = 5;
    heap->heap[0] = 1; heap->heap[1] = 2; heap->heap[2] = 3;
    heap->heap[3] = 5; heap->heap[4] = 8;

    printf("original:\n");
    for(int i = 0; i < heap->tamanho; i++) printf("%d  ", heap->heap[i]);
    printf("\n");

    heap = muda(heap, 1, -1);

    printf("troca 2 por -1:\n");
    for(int i = 0; i < heap->tamanho; i++) printf("%d  ", heap->heap[i]);
    printf("\n");

    heap = muda(heap, 2, 0);

    printf("troca 3 por 0:\n");
    for(int i = 0; i < heap->tamanho; i++) printf("%d  ", heap->heap[i]);
    printf("\n");

    heap = muda(heap, 0, 10);

    printf("troca -1 por 10:\n");
    for(int i = 0; i < heap->tamanho; i++) printf("%d  ", heap->heap[i]);
    printf("\n");

    return 0;
}

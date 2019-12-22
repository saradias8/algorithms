#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int size;
    int used;
    int *heap;
} Heap;

//full heap
Heap* resize(Heap *h) {
    h->size *= 2;
    h->heap = realloc(h->heap,h->size*sizeof(int));
    return h;
}

void swap(int a, int b, int h[]) {
    int tmp = h[b];
    h[b] = h[a]; h[a] = tmp;
}

void bubbleUp(int heap[], int i) {
    if(i<=0) return;
    if(heap[(i-1)/2] > heap[i]) swap((i-1)/2,i,heap);
    bubbleUp(heap,(i-1)/2);
}

void insertHeap(Heap *h, int x) {
    if(h->used == h->size) h = resize(h);
    h->heap[h->used] = x;
    bubbleUp(h->heap,h->used);
    h->used++;
}

int main() {
    Heap h;
    h.heap = malloc(sizeof(int)*10);
    h.size = 10;
    h.used = 0;

    insertHeap(&h,1);
    insertHeap(&h,-1);
    insertHeap(&h,3);

    printf("used = %d \n", h.used);
    for(int i=0;i<10;i++) printf("%d  ", h.heap[i]);
    printf("\n");

    return 0;
}

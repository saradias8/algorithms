#include <stdlib.h>
#include <stdio.h>

#define PARENT(i) (i-1)/2
#define LEFT(i)   2*i + 1
#define RIGHT(i)  2*i + 2

typedef struct minheap {
    int size;
    int used;
    int *values;
} *MinHeap;

void swap(int a, MinHeap h, int b) {
  int tmp = h->values[b];
  h->values[b] = h->values[a]; h->values[a] = tmp;
}

void bubbleDown(MinHeap h) {
    int i = 0;
    int N = h->used;
    while(LEFT(i)<N && RIGHT(i)<N) {
      if(h->values[LEFT(i)] <= h->values[RIGHT(i)]) {
        swap(i,h,LEFT(i));
        i = LEFT(i);
      }
      else {
        swap(i,h,RIGHT(i));
        i = RIGHT(i);
      }
    }
    if(LEFT(i)<N) swap(i,h,LEFT(i));
}

int extract(MinHeap h, int *x) {
    if(h == NULL) return 0;
    *x = h->values[0];
    swap(0,h,--h->used);
    //bubbleDown(h);
    return 1;
}

int *ordenados (MinHeap h) {
    int *ordenado;
    ordenado = malloc(sizeof(int)*h->used);
    int i; int x; int n = h->used;

    for(i=0;i<n;i++) {
        printf("%d\n", h->used);
        for (x=0;x<h->used;x++) printf("%d ",h->values[x]);
        printf("\n");
        extract(h,&x);
            ordenado[i] = x;
            bubbleDown(h);

    }

    free(h->values); free(h);

    return ordenado;
}

int main() {
    MinHeap h;
    int n;
    h = malloc(sizeof(MinHeap));
    h->size = 5;
    h->used = 4;
    n = h->used;
    h->values = malloc(sizeof(int)*h->size);
    h->values[0] = 1;
    h->values[1] = 4;
    h->values[2] = 5;
    h->values[3] = 10;

    int *ordena;

    ordena = ordenados(h);

    for(int i = 0 ; i < n ; i++) printf("%d ", ordena[i]);
    printf("\n");
    return 0;
}

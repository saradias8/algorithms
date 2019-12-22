#include <stdlib.h>
#include <stdio.h>

#define pai(i) (i+1)/2
#define left(i) 2*i +1
#define right(i) 2*i +2

typedef struct minheap {
    int size;
    int used;
    int values[];
} *MinHeap;

/*
    complexidade
            0(N) (passa por todas as folhas da arvore)
*/
int minHeapOK (MinHeap h) {
    int i = h->used-1;
    while(i>0) {
      if(h->values[pai(i)] > h->values[i]) return 0;
      i--;
    }
    return 1;
}

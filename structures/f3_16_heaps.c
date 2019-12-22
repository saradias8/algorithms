#include <stdio.h>
#include <stdlib.h>

// typedef struct buffer {
//   int value;
//   struct buffer *next;
// } *Buffer; //first in first out
//
// Buffer init () {
//   Buffer new = malloc(sizeof(struct buffer));
//   return new;
// }
//
// int empty (Buffer b) {
//   return (b == NULL);
// }
//
// int add (Buffer b, int x) {
//   Buffer *tmp = &b;
//
//   while((*tmp)->next != NULL) tmp = &((*tmp)->next);
//
//   *tmp = malloc(sizeof(struct buffer));
//   (*tmp)->value = x;
//   (*tmp)->next = NULL;
//
//   return 0;
// }
//
// int next (Buffer b, int *x) {
//   Buffer tmp = b;
//
//   b = b->next;
//   free(tmp);
//
//   return 0;
// }

#define PARENT(i) (i-1)/2
#define LEFT(i)   2*i + 1
#define RIGHT(i)  2*i + 2

typedef int Elem;

typedef struct {
  int size;
  int used;
  Elem *values;
} Heap;

Heap* newHeap (int size) {
  Heap *new = malloc(sizeof(Heap));
  new->size = size;
  new->used = 0;
  new->values = malloc(sizeof(int)*size);
  return new;
}

void print(Heap* h) {
  int i=0;
  while(i < h->used) {
    printf("%d\n", h->values[i]);
    i++;
  }
}

void swap(int a, Elem *h, int b) {
  int tmp = h[b];
  h[b] = h[a]; h[a] = tmp;
}

void bubbleUp (Elem h[], int i) {
  if(i<=0) return;
  if(h[PARENT(i)] > h[i]) swap(PARENT(i),h,i);
  bubbleUp(h, PARENT(i));
}

int insertHeap (Heap *h, Elem x) {
  if(h->used == h->size) {
    h->size *= 2;
    h->values = realloc(h->values, h->size*sizeof(int));
  }
  h->values[h->used] = x;
  bubbleUp(h->values, h->used);
  h->used++;
  return 0;
}

void bubbleDown (Elem h[], int N) {
  int i = 0;
  while(LEFT(i)<N && RIGHT(i)<N) {
    if(h[LEFT(i)] <= h[RIGHT(i)]) {
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

int extractMin (Heap *h, Elem *x) {
  swap(0, h->values, --h->used); //h->used--;
  bubbleDown(h->values,h->used);
  return 0;
}

int minHeapOK (Heap h) {
  //para cada PARENT o LEFT e o RIGHT são maiores que o PARENT
  int i = h.used-1;
  while(i>0) {
    if(h.values[PARENT(i)] > h.values[i]) return 0;
    i--;
  }
  return 1;
}

int main() {
  Heap* heap = newHeap(2);

  insertHeap(heap, 10);
  insertHeap(heap, 20);
  insertHeap(heap, 30);
  insertHeap(heap, 22);
  insertHeap(heap, 21);
  insertHeap(heap, 35);
  insertHeap(heap, 25);

  // print(heap);

  extractMin(heap,heap->values);

  print(heap);

  printf("ok? %d\n", minHeapOK(*heap));

  return 0;
}

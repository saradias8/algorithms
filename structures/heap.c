#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define PARENT(i) (i-1)/2  // os indices do array começam em 0
#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2

typedef int Elem; //heap elements
typedef struct {
  int size; //Heap capacity
  int used; //Heap size
  Elem *values;
} Heap;

void initHeap(Heap *h, int size) {
  h->size = size;
  h->used = 0;
  (h->values) = malloc(sizeof(Elem)*size);
}

void bubbleUp(Elem h[], int i) {
  Elem temp;

  while(h[PARENT(i)] > h[i]) {
    //swaps parent and son
    temp = h[PARENT(i)];
    h[PARENT(i)] = h[i];
    h[i] = temp;
    i = PARENT(i);
  }
  return;
}

int insertHeap(Heap* h, Elem x) {

  if(h->size == h->used) {
    h->values = malloc(sizeof(Elem)*2*(h->size)); //doubles array capacity
    h->size *= 2;
  }

  (h->values)[h->used] = x; //inserts x into left most position of array
  bubbleUp(h->values, h->used);
  (h->used)++;
  printf("used = %d\n", h->used);
  printf("(h->values)[h->used(%d)] = %d\n",h->used-1,(h->values)[h->used-1]);
  printf("(h->values)[h->used ant(%d)] = %d\n",h->used-2,(h->values)[h->used-2]);

  return 0;
}

int main() {
  Heap h; int x;

  initHeap(&h, 1);

  insertHeap(&h, 30);
  insertHeap(&h, 60);
  // insertHeap(&h, 40);
  // insertHeap(&h, 10);
  // insertHeap(&h, 100);
  // insertHeap(&h, 20);
  // insertHeap(&h, 90);
  // insertHeap(&h, 50);
  // insertHeap(&h, 80);
  // insertHeap(&h, 70);

  printf("Heap construída (capacidade %d):\n", h.size);
  for (int i = 0; i < h.used; i++)
      printf("%d\n", h.values[i]);
/*
  printf("Extracção de elementos:\n");
  while (extractMin(&h, &x))
      printf("%d\n", x);
*/
}

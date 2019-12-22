#include <stdio.h>
#include <stdlib.h>

#define RIGHT(i) 2*i+2
#define LEFT(i)  2*i+1

void swap(int a, int *h, int b) {
  int tmp = h[b];
  h[b] = h[a]; h[a] = tmp;
}

void bubbledown(int heap[], int N, int i) {
    while(LEFT(i)<N && RIGHT(i)<N) {
      if(heap[LEFT(i)] <= heap[RIGHT(i)]) {
        swap(i,heap,LEFT(i));
        i = LEFT(i);
      }
      else {
        swap(i,heap,RIGHT(i));
        i = RIGHT(i);
      }
    }
    if(LEFT(i)<N) swap(i,heap,LEFT(i));
}

/*
    complexidade [i=0;N-1/2](1/(2^N+1))
*/

void heapify (int v[], int N) {
    int i;
    for(i = (N-2)/2; i >= 0; i--)
        bubbledown(v,N,i);
}

/*
    v[50,20,42,13,2,12,36]

    v[2,13,12,20,50.42.36]

*/

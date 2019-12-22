#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
  int cap;
  int inicio, tamanho;
  int *valores;
} QUEUE;

void initQueue (QUEUE *q) {
  q->cap = 10;
  q->tamanho = 0;
  q->inicio = 0;
  q->valores = malloc(sizeof(int)*(q->cap));
}

int enqueue (QUEUE *q, int x) {
  if(q->tamanho == q->cap) return 1; //queue is full
  (q->valores)[q->inicio+q->tamanho] = ((q->valores)[q->inicio+q->tamanho] +1) % (q->cap); //circular queue
  (q->valores)[q->inicio + q->tamanho] = x; //x added to the back of the queue
  (q->tamanho)++;
  return 0;
}

int dequeue (QUEUE *q, int *x) {
  if(q->tamanho == 0) return 1; //queue is empty
  *x = *(q->valores+q->inicio); //saves 1st element to x
  (q->valores)[q->inicio] = ((q->valores)[q->inicio] +1) % (q->cap); //circular queue
  (q->inicio)++;
  (q->tamanho)--;
  return 0;
}

int main() {
  QUEUE q;
  int a, i, j, empty, full, error;

  initQueue(&q);

  error = 0;
  for(i=10;i<=100 && !error; i+=10) {
    error = enqueue(&q, i);
    printf("enqueued %d; ", i);
  }

  empty = dequeue(&q, &a);
  if(!empty) printf("dequeued %d; ", a);
  for(j=0; j<4 && !empty; j++) {
    empty = dequeue(&q, &a);
    if(!empty) printf("dequeued %d; ", a);
  }

  for(; i<=300 && !error; i+=10) {
    error = enqueue(&q, i);
    printf("enqueued %d; ", i);
  }

  empty = dequeue(&q, &a);
  if (!empty) printf("dequeued %d; ", a);
  for (; !empty; i++) {
      empty = dequeue(&q, &a);
      if (!empty) printf("dequeued %d; ", a);
  }

  return 0;
}

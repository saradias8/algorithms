#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
  int val;
  struct node* next;
} STACK;

void initStack(STACK *s) {
  printf("stack empty\n");
  s->val = -1;
  s = malloc(sizeof(struct node));
}

void print(STACK* s) {
  printf("\n");
  while(s != NULL) {
    printf("%d-> ", s->val);
    s = s->next;
  }
  printf("\n");
}

int pop(STACK *s) {
  STACK* temp = malloc(sizeof(struct node));
  int r;

  if(s == NULL) return -1;

  temp = s;
  r = temp->val;
  s = s->next;
  free(temp);

  return r;
}

void push(STACK *s, int x) {
  STACK* temp = malloc(sizeof(struct node));

  temp->val = x;
  temp->next = s;
  s = temp;
}

int emptycase (STACK *a, STACK *b) {
  int m;
  printf("stack b is empty\n");
  //tranfers elements from stack A to stack B
  while(a!=NULL) {
    m = pop(a);
    printf("%d popped from a\n", m);
    push(b,m);
    printf("%d pushed to b\n", m);
    a = a->next;
  }
  return m;
}

int main() {
  int i, m;
  STACK a; initStack(&a);
  STACK b; initStack(&b);

  for(i=10; i<=100; i+=10) {
    push(&a, i);
    printf("pushed %d; ", i);
  }

  for(i=10; i<=100; i+=10) {
    if((b.val)==-1) {
      printf("stack empty\n");
      m = emptycase(&a,&b);
    } else m=i;
    pop(&b);
    printf("popped %d; ", m);
  }

  return 0;
}

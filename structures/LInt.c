#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct lista {
  int valor;
  struct lista *prox;
} *Lista;

void initLista(Lista *s) {
  *s = NULL;
}

int isEmptyL(Lista s){
  return (s==NULL);
}
//static array
/*
void print(Lista a) {
  while(a != NULL) {
    printf("%d ", a->valor);
    a = a->prox;
  }
}

Lista cons(int x, Lista l) {
  Lista new = malloc(sizeof(struct lista));

  if(new != NULL) {
    new->valor = x;
    new->prox = l;
  }
  return new;
}

int length(Lista l) {
  int r=0;

  while(l!=NULL) {
    r++;
    l = l->prox;
  }
  return r;
}

Lista snoc1(int x, Lista l) {
  Lista pt = l, ant;

  while(pt!=NULL) {
    ant = pt;
    pt = pt->prox;
  }
  pt = malloc(sizeof(struct lista));
  pt->valor = x;
  pt->prox = NULL;
  if(l == NULL) l = pt;
  else ant->prox = pt;
  return l;
}

Lista snoc2(int x, Lista l) {
  Lista new, pt;

  new = malloc(sizeof(struct lista));
  new->valor = x;
  new->prox = NULL;

  if(l == NULL) l = new;
  else {
    pt = l;
    while(pt->prox != NULL)
      pt = pt->prox;
    pt->prox = new;
  }
  return l;
}

Lista snoc3(int x, Lista l) {
  Lista *el = &l;

  while(*el != NULL)
    el = &((*el)->prox);

  *el = malloc(sizeof(struct lista));
  (*el)->valor = x;
  (*el)->prox = NULL;

  return l;
}*/

//static array
/*
int push(Lista *l, int x) {
  Lista new = malloc(sizeof(struct lista));

  if(new) {
    new->valor = x;
    new->prox = *l;
    *l = new;
  }
  return 0;
}
*/
//dinamic array
/*
int pushL(Lista *s, int x) {
  int r=0;
  Lista *new;
  new = malloc(sizeof(Lista));

  if(new == NULL) r=1;
  else {
    new->value = x;
    new->prox = *s;
    *s = new;
  }
  return r;
}

int popL(Lista *s, int *x) {
  int r=0;
  Lista *tmp;

  if(*s == NULL) r=1;
  else {
    *x = (*s)->valor;
    tmp = *s;
    *s = (*s)->prox;
    free(tmp);
  }
  return r;
}
*/
/*
int append(Lista *l, int x) {
  Lista new = malloc(sizeof(struct lista));
  Lista aux = *l;

  while(aux->prox != NULL) aux = aux->prox;

  new->valor = x,
  new->prox = NULL;
  aux->prox = new;

  return 1;
}

Lista concatL(Lista a, Lista b) {
  Lista new = malloc(sizeof(struct lista)*2);

  new = a;
  while(new->prox != NULL) new = new->prox;
  new->prox = b;

  return new;
}

void appendL(Lista *a, Lista b) {
  if((*a)!=NULL && b!=NULL) {
    if((*a)->prox == NULL) (*a)->prox = b;
    else appendL(&((*a)->prox),b);
  }
}
*/

typedef struct stack {
  int size;
  int *values;
  int sp;
} Stack;

void initStack(Stack *s, int n) {
  s->size = n;
  s->values = malloc(sizeof(int) * n);
  s->sp = 0;
}

int isEmptyS (Stack *s) {
  return (s->sp == 0);
}

int doubleArray(Stack *s) {
  int r=0;
  s->size *= 2;
  s->values = realloc(s->values,s->size); //advantage: not transfer every element to the array
  return r;
}

int pushS (Stack *s, int x) {
  int r=0;
  if(s->sp == s->size) r = doubleArray(s);
  if(r == 0) s->values[s->sp++] = x;
  return r;
}

int length (int *array) {
  int i = 0;
  while(array) i++;
  return i;
}

int halfArray(Stack *s) {
  int r=0;
  s->size /= 2;
  s->values = realloc(s->values,s->size);
  return r;
}

int popS (Stack *s, int *x) {
  int r = 0;
  if(length(s->values) < 0.25*(s->size)) r = halfArray(s);
  if(s->sp == 0) r=1;
  else *x = s->values[--s->sp];
  return r;
}

int main() {
  return 0;
}

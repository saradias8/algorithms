#include <stdio.h>
#include <stdlib.h>

typedef struct btree {
  int value;
  struct btree *left, *right;
} Node, *BTree;

void print(BTree b) {
  if(b==NULL) printf("NULL\n");
  else {
    printf("%d\n", b->value);
    print(b->left); print(b->right);
  }
}

int size (BTree b) {
  BTree tmp = b;
  int tam;

  if(tmp==NULL) return 0;
  tam = 1 + size(b->left) + size(b->right);

  return tam;
}

int maximo (int a, int b) {
  if(a>=b) return a;
  else return b;
}

int altura (BTree b) {
  if(b==NULL) return 0;
  return ( 1 + maximo( altura(b->right), altura(b->left) ) );
}

BTree add (BTree b, int x) {
  BTree *tmp = &b;

  while((*tmp)!= NULL) {
    if(x <= (*tmp)->value) tmp= &((*tmp)->left);
    else tmp= &((*tmp)->right);
  }

  *tmp = malloc(sizeof(struct btree));
  (*tmp)->value = x;
  (*tmp)->left = (*tmp)->right = NULL;

  return b;
}

int search (BTree b, int x) {
  int r = 1;
  BTree tmp = b;

  if(tmp==NULL) r = 1;

  while(tmp != NULL) {
    if(tmp->value == x) { r = 0; break; }
    else if(x < tmp->value) tmp = tmp->left;
    else tmp = tmp->right;
  }
  return r;
}

int max (BTree b) {
  int maxi;
  BTree tmp = b;

  if(tmp==NULL) maxi = 0;
  while((tmp->right) != NULL) {
    tmp = tmp->right;
  }
  maxi = tmp->value;
  return maxi;
}

int main() {
  BTree a = malloc(sizeof(struct btree));

  a->value = 1; a->left = a->right = NULL;
  a = add(a,0);
  a = add(a,2);
  a = add(a,3);
  a = add(a,2);
  a = add(a,10);

  print(a);

  printf("\nsize %d\n", size(a));
  printf("altura %d\n", altura(a));
  printf("\nsearch ? %d\n", search(a,0));
  printf("\nmaior el %d\n", max(a));

  return 0;
}

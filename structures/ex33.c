#include <stdio.h>
#include <stdlib.h>

#define Bal 0
#define Esq 1
#define Dir -1

typedef struct avlnode {
    int valor;
    int balanco;
    struct avlnode *esq, *dir;
} *AVL;

/*
    complexidade 0(logN)
*/

int altura(AVL t) {
    int height = 0;

    if(t==NULL) return 0;
    else if(t->balanco <= 0) height = 1 + altura(t->dir);
    else height = 1 + altura(t->esq);

    return height;
}

int main() {
    AVL t;
    t = malloc(sizeof(AVL));

    t->valor = 1;
    t->balanco = -1;
    t->esq = NULL;
    t->dir = malloc(sizeof(AVL));
    t->dir->valor = 3;
    t->dir->balanco = 1;
    t->dir->dir = NULL;
    t->dir->esq = malloc(sizeof(AVL));
    t->dir->esq->valor = 2;
    t->dir->esq->balanco = 0;
    t->dir->esq->dir = t->dir->esq->esq = NULL;

    printf("altura %d \n", altura(t));

    return 0;
}

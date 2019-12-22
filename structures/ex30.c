#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    int altura;
    struct nodo *esq, *dir;
} Node, *AVL;

AVL rotateesq (AVL a) {
    AVL b;

    b = a->dir;
    a->altura = a->altura - 2;
    a->dir = b->esq;
    b->esq = a;

    return b;
}

int main() {
    AVL a;
    a = malloc(sizeof(AVL));

    a->valor = 3;
    a->altura = 3;
    a->esq = malloc(sizeof(AVL)); a->esq->valor = 2; a->esq->altura = 0;
    a->dir = malloc(sizeof(AVL)); a->dir->valor = 5; a->dir->altura = 2;
    a->dir->dir = malloc(sizeof(AVL)); a->dir->dir->valor = 8; a->dir->dir->altura = 1;
    a->dir->dir->esq = malloc(sizeof(AVL)); a->dir->dir->esq->valor = 6; a->dir->dir->esq->altura = 0;

    a = rotateesq(a);

    printf("altura %d\n", a->altura);

    return 0;
}

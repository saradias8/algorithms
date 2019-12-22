#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *AVL;

AVL rotateRight(AVL a) {
    AVL b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    return b;
}

AVL spine (AVL a) {
    if(a != NULL) {
        while(a->esq != NULL)
            a = rotateRight(a);
        a->dir = spine(a->dir);
    }
    return a;
}

void print(AVL a) {
    AVL aux = a;
    if(aux != NULL) printf("%d  ", aux->valor);
    if(aux->esq != NULL) {printf("esq ");print(aux->esq);}
    if(aux->dir != NULL) {printf("dir ");print(aux->dir);}
}

int main() {
    AVL a;
    a = malloc(sizeof(AVL));

    a->valor = 0;
    a->esq = malloc(sizeof(AVL));
    a->esq->valor = 1;
    a->esq->esq = malloc(sizeof(AVL));
    a->esq->esq->valor = 2;

    print(a);

    a = rotateRight(a);

    printf("\n");
    print(a);

    a = spine(a);
    printf("\n");
    print(a);

    return 0;
}

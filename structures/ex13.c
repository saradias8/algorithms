#include <stdio.h>
#include <stdlib.h>

typedef struct avlnode {
    int value, balance;
    struct avlnode *esq,*dir;
} *AVL;

int rdir(AVL *tptr) {
    if((*tptr)->esq == NULL) return -1;
    AVL* b = tptr;
    b = &(*tptr)->esq;
    (*tptr)->esq = (*b)->dir;
    (*b)->dir = tptr;
    tptr = b;
    return 0;
}

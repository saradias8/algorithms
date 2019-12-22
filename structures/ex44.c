#include <stdlib.h>
#include <stdio.h>

typedef struct llint {
    int value;
    struct llint *next;
} *LInt;

typedef struct avl {
    int value;
    int bal, deleted;
    struct avl *left, *right;
} *AVL;

AVL insert(AVL avl, int x) {

}

AVL fromList (LInt l, int n) {
    AVL new;
    new = malloc(sizeof(AVL));

    for(;l!=NULL;l=l->next) {
        new = insert(new,l->value);
    }

    return new;
}

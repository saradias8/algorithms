#include <stdlib.h>
#include <stdio.h>

#define LEFT 1
#define BAL 0
#define RIGHT -1

typedef struct avl {
    int value;
    int bal;
    struct avl *left, *right;
} *AVL;

AVL maisProfundo (AVL a) {
    AVL aux;
    aux = a;
    return aux;
}

int main() {
    AVL arv;
    arv = malloc(sizeof(AVL));

    arv->value = 2;
    arv->left = malloc(sizeof(AVL)); arv->left->value = 1;
    arv->right = arv->left->left = arv->left->right = NULL;

    arv = maisProfundo(arv);

    printf("%d\n", arv->value);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct avlnode {
    int value;
    int bal; // Left -1 Bal 0 Right 1
    struct avlnode *left, *right;
} *AVLTree;

/*
    complexidade 0(logN);
*/
int deepest (AVLTree *a) {
    int prof = 0;
    if((*a)==NULL) return prof;
    else if((*a)->bal <= 0 && (*a)->left != NULL) prof = deepest(&((*a)->left));
    else if((*a)->bal > 0 && (*a)->right != NULL) prof = deepest(&((*a)->right));
    return (1 + prof);
}

int main() {
    AVLTree arv;
    arv = malloc(sizeof(AVLTree));

    arv->value = 2;
    arv->left = malloc(sizeof(AVLTree)); arv->left->value = 1;
    arv->right = arv->left->left = arv->left->right = NULL;


    printf("prof %d\n", deepest(&arv));

    return 0;
}

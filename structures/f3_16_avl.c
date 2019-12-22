#include <stdio.h>
#include <stdlib.h>

typedef struct avl {
    int value;
    int bal; //left 1 right -1 bal 0
    struct avl *left, *right;
} AVLNode, *AVLTree;

int alturaAVL(AVLTree t) {
    int a = 0;
    AVLTree tmp;
    tmp = t;

    while(tmp != NULL) {
        a++;
        if(tmp->bal <= 0) tmp = tmp->right;
        else tmp = tmp->left;
    }
    return a;
}

int main() {
    AVLTree t;
    t = malloc(sizeof(AVLTree));

    t->value = 1;
    t->bal = 1;
    t->left = malloc(sizeof(AVLTree));
    t->left->value = 0; t->left->left = NULL;
    t->left->right =malloc(sizeof(AVLTree));
    t->left->right->value = 1;
    t->right = NULL;

    printf("altura de t: %d\n", alturaAVL(t));

    return 0;
}

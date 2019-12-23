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
    AVL r;
    
    if(a->bal > 0 && a->left != NULL) r = maisProfundo(a->left);
   
    else if(a->right != NULL) r = maisProfundo(a->right);
    
    else r = a;
   
    return r;
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

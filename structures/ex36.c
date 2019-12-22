#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *left, *right;
} Node, *BTree;

/*
    complexidade
            pior caso: é uma heap (verifica todos os nodos da árvore)
                        0(N)
            melhor caso: BTree é NULL ou só tem 1 elemento (a função para na primeira chamada)
                        0(1)
*/
int heapOK(BTree a) {
    int r=1;

    if(a == NULL || (a->right == NULL && a->left == NULL)) return 1;

    else if(a->left == NULL && a->value <= a->right->value)
        r = heapOK(a->right);

    else if(a->right == NULL && a->value <= a->left->value)
        r = heapOK(a->left);

    else if((a->value <= a->left->value) && (a->value <= a->right->value))
        r = heapOK(a->left) && heapOK(a->right);

    else return 0;

    return r;
}

int main() {
    BTree a;
    a = malloc(sizeof(BTree));

    a->value = 1;
    a->left = malloc(sizeof(BTree)); a->left->value = 0;
    a->right = NULL;

    printf("is heap? (1 for yes and 0 for no) answer: %d\n", heapOK(a));

    return 0;
}

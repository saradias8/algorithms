#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int dados;
} Data;

typedef struct node {
    int balance; // -1 LEFT 0 BALANCED 1 RIGHT
    char key[11];
    Data info;
    struct node *left, *right;
} Node;

typedef Node *Dictionary;

/*
    complexidade 0(logN)
*/

int allCopies(Dictionary dic, char key[11]) {
    int nr_copies = 0;

    if(dic == NULL) return 0;

    if(strcmp(key,dic->key) < 0) nr_copies = allCopies(dic->right,key);

    else if(strcmp(key,dic->key) > 0) nr_copies = allCopies(dic->left,key);

    else if(strcmp(key,dic->key) == 0) nr_copies = 1 + allCopies(dic->left,key);

    return nr_copies;
}

int main() {
    Dictionary dic;
    dic = malloc(sizeof(Node));

    strcpy(dic->key, "MANUEL");
    dic->right = NULL; dic->left = malloc(sizeof(Node));
    strcpy(dic->left->key, "MANUEL");
    dic->left->right = NULL; dic->left->left = malloc(sizeof(Node));
    strcpy(dic->left->left->key,"PEDRO");

    printf("%d\n", allCopies(dic,"MANUEL"));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int value;
    struct queue* next;
} *PQueue;

//ordem crescente
PQueue add(PQueue q, int x) {
    PQueue new;
    new = malloc(sizeof(struct queue));
    new->value = x;
    new->next = q;
    q = new;
    return q;
}

int main() {
    PQueue a,aux;
    a = malloc(sizeof(struct queue));

    a->value = 1;
    a->next = NULL;

    a = add(a,2);
    a = add(a,1);

    for(aux = a; aux != NULL; aux = aux->next)
        printf("%d\n", aux->value);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct edge {
    int dest;
    int cost;
    struct edge *next;
}*EList;
typedef EList Graph[N];

int pesoC (Graph g, int v[], int k) {
    int peso = 0;
    int i;
    EList t;

    for(i = 0; i < k-1; i++)
        for(t = g[v[i]]; t != NULL; t = t->next)
            if(t->dest == v[i+1]) peso += t->cost;
    return peso;
}

int main() {
    Graph g;

    g[0] = malloc(sizeof(EList));
    g[0]->dest = 1; g[0]->cost = 3;
    g[0]->next = NULL;

    g[1] = malloc(sizeof(EList));
    g[1]->dest = 2; g[1]->cost = 4;
    g[1]->next = malloc(sizeof(EList));
    g[1]->next->dest = 3; g[1]->next->cost = 1;
    g[1]->next->next = NULL;

    g[2] = NULL;

    g[3] = malloc(sizeof(EList));
    g[3]->dest = 0; g[3]->cost = 1;
    g[3]->next = NULL;

    int v[N] = {3,0,1,2};

    printf("peso do caminho %d \n", pesoC(g,v,N));

    return 0;
}

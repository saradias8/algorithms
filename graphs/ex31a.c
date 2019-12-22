#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct edge {
    int dest;
    int cost;
    struct edge *next;
}*EList;
typedef EList Graph[N];

int alcancaveisAUX(Graph g, int o, int ant[], int visitado[]) {
    EList t;

    visitado[o] = 1;

    for(t = g[o]; t != NULL; t = t->next) {
        ant[t->dest] = o;
        if(visitado[t->dest] == 0)
            alcancaveisAUX(g,t->dest,ant,visitado);
    }
    return 0;
}

int alcancaveis (Graph g, int o, int ant[]) {
    int visitado[N];

    for(int i = 0; i < N; i++) visitado[i] = 0;

    return aux(g,o,ant,visitado);
}

int main() {
    Graph g;

    g[0] = malloc(sizeof(EList));
    g[0]->dest = 3;
    g[0]->next = NULL;

    g[1] = malloc(sizeof(EList));
    g[1]->dest = 0;
    g[1]->next = NULL;

    g[2] = malloc(sizeof(EList));
    g[2]->dest = 1;
    g[2]->next = NULL;

    g[3] = NULL;

    int ant[N];
    for(int i = 0; i < N; i++) ant[i] = -1;

    alcancaveis(g,0,ant);

    for(int i = 0; i < N; i++) printf("%d  ", ant[i]);
    printf("\n");

    return 0;
}

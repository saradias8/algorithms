#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct edge {
    int dest;
    int cost;
    struct edge *next;
}*EList;
typedef EList Graph[N];

/*
    capacidade total = capacidade entrada - capacidade saída
*/
int capacidade1(Graph g, int v) {
    int capE = 0, capS = 0;
    int i;
    EList t;

    for(t = g[v]; t != NULL; t = t->next)
        capS += t->cost;

    for(i = 0; i < N; i++)
        for(t = g[i]; t != NULL; t = t->next)
            if(t->dest == v) capE += t->cost;

    return (capE - capS);
}
/*
    eficiente
    complexidade V+E
*/
void capacidade2(Graph g, int cap[]) {
    int i;
    EList t;

    for(i = 0; i < N; i++)
        for(t = g[i]; t != NULL; t = t->next){
            cap[t->dest] += t->cost;
            cap[i] -= t->cost;
        }
}

int main() {
    Graph g;

    g[0] = malloc(sizeof(EList));
    g[0]->dest = 1; g[0]->cost = 1;
    g[0]->next = malloc(sizeof(EList));
    g[0]->next->dest = 3;g[0]->next->cost = 3; g[0]->next->next = NULL;

    g[1] = malloc(sizeof(EList));
    g[1]->dest = 3; g[1]->cost = 2; g[1]->next = NULL;

    g[2] = malloc(sizeof(EList));
    g[2]->dest = 1; g[2]->cost = 3;
    g[2]->next = malloc(sizeof(EList));
    g[2]->next->dest = 3; g[2]->next->cost = 4; g[2]->next->next = NULL;

    g[3] = NULL;

    printf("capacidade do vértice 0 = %d\n", capacidade1(g,0));
    printf("capacidade do vértice 1 = %d\n", capacidade1(g,1));
    printf("capacidade do vértice 2 = %d\n", capacidade1(g,2));
    printf("capacidade do vértice 3 = %d\n", capacidade1(g,3));

    int v[N] = {0};
    capacidade2(g,v);
    for(int i = 0; i < N; i++)
        printf("capacidade eficiente do vértice %d = %d\n", i, v[i]);

    return 0;
}

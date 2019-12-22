#include <stdio.h>
#include <stdlib.h>
#include "ex42a.c"


int bipartido(Graph g, int v1[]) {
    int visitados[N]; int v2[N];
    struct edge* t;
    int i;
    for(i = 0; i < N; visitados[i] = 0, v1[i] = 0, v2[i] = 0, i++);

    for(i = 0; i < N; i++) {
        visitados[i] = 1;
        for(t = g[i]; t != NULL; t = t->next) {
            if(!visitados[t->dest]) {
                visitados[t->dest] = 1;
                v1[i] = 1;
                v2[t->dest] = 1;
            }
            else {
                if(v1[t->dest] && !v2[i]) v2[i] = 1;
                else if(v2[t->dest] && !v1[i]) v1[i] = 1;
            }
        }
        if(g[i] == NULL) v1[i] = 1;
    }
    for(i = 0; i < N; i++)
        if(v1[i] == v2[i]) return 0;

    if(bipartition(g,v1) && bipartition(g,v2)) return 1;

    return 0;
}

int main() {
    Graph g;

    g[0] = NULL;

    g[1] = malloc(sizeof(struct edge));
    g[1]->dest = 2;
    g[1]->next = malloc(sizeof(struct edge));
    g[1]->next->dest = 3;
    g[1]->next->next = NULL;

    g[2] = NULL;

    g[3] = malloc(sizeof(struct edge));
    g[3]->dest = 0;
    g[3]->next = NULL;

    int v[N];

    printf("é bipartido? %d \n", bipartido(g,v));

    return 0;
}

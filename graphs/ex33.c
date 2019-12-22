#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct edge {
    int dest;
    struct edge *next;
}*Graph[N];

void aux (Graph g, int o, int visited[]) {
    struct edge* t;
    visited[o] = 1;
    for(t = g[o]; t != NULL; t = t->next) {
        visited[t->dest] = 1;
        aux(g,t->dest,visited);
    }
}

int naoalcancavel (Graph g, int o) {
    int i;
    int visited[N];
    for(i=0;i<N;i++) visited[i] = 0;
    aux(g,o,visited);
    for(i=0;i<N;i++) if(visited[i] == 0) return i;
    return -1;
}

int main() {
    Graph g;
    for(int i = 0; i < 3; i++) g[i] = malloc(sizeof(struct edge));
    g[0]->dest = 1;
    g[0]->next = NULL;
    g[1]->dest = 2;
    g[1]->next = NULL;
    g[2]->dest = 3;
    g[2]->next = NULL;
    g[3] = NULL;

    printf("Vértice não alcaçável a partir de 0: %d\n", naoalcancavel(g,0));

    return 0;
}

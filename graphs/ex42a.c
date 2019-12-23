#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct edge {
    int dest;
    struct edge *next;
}*EList;
typedef EList Graph[N];

int bipartition (Graph g, int v1[]) {
    int i; EList t;

    for(i=0;i<N;i++)
        for(t=g[i];t!=NULL;t=t->next) {
            if((v1[t->dest] == 1 && v1[i] == 1)
            || (v1[t->dest] == 0 && v1[i] == 0))
                return 0;
        }
    return 1;
}

int main() {
    Graph g;

    g[0] = NULL;

    g[1] = malloc(sizeof(EList));
    g[1]->dest = 2;
    g[1]->next = malloc(sizeof(EList));
    g[1]->next->dest = 3;
    g[1]->next->next = NULL;

    g[2] = NULL;

    g[3] = malloc(sizeof(EList));
    g[3]->dest = 0;
    g[3]->next = NULL;

    int v1[N] = {1,1,0,0};

    printf("é bipartido? %d \n", bipartition(g,v1));

    return 0;
}

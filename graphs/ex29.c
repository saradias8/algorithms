#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct edge {
    int dest;
    struct edge *next;
}*Graph[N];

int antecessores (Graph g, int v) {
    int i; int a=0;
    struct edge *t;

    for(i=0;i<N;i++)
        for(t=g[i];t!=NULL;t=t->next)
            if(t->dest == v) a++;

    return a;
}

int main() {
    Graph g;

    g[0] = malloc(sizeof(struct edge));
    g[0]->dest = 1; g[0]->next = malloc(sizeof(struct edge));
    g[0]->next->dest = 2; g[0]->next->next = NULL;

    g[1] = malloc(sizeof(struct edge));
    g[1]->dest = 0; g[1]->next = malloc(sizeof(struct edge));
    g[1]->next->dest = 2; g[1]->next->next = NULL;

    g[2] = malloc(sizeof(struct edge));
    g[2]->dest = 0; g[2]->next = malloc(sizeof(struct edge));
    g[2]->next->dest = 1; g[2]->next->next = malloc(sizeof(struct edge));
    g[2]->next->next->dest = 3; g[2]->next->next->next = NULL;

    g[3] = malloc(sizeof(struct edge));
    g[3]->dest = 2; g[3]->next = NULL;

    printf("r de antecessores de 0: %d\n", antecessores(g,0));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct edge {
    int dest;
    int cost;
    struct edge *next;
}*EList;
typedef EList Graph[N];

int checkcoloring (Graph g, int c[]) {
    int i;
    EList t;
    for(i = 0; i < N; i++)
        for(t = g[i]; t != NULL; t = t->next)
            if(c[i] == c[t->dest]) return 0;
    return 1;
}

int main() {
    Graph g;

    g[0] = malloc(sizeof(EList));
    g[0]->dest = 1; g[0]->next = malloc(sizeof(EList));
    g[0]->next->dest = 2; g[0]->next->next = NULL;

    g[1] = malloc(sizeof(EList));
    g[1]->dest = 0; g[1]->next = malloc(sizeof(EList));
    g[1]->next->dest = 2; g[1]->next->next = NULL;

    g[2] = malloc(sizeof(EList));
    g[2]->dest = 0; g[2]->next = malloc(sizeof(EList));
    g[2]->next->dest = 1; g[2]->next->next = malloc(sizeof(EList));
    g[2]->next->next->dest = 3; g[2]->next->next->next = NULL;

    g[3] = malloc(sizeof(EList));
    g[3]->dest = 2; g[3]->next = NULL;

    int color[4] = {1,0,2,0};

    printf("color valid? %d \n", checkcoloring(g,color));

    return 0;
}

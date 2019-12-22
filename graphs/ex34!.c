#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct edge {
    int dest;
    struct edge *next;
}*EList;
typedef EList Graph[N];
/*
void succAUX (Graph g, int v, int n, int dis[], int d) {
    EList t;

    for(t = g[v]; t != NULL; t = t->next) {
        if(d < dis[t->dest]) dis[t->dest] = d;
        succAUX(g,t->dest,n,dis,d+1);
    }
}

int succN (Graph g, int v, int n) {
    int dis[N];
    int i; int r; int d=1;

    for(i = 0 ; i < N; i++) dis[i] = N;

    succAUX(g,v,n,dis,d);

    for(i = 0; i < N; i++)
        if(dis[i] <= n) r++;

    return r;
}
*/
int succN (Graph g, int v, int N) {
    int visitados[N], q[N], dis[N];
    int inicio = 0, fim = 0; int nrArestas = 0;

    visitados[v] = 1;
    while(inicio < fim) {
        v = q[inicio++];
        if(!visitados[v]) {
            dis[v] = nrArestas;
        }
    }

}

int main() {
    Graph g;

    g[0] = malloc(sizeof(EList));
    g[0]->dest = 4;
    g[0]->next = NULL;

    g[1] = malloc(sizeof(EList));
    g[1]->dest = 2;
    g[1]->next = malloc(sizeof(EList));
    g[1]->next->dest = 3;
    g[1]->next->next = NULL;

    g[2] = malloc(sizeof(EList));
    g[2]->dest = 0;
    g[2]->next = NULL;

    g[3] = malloc(sizeof(EList));
    g[3]->dest = 0;
    g[3]->next = malloc(sizeof(EList));
    g[3]->next->dest = 2;
    g[3]->next->next = malloc(sizeof(EList));
    g[3]->next->next->dest = 4;
    g[3]->next->next->next = NULL;

    g[4] = NULL;

    printf("%d\n", succN(g,1,1));

    return 0;
}

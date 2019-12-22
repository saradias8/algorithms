#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct edge {
    int dest;
    int cost;
    struct edge *next;
}*EList;
typedef EList Graph[N];


int ligacao (Graph g, int v1, int v2, int seccao) {
    int visitados[N];
    int q[N];
    int inicio = 0, fim = 0;
    int dis = 0;

    visitados[v1] = 1;
    q[fim++] = v1;

    while(inicio < fim) {
        v1 = q[inicio++]; //dequeue v1
        if(v1 == v2) dis = 1;
        for(t = g[v1]; t != NULL; t = t->next)
            if(!visitados[t->dest] && t->cost > seccao) {
                q[fim++] = t->dest; //enqueue t->dest
                visitados[t->dest] = 1;
            }
    }
    return r;
}

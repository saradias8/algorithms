#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct edge {
    int dest;
    struct edge *next;
}*ELIST;
typedef ELIST Graph[N];

/*
    complexidade
            0(V+E), porque percorre todas as arestas e todos os vértices do grafo original
                    não é possível saber quais vértices estão ligados a outros
                sem percorrer todas as arestas e os respetivos vértices
*/
void inverso(Graph g, Graph new) {
    struct edge * t; struct edge * aux;
    int i;

    for(i=0;i<N;i++){
        for(t = g[i]; t != NULL; t = t->next) {
            aux = malloc(sizeof(struct edge));
            aux->dest = i;
            aux->next = new[t->dest];
            new[t->dest] = aux;
        }
    }
}

int main() {
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct edge {
    int dest;
    int cost;
    struct edge *next;
}*EList;
typedef EList Graph[N];

int maior = 0;

int big(int v[]) {
    int count = 0;
    for(int i = 0; i < N; i++)
        if(v[i] == 1) count++;
    return count;
}

void clean(int v[]) {
    for(int i = 0; i < N; i++) v[i] = 0;
}

int maiorAUX (Graph g, int o, int v[], int visitados[]) {

    int i; EList t;

    for(i = o; i < N; i++){
        if(visitados[i] == 0) {
            visitados[i] = 1;
            v[i] = 1;
            for(t = g[i]; t != NULL; t = t->next)
                maiorAUX(g,t->dest,v,visitados);

            if(big(v) > maior) maior = big(v);
            printf("maior %d\n", maior);
        }
    }
    return maior;
}

int maior_cont(Graph g) {
    int v[N];
    int visitados[N];

    clean(v); clean(visitados);
    
    return maiorAUX(g,0,v,visitados);
}

int main() {
    Graph g;

    g[0] = NULL;

    g[1] = malloc(sizeof(EList));
    g[1]->dest = 3;
    g[1]->next = malloc(sizeof(EList));
    g[1]->next->dest = 5;
    g[1]->next->next = NULL;

    g[2] = malloc(sizeof(EList));
    g[2]->dest = 4;
    g[2]->next = NULL;

    g[3] = malloc(sizeof(EList));
    g[3]->dest = 1;
    g[3]->next = malloc(sizeof(EList));
    g[3]->next->dest = 5;
    g[3]->next->next = malloc(sizeof(EList));

    g[4] = malloc(sizeof(EList));
    g[4]->dest = 2;
    g[4]->next = malloc(sizeof(EList));
    g[4]->next->dest = 6;
    g[4]->next->next = NULL;

    g[5] = malloc(sizeof(EList));
    g[5]->dest = 1;
    g[5]->next = malloc(sizeof(EList));
    g[5]->next->dest = 3;
    g[5]->next->next = malloc(sizeof(EList));
    g[5]->next->next->dest = 7;
    g[5]->next->next->next = NULL;

    g[6] = malloc(sizeof(EList));
    g[6]->dest = 4;
    g[6]->next = NULL;

    g[7] = malloc(sizeof(EList));
    g[7]->dest = 5;
    g[7]->next = NULL;

    printf("maior continente: %d\n", maior_cont(g));

    return 0;
}

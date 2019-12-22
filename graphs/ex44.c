#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct edge {
    int dest;
    struct edge *next;
}*Graph[N];

/*
    complexidade
            0(V² + V*E) + 0(V) (primeiro while) + 0(E) (segundo while) para o pior caso
            0(V² + V + E + V*E)
*/
int mais_arestas (Graph g, int o) {
    int pais[N], pesos[N];
    int maiorI, i = 1, r = 0;

    int t = dijkstra(g,o,pais,pesos); // 0(v² + V*E)

    while(i < N) { //calcula o peso maior aka maior distância
        if(pesos[i] > pesos[i-1]) maiorI = i;
        i++;
    }
    while( maiorI != o) { //no array pais está armazenado o caminho mais curto até cada vértice
        maiorI = pais[maiorI];
        r++;
    }
    return r;
}

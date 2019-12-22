#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct edge {
    int dest;
    struct edge *next;
}*Graph[N];

int homoGraph (Graph g1, Graph g2, int f[]) {
    struct edge* t1, t2;
    int a, b, r=0; int i;
    for(i=0;i<N;i++)
        for(t1 = g1[i]; t1 != NULL && r == 0; t1 = t1->next) {
            a = f[i];
            b = f[t1->dest];
            for(t2 = g2[a]; t2 != NULL && r == 0; t2 = t2->next)
                if(t2->dest == b) r = 1;
        }
    return r;
}

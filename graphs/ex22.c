#include <stdio.h>
#include <stdlib.h>

#define N 5

struct edge {
    int dest;
    struct edge *next;
};
typedef struct edge *Graph[N];

int valid_path(Graph g, int path[], int n) {
    int found = 0; int r = 1;
    int i;
    struct edge *j;

    for(i=0;i<n-1;i++) { // g[path[i]] ---- g[path[i+1]] é uma aresta? continuar
        found = 0;
        for(j = g[path[i]]; j != NULL; j = j->next)
            if(j->dest == path[i+1]) {
                found = 1;
                break;
            }
        if(found == 0) {r = 0; break;}
    }
    return r;
}
/*
int valid_path(Graph g, int path[], int n) {
    int i=0; int r=1;
    struct edge *t;
    while(i<n && r) {
        int j = path[i]; t = g[j];
        while(t) {
            if(t->dest == path[i+1]) break;
            else t = t->next;
            if(!t) r=0;
        }
        i++;
    }
    return r;
}*/

int main() {
    Graph g;
    g[0] = malloc(sizeof(struct edge));
    g[0]->dest = 2;
    g[0]->next = malloc(sizeof(struct edge));
    g[0]->next->dest = 1; g[0]->next->next = NULL;
    g[1] = malloc(sizeof(struct edge));
    g[1]->dest = 3; g[1]->next = NULL;
    g[2] = malloc(sizeof(struct edge));
    g[2]->dest = 1;
    g[2]->next = malloc(sizeof(struct edge));
    g[2]->next->dest = 4; g[2]->next->next = NULL;
    g[3] = NULL;
    g[4] = malloc(sizeof(struct edge));
    g[4]->dest = 1; g[4]->next = NULL;

    int path1[4] = {0,2,4,3};
    int path2[3] = {0,4,1};
    int path3[3] = {0,1,3};
    int path4[4] = {2,4,1,3};

    printf("is path[0,2,4,3] valid? %d\n", valid_path(g, path1, 4));  // no
    printf("is path[0,4,1] valid? %d\n", valid_path(g, path2, 3));    // no
    printf("is path[0,1,3] valid? %d\n", valid_path(g, path3, 3));    // yes
    printf("is path[2,4,1,3] valid? %d\n", valid_path(g, path4, 4));  // yes

    return 0;
}

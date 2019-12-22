#include <stdio.h>
#include <stdlib.h>

typedef struct nodo *ABPInt;

struct nodo {
    int valor;
    ABPInt esq, dir;
};

int pertence (int l, int u, int x) {
    if(x > l && x < u) return 1;
    return 0;
}

/*
    complexidade:
        melhor caso: a árvore é nula ou o primeiro nodo pertence ao intervalo
                    Q(1) (tempo constante)
        pior caso: nenhum nodo da árvore está no intervalo
                O(N) (tempo linear -> percorre todos os nodos da árvore)
*/
/*
    return:
        1 -> elemento existe;
        0 -> elemento não existe;
*/
int procura (ABPInt a, int l, int u) {
    int r = 0;
    if(a == NULL) return 0;
    if(pertence(l,u,a->valor) == 1) return 1;
    r = procura(a->esq,l,u) || procura(a->dir,l,u);
    return r;
}

int main() {
    ABPInt a;
    a = malloc(sizeof(struct nodo));
    a->valor = 1;
    a->esq = malloc(sizeof(struct nodo));
    a->esq->valor = 2;
    a->dir = NULL;
    printf("existe elemento entre 1 e 4? %d\n", procura(a,1,4));
    printf("existe elemento entre 1 e 2? %d\n", procura(a,1,2));
    return 0;
}

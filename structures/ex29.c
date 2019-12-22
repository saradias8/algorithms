#define Bal 0
#define Esq -1
#define Dir 1

typedef struct avlNode *AVL;

struct avlnode {
    int bal;
    int valor;
    struct avlNode *esq,*dir;
}

int altura (AVL a) {
    int alt = 0;
    AVL tmp;
    tmp = a;
    while(tmp!=NULL) {
        if(tmp->bal == Esq) tmp = tmp->esq;
        else tmp = tmp->dir;
        alt++;
    }
    return alt;
}

int main() {
    AVL a;
    a = malloc(sizeof(AVL));
    a->esq->valor = 1;
    a->bal = Esq;
    a->dir = NULL;
    printf("altura %d\n", altura(a));
    return 0;
}

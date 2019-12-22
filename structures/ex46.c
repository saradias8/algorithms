#include <stdlib.h>
#include <stdio.h>

#define LIVRE 0
#define APAGADO 1
#define OCUPADO 2

struct entry {
    int value, status;
};

typedef struct thash {
    int ocupado, tamanho;
    struct entry *tabela;
} *THash;

/*
    // linear probing //

    hash(x,size) = x % size

    if(ocupado > 50%) size = 2*size+1
    if(ocupado < 33%) size = 2*size/3

*/

int hash(int value, int size) {
    return (value%size);
}

THash resize(THash h) {
    THash aux;
    aux = malloc(sizeof(THash));
    int i;
    int hash_value;

    aux->tamanho = 2 * h->tamanho / 3;
    aux->tabela = malloc(sizeof(struct entry) * aux->tamanho);

    for(i = 0; i < aux->tamanho; i++) aux->tabela[i].status = LIVRE;

    for(i = 0; i < h->tamanho; i++)
        if(h->tabela[i].status == OCUPADO) {
            hash_value = hash(h->tabela[i].value, aux->tamanho);

            while(aux->tabela[hash_value].status == OCUPADO) hash_value = (hash_value+1) % aux->tamanho;

            aux->tabela[hash_value].value = h->tabela[i].value;
            aux->tabela[hash_value].status = OCUPADO;
        }
    aux->ocupado = h->ocupado;

    return aux;
}


int remover(THash h, int value) {
    int i;

    for(i = hash(value,h->tamanho); i < h->tamanho
                                    && h->tabela[i].value != value
                                    && h->tabela[i].status == OCUPADO; i = (i+1) % h->tamanho);
    if(i >= h->tamanho || h->tabela[i].status != OCUPADO) return 1; //elemento não existe na hash table

    h->tabela[i].status = APAGADO;
    h->ocupado--;
    //resize && rehash
    h = resize(h);
    return 0;
}

int main() {
    THash h;
    h = malloc(sizeof(THash));
    h->tabela = malloc(sizeof(struct entry) * 10);
    h->tamanho = 10;
    h->tabela[0].value = 10;
    h->tabela[0].status = OCUPADO;
    h->tabela[5].value = 5;
    h->tabela[0].status = OCUPADO;
    h->ocupado = 2;

    remover(h,5);

    for(int i = 0; i<h->tamanho; i++) {
        if(h->tabela[i].status == OCUPADO) printf("%d -> %d  ", i,h->tabela[i].value);
    }

    return 0;
}

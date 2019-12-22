#include <stdio.h>
#include <stdlib.h>

#define HSIZE 1000

typedef struct lista {
    int valor;
    struct lista *prox;
} *HashChain[HSIZE];

typedef struct celula {
    int estado; // 0 LIVRE // 1 OCUPADO // 2 REMOVIDO
    int valor;
} HashOpen[HSIZE];

int hash (int chave, int size) {
    return (chave%size);
}

// considerando que as tabelas têm a mesma dimensão
int fromChain (HashChain h1, HashOpen h2) {
    int hash_value, valor;
    int i;

    for(i = 0; i < HSIZE; i++) {
        for(; h1[i] != NULL; h1[i] = h1[i]->prox) {
            valor = h1[i]->valor;
            hash_value = hash(valor,HSIZE);

            while(h2[hash_value].estado == 1) hash_value = (hash_value + 1) % HSIZE;

            h2[hash_value].valor = valor;
            h2[hash_value].estado = 1;
        }
    }

    return 0;
}

int main() {
    return 0;
}

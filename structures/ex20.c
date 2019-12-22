#include <stdio.h>
#include <stdlib.h>

typedef struct entryC {
    char key[10];
    void *info;
    struct entryC *next;
} EntryChain;

typedef struct hashT {
    int hashsize;
    EntryChain *table;
} *HashTableChain;


/*
    fator de carga  -> razão entre o nr de pares armazenados e o tamanho do array
                    -> número médio de colisões que se deram na tabela
*/

float loadFactorC (HashTableChain t) {
    int colisoes = 0; int i;

    for(i = 0; i < t->hashsize; i++)
        //for(; t->table[i]; t->table[i] = t->table[i].next)
        colisoes++;

    return (colisoes / t->hashsize);
}

int main() {
    HashTableChain h;
    h = malloc(sizeof(HashTableChain));
    h->hashsize = 4;

    return 0;
}

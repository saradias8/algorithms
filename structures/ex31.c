#include <stdio.h>
#include <stdlib.h>

#define Livre 0
#define Ocupado 1
#define Apagado 2

typedef struct key *Key;

struct celula {
    Key k;
    void *info;
    int estado; // Livre // Ocupado // Apagado
}

typedef struct shash {
    int tamanho, ocupados, apagados;
    struct celula *Tabela;
} *THash;

int hash (Key key, int size) {
    return (key%size);
}

void remApagados (THash h) {

}

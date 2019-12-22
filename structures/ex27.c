#include <stdio.h>
#include <stdlib.h>

typedef struct entry {
    char key[10];
    void *info;
    struct entry *next;
} *Entry;

typedef struct hashT {
    int hashsize;
    Entry *table;
} *HashTable;


int hash (int hashsize, char key[]){
    return (atoi(key)%hashsize);
}

HashTable newTable (int hashsize) {
    HashTable new;

    new = malloc(sizeof(HashTable));
    new->hashsize = hashsize;
    new->table = malloc(sizeof(Entry));
    new->table = NULL;

    return new;
}

int main() {
    HashTable h;
    h = newTable(5);
    printf("%d\n", h->hashsize);
    return 0;
}

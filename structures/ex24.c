#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STATUS_FREE   0
#define STATUS_USED   1
#define STATUS_DELETE 2

typedef struct entryO {
    int status;
    char *key;
    void *info;
} EntryOAdd;

typedef struct hashT {
    int size;
    int used;
    EntryOAdd *table;
} *HashTableOAddr;

int hash(char key[], int size) {
    return (atoi(key)%size);
}

int doubleTable (HashTableOAddr h) {
    int i; int hash_value;
    HashTableOAddr aux;
    aux = malloc(sizeof(HashTableOAddr)*2*h->size);
    aux->size = 2 * h->size; //doubles size
    aux->used = h->used;

    for(i=0;i<aux->size;i++) aux->table[i].status = STATUS_FREE;

    for(i=0;i<h->size;i++) //copies each element to new hashtable
        if(h->table[i].status == STATUS_USED){
            hash_value = hash(h->table[i].key,aux->size);

            while(aux->table[hash_value].status == STATUS_USED)
                hash_value = (hash_value + 1) % aux->size;

            aux->table[i].status = STATUS_USED;
            strcpy(aux->table[i].key,h->table[i].key);
            strcpy(aux->table[i].info,h->table[i].info);
        }
    return aux->size;
}

int main() {
    HashTableOAddr h;
    h = malloc(sizeof(HashTableOAddr));

    h->size = 2;
    h->used = 1;
    h->table = malloc(sizeof(EntryOAdd)*h->size);

    // h->table[0].status = STATUS_USED;
    // strcpy(h->table[0].key, "4");

    printf("size of h %d \n", h->size);

    printf("new size of h %d \n", doubleTable(h));
    return 0;
}

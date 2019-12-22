#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 31

typedef char KeyType[9];
typedef void *Info;

typedef struct entry {
    KeyType key;
    Info info;
    struct entry *next;
} Entry, *HashTable[HASHSIZE];


int hash(KeyType key) {
    return (atoi(key)%HASHSIZE);
}

void initializeTable(HashTable h) {
    h = malloc(sizeof(HashTable));
}

void clearTable(HashTable h) {
    int i;

    for(i=0;i<HASHSIZE;i++) {
        strcpy(h[i]->key,"");
        h[i]->info = "";
        h[i]->next = NULL;
    }
}

//does not work
void insertTable(HashTable h, KeyType key, Info info) {
    Entry *tmp, *new;
    new = malloc(sizeof(Entry));

    strcpy(new->key,key);
    new->info = info;
    new->next = NULL;

    tmp = h[hash(key)];

    while(tmp->next != NULL) tmp = tmp->next;

    tmp->next = new;
}

int main(){
    int i;
    HashTable h;

    initializeTable(h);
    clearTable(h);

    insertTable(h,"12","0");

    for(i=0;i<HASHSIZE;i++) {
       printf("%d  key  %s\n", i,h[i]->key);
       printf("   info %s\n", h[i]->info);
    }

    return 0;
}

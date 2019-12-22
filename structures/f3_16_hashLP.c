#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASHSIZE 7     // nr primo
#define EMPTY    ""
#define DELETED  "-"

typedef char KeyType[9];
typedef void *Info;

typedef struct entry {
    KeyType key;
    Info info;
} Entry, HashTable[HASHSIZE];


int hash(KeyType key) {
    return (atoi(key) % HASHSIZE);
}

void initializeTable(HashTable h) {
    h = malloc(sizeof(HashTable));
}

void clearTable(HashTable h) {
    int i;
    for(i=0;i<HASHSIZE;i++) {
        h[i].info = EMPTY;
        strcpy(h[i].key,"");
    }
}
/*
void insertTable_LP (HashTable h, KeyType key, Info info) {
    int ha = hash(key);
    int i = ha;

    while(strcmp(h[i].info,EMPTY)!=0 && strcmp(h[i].info,DELETED)!=0) i++;

    if(i<HASHSIZE) {
        strcpy(h[i].key,key);
        h[i].info = info;
    }
    else {
        i=0;
        while(strcmp(h[i].info,EMPTY)!=0 && strcmp(h[i].info,DELETED)!=0) i++;
        if(i<HASHSIZE) {
          strcpy(h[i].key,key);
          h[i].info = info;
        }
    }
}*/

void insertTable_LP(HashTable h, KeyType key, Info info) {
    int i;

    for(i=hash(key); strcmp(h[i].info,EMPTY)!=0 && strcmp(h[i].info,DELETED)!=0; i = (i+1)%HASHSIZE);

    strcpy(h[i].key,key);
    h[i].info = info;
}

void deleteTable_LP(HashTable h, KeyType key) {
    int i;

    for(i = hash(key); strcmp(h[i].key,key) != 0; i = (i+1)%HASHSIZE);

    strcpy(h[i].key,"");
    h[i].info = DELETED;
}

int retrieveTable_LP(HashTable h, KeyType key) {
    int i;

    for(i = hash(key); strcmp(h[i].key,key) != 0 &&
                       strcmp(h[i].info,EMPTY) != 0 &&
                       strcmp(h[i].info,DELETED) != 0; i = (i+1)%HASHSIZE);

    if(strcmp(h[i].info,EMPTY) == 0 || strcmp(h[i].info,DELETED) == 0) return -1;

    return i;
}

int main() {
    int i;
    KeyType key0,key1,key2,del,search;
    Info info;
    info = "1";
    HashTable h;
    initializeTable(h);
    clearTable(h);

    printf("choose key 1: "); scanf("%s",key0);
    printf("hash of your key: %d\n\n", hash(key0));
    insertTable(h,key0,info);

    printf("choose key 2: "); scanf("%s",key1);
    printf("hash of your key: %d\n\n", hash(key1));
    insertTable(h,key1,info);

    printf("choose key 3: "); scanf("%s",key2);
    printf("hash of your key: %d\n\n", hash(key2));
    insertTable(h,key2,info);

    printf("hashtable: \n");
    for(i=0;i<HASHSIZE;i++) {
       printf("%d  key  %s\n", i,h[i].key);
       printf("   info %s\n", h[i].info);
    }

    printf("\nchoose key to be deleted: "); scanf("%s",del);

    if(strcmp(del,key0)==0 || strcmp(del,key1)==0 || strcmp(del,key2)==0) {
        printf("\nchosen key will be deleted...\n\n");
        deleteTable_LP(h,del);
        printf("new hashtable: \n");
        for(i=0;i<HASHSIZE;i++) {
           printf("%d  key  %s\n", i,h[i].key);
           printf("   info %s\n", h[i].info);
        }
    }
    else printf("\nthe key you chose doesn't exist\n");

    printf("\nsearch for key "); scanf("%s",search);
    printf("key found in position %d (-1 if it was not found)\n",retrieveTable_LP(h,search));

    printf("\nGOODBYE\n");

    return 0;
}

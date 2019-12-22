#include <stdlib.h>

#define MAX 100

typedef char SetInt[MAX];
typedef int MSetInt[MAX];

int initSet(SetInt s) {
  int i;
  for(i=0;i<MAX;s[i++]=0);
}

void initMSet(MSetInt s) {
  int i;
  for(i=0;i<MAX;s[i++]=0);
}

int emptySet(SetInt s) {
  int i, r=1;

  for(i=0; i<MAX && r==1; i++)
    if(s[i]!=0) r=0;

  return r;
}

int emptyMSet(MSetInt s) {
  int i, r=1;

  for(i=0; i<MAX && r==1; i++)
    if(s[i]!=0) r=0;

  return r;
}

int addSet(SetInt s, int x) {
  s[x] = 1;
  return 0;
}

int addMSet(MSetInt s, int x) {
  s[x] += 1;
  return 0;
}

int searchSet(SetInt s, int x) {
  return (s[x]);
}

int searchMSet(MSetInt s, int x) {
  return (s[x]);
}

void unionSet(SetInt s1, SetInt s2, SetInt r) {
  int i;
  for(i=0;i<MAX;i++)
    r[i] = s1[i] || s2[i];
}

void unionMSet(MSetInt s1, MSetInt s2, MSetInt r) {
  int i;
  for(i=0;i<MAX;i++)
    if(s1[i] > s2[i]) r[i] = s1[i];
    else r[i] = s2[i];
}

void intersectSet(SetInt s1, SetInt s2, SetInt r) {
  int i;
  for(i=0;i<MAX;i++)
    r[i] = s1[i] && s2[i];
}

void intersectMSet(MSetInt s1, MSetInt s2, MSetInt r) {
  int i;
  for(i=0;i<MAX;i++)
    if(s1[i]>s2[i]) r[i] = s2[i];
    else r[i] = s1[i];
}

void differenceSet(SetInt s1, SetInt s2, SetInt r) {
  int i;
  for(i=0;i<MAX;i++)
    r[i] = s1[i] && !(s2[i]);
}

void differenceMSet(MSetInt s1, MSetInt s2, MSetInt r) {
  int i;
  for(i=0;i<MAX;i++)
    if(s1[i]>s2[i]) r[i] = s1[i] - s2[i];
    else r[i] = 0;
}

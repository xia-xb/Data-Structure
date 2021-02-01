#ifndef MYLIST1_H
#define MYLIST1_H

#define MAXSIZE 20

typedef int elemType;

struct list{
    int data[MAXSIZE];
    int length;
};

void InitList(list &L);
bool ListEmpty(list &L);
void ClearList(list &L);
bool GetElem(list &L, int i, elemType &e);
int LocateElem(list &L, elemType &e);
bool ListInsert(list &L, int i, elemType &e);
bool ListDelete(list &L, int i, elemType &e);
int ListLength(list &L);

// ***********************************************************************

// ***********************************************************************

/* void InitList(list *L);
bool ListEmpty(list *L);
void ClearList(list *L);
bool GetElem(list *L, int i, elemType &e);
int LocateElem(list *L, elemType &e);
bool ListInsert(list *L, int i, elemType &e);
bool ListDelete(list *L, int i, elemType &e);
int ListLength(list *L); */


#endif
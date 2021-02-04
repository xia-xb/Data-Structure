#ifndef STATICLIST_H
#define STATICLIST_H

#define MAXSIZE 20
typedef int ElemType;

struct Component {
    ElemType data;
    int cur;
};

int ListLength(Component space[MAXSIZE]);
int Malloc_SLL(Component space[MAXSIZE]);
void Free_SLL(Component space[MAXSIZE], int k);
bool InitList(Component spce[MAXSIZE]);
bool ListInsert(Component space[MAXSIZE], int k, ElemType e);
bool ListDelete(Component space[MAXSIZE], int k);

#endif
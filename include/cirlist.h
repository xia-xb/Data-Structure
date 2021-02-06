#ifndef CIRLIST_H
#define CIRLIST_H

typedef int ElemType;

struct Node {
    ElemType data;
    Node *Next;
};

bool InitList(Node &list);
int ListLength(Node &list);
bool ListInsert(Node &list, int i, ElemType &e);
bool ListDelte(Node &list, int i, ElemType &e);
bool GetElem(Node &list, int i, ElemType &e);
#endif
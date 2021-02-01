#ifndef MYLIST2_H
#define MYLIST2_H

typedef int ElemType;


typedef struct Node
{
    ElemType data;
    struct Node *Next;
}Node;
typedef struct Node *LinkList;

bool GetElem(LinkList L,int i,ElemType *e);
bool ListInsert(LinkList *L,int i,ElemType e);
bool ListDelete(LinkList *L,int i,ElemType *e);
void CreatListHead(LinkList *L,int n);
bool ClearList(LinkList *L);



#endif
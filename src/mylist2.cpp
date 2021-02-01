#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "mylist2.h"

using namespace std;

bool GetElem(LinkList L,int i,ElemType *e){
    int j;
    LinkList p;
    p=L->Next;
    j=1;
    while (p && j<i){
        p=p->Next;
        j++;
    }
    if(!p || j>i){
        return 0;
    }
    *e=p->data;
    return 1;
}

bool ListInsert(LinkList *L,int i,ElemType e){
    int j;
    LinkList p,s;
    p=*L;
    j=1;
    while(p && j<i){
        p=p->Next;
        j++;
    }
    if(!p || j>i){
        return 0;
    }
    s=(LinkList)malloc(sizeof(Node));
    s->data=e;
    s->Next=p->Next;
    p->Next=s;
    return 1;
}

bool ListDelete(LinkList *L,int i,ElemType *e){
    int j;
    LinkList p,q;
    p=*L;
    j=1;
    while(p->Next && j<i){
        p=p->Next;
        j++;
    }
    if(!(p->Next) || j>i){
        return 0;
    }
    q=p->Next;
    p->Next=q->Next;
    *e=q->data;
    free(q);
    return 1;
}

void CreatListHead(LinkList *L,int n){
    LinkList p,r;
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    r=*L;
    for(i=0;i<n;i++){
        p=(Node *)malloc(sizeof(Node));
        p->data=rand()%100+1;
        r->Next=p;
        r=p;
    }
    r->Next=NULL;
}

bool ClearList(LinkList *L){
    LinkList p,q;
    p=(*L)->Next;
    while(p){
        q=p->Next;
        free(p);
        p=q;
    }
    (*L)->Next=NULL;
    return 1;
}



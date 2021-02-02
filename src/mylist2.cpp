#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "mylist2.h"

using namespace std;

/* bool GetElem(LinkList L,int i,ElemType *e){
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
} */


// ***********************************************************************************************

bool GetElem(HeadNode L,int i,ElemType *e){
    if(i>L.length || i<=0){
        return 0;
    }
    else{
        Node *p=L.Next;
        for(int j=1;j<=i;j++){
            if(j==1){
                continue;
            }
            else{
                p=(*p).Next;
            }
        }
        *e=(*p).data;
        return 1;
    }
}

bool ListInsert(HeadNode &L,int i,ElemType e){
    if(i>L.length+1 || i<=0){
        return 0;
    }
    else{
        Node *p=L.Next;
        for(int j=1;j<=i-1;j++){
            if(j==1){
                continue;
            }
            p=(*p).Next;
        }
        Node *r=new(Node);
        (*r).data=e;
        (*r).Next=(*p).Next;
        (*p).Next=r;
        L.length++;
        return 1;
    }
}

bool ListDelete(HeadNode &L,int i,ElemType &e){
    if(i>L.length || i<=0){
        return 0;
    }
    else{
        Node *p=L.Next;
        for(int j=1;j<=i-1;j++){
            if(j==1){
                continue;
            }
            p=(*p).Next;
        }
        Node *q=(*p).Next;
        e=(*q).data;
        (*p).Next=(*q).Next;
        free(q);
        L.length--;
        return 1;
    }
}

void CreatListHead(HeadNode &L,int n){
    L.length=0;
    L.Next=NULL;
    for(int i=1;i<=n;i++){
        Node *p=new(Node);
        (*p).data=i;
        (*p).Next=L.Next;
        L.Next=p;
        L.length++;
    }
}

bool ClearList(HeadNode &L){
    if(L.length==0){
        return 1;
    }
    else{
        Node *p=L.Next;
        while(p){
            Node *q=(*p).Next;
            L.Next=q;
            free(p);
            p=q;
            L.length--;
        }
    }
    L.Next=NULL;
    return 1;
}


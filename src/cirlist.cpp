#include "cirlist.h"

#include <iostream>

using namespace std;

bool InitList(Node &list) {
    list.Next = &list;
    return 1;
}

int ListLength(Node &list) {
    int length = 0;
    Node *p = list.Next;
    while (p != (&list)) {
        p = p->Next;
        length++;
    }
    return length;
}

bool ListInsert(Node &list, int i, ElemType &e) {
    if (i <= 0 || i > ListLength(list) + 1) {
        return 0;
    }
    Node *p = &list;
    for (int j = 1; j <= i - 1; j++) {
        p = p->Next;
    }
    Node *q = new (Node);
    (*q).data = e;
    (*q).Next = p->Next;
    p->Next = q;
    return 1;
}

bool ListDelte(Node &list, int i, ElemType &e) {
    if (i <= 0 || i > ListLength(list)) {
        return 0;
    }
    Node *p = &list;
    for (int j = 1; j <= i - 1; j++) {
        p = p->Next;
    }
    Node *q = p->Next;
    e = q->data;
    p->Next = q->Next;
    free(q);
    return 1;
}

bool GetElem(Node &list, int i, ElemType &e) {
    if (i <= 0 || i > ListLength(list)) {
        return 0;
    }
    Node *p = &list;
    for (int j = 1; j <= i; j++) {
        p = p->Next;
    }
    e = p->data;
    return 1;
}

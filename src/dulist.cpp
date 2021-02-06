#include "dulist.h"

#include <iostream>

Dulist::Dulist() {
    this->data = 0;
    this->length = 0;
    this->pre = this;
    this->next = this;
}

Dulist::~Dulist() {}

bool Dulist::Insert(int i, ElemType &e) {
    if (i <= 0 || i > this->length + 1) {
        return 0;
    }
    Dulist *p = this;
    for (int j = 1; j <= i - 1; j++) {
        p = (*p).next;
    }
    Dulist *q = new (Dulist);
    (*q).data = e;
    (*q).next = (*p).next;
    (*q).pre = p;
    p->next->pre = q;
    p->next = q;
    this->length++;
    return 1;
}

bool Dulist::Delete(int i, ElemType &e) {
    if (i <= 0 || i > this->length) {
        return 0;
    }
    Dulist *p = this;
    for (int j = 1; j <= i; j++) {
        p = (*p).next;
    }
    e = (*p).data;
    p->pre->next = p->next;
    p->next->pre = p->pre;
    delete (p);
    this->length--;
    return 1;
}

bool Dulist::getElem(int i, ElemType &e) {
    if (i <= 0 || i > this->length || this->length == 0) {
        return 0;
    }
    Dulist *p = this;
    for (int j = 1; j <= i; j++) {
        p = (*p).next;
    }
    e = (*p).data;
    return 1;
}

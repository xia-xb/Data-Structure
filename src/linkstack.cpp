#include "linkstack.h"

#include <iostream>

LinkStack::LinkStack() {
    this->top = NULL;
    this->count = 0;
}

LinkStack::~LinkStack() {}

bool LinkStack::push(SElemType &e) {
    StackNode *p = new (StackNode);
    (*p).data = e;
    (*p).next = this->top;
    this->top = p;
    this->count++;
    return 1;
}

bool LinkStack::pop(SElemType &e) {
    StackNode *p = this->top;
    e = (*p).data;
    this->top = this->top->next;
    free(p);
    this->count--;
    return 1;
}

bool LinkStack::IsEmpty() { return (this->count == 0); }

void LinkStack::clear() {
    SElemType e;
    while (!this->IsEmpty()) {
        if (this->pop(e)) {
        }
    }
}

SElemType LinkStack::GetTop() {
    if (this->IsEmpty()) {
        return 0;
    }
    SElemType e = this->top->data;
    return e;
}
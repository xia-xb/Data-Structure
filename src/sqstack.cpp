#include "sqstack.h"

#include <iostream>

using namespace std;

SqStack::SqStack() {
    this->top = -1;
    this->length = 0;
}

SqStack::~SqStack() {}

bool SqStack::push(SElemType &e) {
    if (this->top >= MAXSIZE - 1) {
        return 0;
    }
    this->top++;
    this->data[this->top] = e;
    this->length++;
    return 1;
}

bool SqStack::pop(SElemType &e) {
    if (this->top == -1) {
        return 0;
    }
    e = this->data[this->top];
    this->top--;
    this->length--;
    return 1;
}

bool SqStack::IsEmpty() { return this->top == -1; }

/* void SqStack::destory() {
    if (!this->IsEmpty()) {
    }
} */

void SqStack::clear() {
    SElemType e;
    while (!this->IsEmpty()) {
        if (this->pop(e)) {
        }
    }
}

SElemType SqStack::GetTop() {
    if (this->IsEmpty()) {
        return 0;
    }
    return this->data[this->top];
}
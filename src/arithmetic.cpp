#include "arithmetic.h"

#include <iostream>

/* void InitNode(char c, node &e) {
    e.data=c;
    e.next=NULL;
    switch (c) {
    case '+':
        e.level=1;
        break;
    case '-':
        e.level=1;
        break;
    case '*':
        e.level=2;
        break;
    case '/':
        e.level=2;
        break;
    case '(':
        e.level=1;
        break;
    case ')':
        e.level=0;
        break;
    default:
        break;
    }
}
 */
void InitNode(char c, node *e) {
    e->data = c;
    e->next = NULL;
    if (c - '0' >= 0 && c - '9' <= 0) {
        e->level = 0;
    } else {
        switch (c) {
        case '+':
            e->level = 1;
            break;
        case '-':
            e->level = 1;
            break;
        case '*':
            e->level = 2;
            break;
        case '/':
            e->level = 2;
            break;
        case '(':
            e->level = 1;
            break;
        case ')':
            e->level = 1;
            break;
        default:
            break;
        }
    }
}

LinkStack::LinkStack() {
    this->top = NULL;
    this->count = 0;
}

LinkStack::~LinkStack() {}

/* void LinkStack::push(char &c){
    node *e=new(node);
    (*e).data=c;
    (*e).next=NULL;
    switch (c) {
    case '+':
        (*e).level=1;
        break;
    case '-':
        (*e).level=1;
        break;
    case '*':
        (*e).level=2;
        break;
    case '/':
        (*e).level=2;
        break;
    case '(':
        (*e).level=1;
        break;
    case ')':
        (*e).level=0;
        break;
    default:
        break;
    }
    // InitNode(c,e);
    if(!this->IsEmpty()){
        (*e).next=top->next;
        // e.next=top->next;
        top=e;
        count++;
    }else{
        (*e).next=NULL;
        // e.next=NULL;
        top=e;
        count++;
    }
} */

void LinkStack::push(char &c) {
    node *e = new (node);
    InitNode(c, e);
    // e->data='a';
    // e->data=c;
    // e->level=1;
    if (!(this->IsEmpty())) {
        e->next = this->top;
        this->top = e;
        this->count++;
    } else {
        e->next = NULL;
        this->top = e;
        this->count++;
    }
}

/* void LinkStack::push(char &c){
    node e;
    InitNode(c,e);
    if(!this->IsEmpty()){
        // (*e).next=this->top->next;
        e.next=this->top;
        this->top=&e;
        this->count++;
    }else{
        // (*e).next=NULL;
        e.next=NULL;
        this->top=&e;
        this->count++;
    }
} */

void LinkStack::pop() {
    node *q = this->top;
    this->top = (*q).next;
    free(q);
    this->count--;
}

bool LinkStack::IsEmpty() { return (this->count == 0); }

node LinkStack::GetTop() {
    node e;
    e.data = this->top->data;
    e.level = this->top->level;
    e.next = this->top->next;
    return e;
}

void translate(LinkStack stack) {}
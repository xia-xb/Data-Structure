#include "queue2.h"

#include <iostream>

LinkQueue::LinkQueue() {
    node *que = new (node);
    this->front = que;
    this->rear = que;
}

LinkQueue::~LinkQueue() {}

int LinkQueue::length() {
    if (this->front == this->rear) {
        return 0;
    } else {
        int i = 0;
        node *p = this->front;
        while (p != this->rear) {
            i++;
            p = p->next;
        }
        return i;
    }
}

bool LinkQueue::QueueInsert(QElemType e){
    node *p=new(node);
    (*p).data=e;
    (*p).next=NULL;
    this->rear->next=p;
    this->rear=p;
    return 1;
}

bool LinkQueue::QueueDelete(QElemType &e){
    if(this->front==this->rear){
        return 0;
    }
    node *p=this->front->next;
    e=(*p).data;
    this->front->next=(*p).next;
    if(this->rear==p){
        this->rear=this->front;
    }
    free(p);
    return 1;
}

bool LinkQueue::IsEmpty(){
    return (this->front==this->rear);
}

QElemType LinkQueue::GetHead(){
    QElemType e=0;
    if(!(this->front==this->rear)){
        e=(*this->front->next).data;
    }
    return e;
}

bool LinkQueue::ClearQueue(){
    while(!this->IsEmpty()){
        QElemType e;
        this->QueueDelete(e);
    }
    return 1;
}

bool LinkQueue::DestoryQueue(){
    if(this->ClearQueue()){}
    node *p=this->front;
    free(p);
    return 1;
}
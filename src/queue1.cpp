#include "queue1.h"

#include <iostream>

SqQueue::SqQueue() {
    this->front = 0;
    this->rear = 0;
}

SqQueue::~SqQueue() {}

int SqQueue::length() { return (this->rear - this->front + MAXSIZE) % MAXSIZE; }

bool SqQueue::QueueInsert(QElemType e) {
    if ((this->rear + 1) % MAXSIZE == this->front) {
        return 0;
    }
    this->data[this->rear] = e;
    this->rear = (this->rear + 1) % MAXSIZE;
    return 1;
}

bool SqQueue::QueueDelete(QElemType &e) {
    if (this->front == this->rear) {
        return 0;
    }
    e = this->data[this->front];
    this->front = (this->front + 1) % MAXSIZE;
    return 1;
}

bool SqQueue::IsEmpty() { return (this->front == this->rear); }

QElemType SqQueue::GetHead() {
    if (this->IsEmpty()) {
        return 0;
    }
    return this->data[this->front];
}

bool SqQueue::ClearQueue() {
    if (!this->IsEmpty()) {
        this->front = 0;
        this->rear = 0;
    }
    return 1;
}

bool SqQueue::DestoryQueue() {
    // free(this->data);
    while(!this->IsEmpty()){
        free(&this->data[this->front]);
        QElemType e;
        if(this->QueueDelete(e)){};
    }
    return 1;
}
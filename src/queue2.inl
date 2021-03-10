#include "queue2.h"

#include <iostream>

template <class QElemType>
LinkQueue<QElemType>::LinkQueue() {
    node<QElemType> *que = new (node<QElemType>);
    this->front = que;
    this->rear = que;
}

template <class QElemType>
LinkQueue<QElemType>::~LinkQueue() {}

template <class QElemType>
int LinkQueue<QElemType>::length() {
    if (this->front == this->rear) {
        return 0;
    } else {
        int i = 0;
        node<QElemType> *p = this->front;
        while (p != this->rear) {
            i++;
            p = p->next;
        }
        return i;
    }
}

template <class QElemType>
bool LinkQueue<QElemType>::QueueInsert(QElemType e) {
    node<QElemType> *p = new (node<QElemType>);
    (*p).data = e;
    (*p).next = NULL;
    this->rear->next = p;
    this->rear = p;
    return 1;
}

template <class QElemType>
bool LinkQueue<QElemType>::QueueDelete(QElemType &e) {
    if (this->front == this->rear) {
        return 0;
    }
    node<QElemType> *p = this->front->next;
    e = (*p).data;
    this->front->next = (*p).next;
    if (this->rear == p) {
        this->rear = this->front;
    }
    delete (p);
    return 1;
}

template <class QElemType>
bool LinkQueue<QElemType>::IsEmpty() {
    return (this->front == this->rear);
}

template <class QElemType>
QElemType LinkQueue<QElemType>::GetHead() {
    QElemType e = 0;
    if (!(this->front == this->rear)) {
        e = (*this->front->next).data;
    }
    return e;
}

template <class QElemType>
bool LinkQueue<QElemType>::ClearQueue() {
    while (!this->IsEmpty()) {
        QElemType e;
        this->QueueDelete(e);
    }
    return 1;
}

template <class QElemType>
bool LinkQueue<QElemType>::DestoryQueue() {
    if (this->ClearQueue()) {
    }
    node<QElemType> *p = this->front;
    delete (p);
    return 1;
}

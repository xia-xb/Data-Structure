#ifndef QUEUE2_H
#define QUEUE2_H
// typedef int QElemType;

template <typename QElemType = int>
struct node {
    QElemType data;
    node<QElemType> *next;
};

template <typename QElemType = int>
class LinkQueue {
private:
    node<QElemType> *front;
    node<QElemType> *rear;

public:
    LinkQueue();
    ~LinkQueue();
    int length();
    bool QueueInsert(QElemType e);
    bool QueueDelete(QElemType &e);
    bool IsEmpty();
    QElemType GetHead();
    bool ClearQueue();
    bool DestoryQueue();
};

#include "E:\CPP\VSCode\Data-Structure\src\queue2.inl"
#endif
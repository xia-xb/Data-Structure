#ifndef QUEUE2_H
#define QUEUE2_H

typedef int QElemType;

struct node {
    QElemType data;
    node *next;
};

class LinkQueue {
private:
    node *front;
    node *rear;

public:
    LinkQueue(/* args */);
    ~LinkQueue();
    int length();
    bool QueueInsert(QElemType e);
    bool QueueDelete(QElemType &e);
    bool IsEmpty();
    QElemType GetHead();
    bool ClearQueue();
    bool DestoryQueue();
};

/* LinkQueue::LinkQueue()
{
}

LinkQueue::~LinkQueue()
{
} */

#endif
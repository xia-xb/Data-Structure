#ifndef QUEUE1_H
#define QUEUE1_H

#define MAXSIZE 5
typedef int QElemType;

class SqQueue {
private:
    QElemType data[MAXSIZE];
    int front;
    int rear;

public:
    SqQueue(/* args */);
    ~SqQueue();
    int length();
    bool QueueInsert(QElemType e);
    bool QueueDelete(QElemType &e);
    bool IsEmpty();
    QElemType GetHead();
    bool ClearQueue();
    bool DestoryQueue();
};

/* SqQueue::SqQueue()
{
}

SqQueue::~SqQueue()
{
} */

#endif
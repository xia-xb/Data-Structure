#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef int SElemType;

struct StackNode {
    SElemType data;
    StackNode *next;
};

/* class StackNode
{
private:
    SElemType data;
    StackNode *next;
}; */

class LinkStack {
private:
    StackNode *top;
    int count;

public:
    LinkStack(/* args */);
    ~LinkStack();
    bool push(SElemType &);
    bool pop(SElemType &);
    bool IsEmpty();
    // void destory();
    void clear();
    SElemType GetTop();
};

#endif
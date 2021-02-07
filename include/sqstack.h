#ifndef SQSTACK_H
#define SQSTACK_H

#define MAXSIZE 20
typedef int SElemType;

class SqStack {
private:
    SElemType data[MAXSIZE];
    int top;

public:
    SqStack(/* args */);
    ~SqStack();
    int length;
    bool push(SElemType &);
    bool pop(SElemType &);
    bool IsEmpty();
    // void destory();
    void clear();
    SElemType GetTop();
};

#endif
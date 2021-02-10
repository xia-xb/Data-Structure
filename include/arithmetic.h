#ifndef ARITHMETIC_H
#define ARITHMETIC_H

struct node {
    char data;
    int level;
    node *next;
};

void InitNode(char, node *);

class LinkStack {
private:
    node *top;
    int count;

public:
    LinkStack(/* args */);
    ~LinkStack();
    void push(char &);
    void pop();
    bool IsEmpty();
    // void destory();
    // void clear();
    node GetTop();
};

void translate(LinkStack);

#endif
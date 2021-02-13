#ifndef ARITHMETIC_H
#define ARITHMETIC_H
#include <string>
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

/* class postExpression {
private:
    string data;
    postExpression *next;

public:
    postExpression();
    ~postExpression();
    void push(string);
    void pop();
    float calculation();
    string getTop();
}; */

/* postExpression::postExpression()
{
}

postExpression::~postExpression()
{
} */

void translate(LinkStack);

int transform(std::string, std::size_t &, char, node *);

std::string conversion(std::string);

float calculation(std::string);

#endif
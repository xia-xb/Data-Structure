#include "arithmetic.h"

#include <math.h>

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void InitNode(char c, node *e) {
    e->data = c;
    e->next = NULL;
    if (c - '0' >= 0 && c - '9' <= 0) {
        e->level = 0;
    } else {
        switch (c) {
        case '+':
            e->level = 1;
            break;
        case '-':
            e->level = 1;
            break;
        case '*':
            e->level = 2;
            break;
        case '/':
            e->level = 2;
            break;
        case '(':
            e->level = 1;
            break;
        case ')':
            e->level = 1;
            break;
        default:
            break;
        }
    }
}

LinkStack::LinkStack() {
    this->top = NULL;
    this->count = 0;
}

LinkStack::~LinkStack() {}

void LinkStack::push(char &c) {
    node *e = new (node);
    InitNode(c, e);
    if (!(this->IsEmpty())) {
        e->next = this->top;
        this->top = e;
        this->count++;
    } else {
        e->next = NULL;
        this->top = e;
        this->count++;
    }
}

void LinkStack::pop() {
    node *q = this->top;
    this->top = (*q).next;
    free(q);
    this->count--;
}

bool LinkStack::IsEmpty() { return (this->count == 0); }

node LinkStack::GetTop() {
    node e;
    e.data = this->top->data;
    e.level = this->top->level;
    e.next = this->top->next;
    return e;
}

/* postExpression::postExpression() {
    this->data = " ";
    this->next = NULL;
}

postExpression::~postExpression() {}

void postExpression::push(string s) {
    postExpression *p = new (postExpression);
    p->data = s;
    p->next = this;
    postExpression *q = this;
    while (q->next != NULL) {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
}

void postExpression::pop() {
    if (!(this->next == NULL)) {
        postExpression *p = this;
        while (p->next->next != NULL) {
            p = p->next;
        }
        postExpression *q=p->next;
        p->next=NULL;
        free(q);
    }
}

string postExpression::getTop(){
   return (*this->next).data;
}

float postExpression::calculation(){
    return 0;
} */

void translate(LinkStack stack) {}

/* 对于字符串中给定起始位置开始的“数字”,转换为相应的数字 */
int transform(std::string s, size_t &i, char c, node *str) {
    int digits = 0, num = 0;
    std::stack<int> data;

    while (str->level == 0) {
        data.push(c - '0');
        i++;
        if (i >= s.length()) {
            break;
        }
        c = s.at(i);
        InitNode(c, str);
    }
    while (!data.empty()) {
        num += (data.top() * pow(10, digits));
        digits++;
        data.pop();
    }
    return num;
}

/* 输入中缀表达式字符串，转换为后缀表达式字符串 */
std::string conversion(std::string s) {
    string result;
    // postExpression result;
    char c;
    LinkStack stack;
    size_t i = 0;
    while (i < s.length()) {
        c = s.at(i);
        node *str = new (node);
        InitNode(c, str);
        /* 元素为数字，检测实际数据大小 */
        if (str->level == 0) {
            int num = transform(s, i, c, str);
            result.append(to_string(num));
            // result.push(to_string(num));
        } else {
            if (!stack.IsEmpty()) {
                node t = stack.GetTop();
                /* 字符为右括号')'，出栈直到左括号'(' */
                if (c == ')') {
                    while (t.data != '(') {
                        result = result + t.data;
                        // result.push(string(1,t.data));
                        stack.pop();
                        if (!(stack.IsEmpty())) {
                            t = stack.GetTop();
                        }
                    }
                    stack.pop();
                } else {
                    /* 字符为加减乘除，则判断当前字符等级是否小于栈顶字符等级 */
                    /* 小于栈顶字符等级则依次出栈，直到栈顶等级与当前字符等级相同
                     */
                    while (str->level < t.level) {
                        // result.push(string(1,t.data));
                        result = result + t.data;
                        stack.pop();
                        if (!(stack.IsEmpty())) {
                            t = stack.GetTop();
                        }
                        // result.push(string(1,t.data));
                        result = result + t.data;
                        stack.pop();
                    }
                }
            }
            /* 除了右括号')'，将字符压栈 */
            /* 当栈为空时，直接压栈，不用通过上述检测 */
            if (str->level && c != ')') {
                stack.push(c);
            }
            i++;
        }
    }
    /* 字符遍历完成，将栈中剩余字符出栈 */
    node t = stack.GetTop();
    while (!stack.IsEmpty()) {
        // result.push(string(1,t.data));
        result = result + t.data;
        stack.pop();
        if (stack.IsEmpty()) {
            break;
        }
        t = stack.GetTop();
    }
    return result;
}

float calculation(string s) {
    float num = 0, first = 0, second = 0;
    size_t i = 0;
    char c = s.at(i);
    // string c=s.getTop();
    node *str = new (node);
    InitNode(c, str);
    stack<float> Stack;
    while (i < s.length()) {
        if (str->level == 0) {
            int n = transform(s, i, c, str);
            float num = float(n);
            Stack.push(num);
        } else {
            switch (c) {
            case '+':
                first = Stack.top();
                Stack.pop();
                second = Stack.top();
                num = first + second;
                Stack.push(num);
                break;
            case '-':
                first = Stack.top();
                Stack.pop();
                second = Stack.top();
                num = first - second;
                Stack.push(num);
                break;
            case '*':
                first = Stack.top();
                Stack.pop();
                second = Stack.top();
                num = first * second;
                Stack.push(num);
                break;
            case '/':
                first = Stack.top();
                Stack.pop();
                second = Stack.top();
                num = first / second;
                Stack.push(num);
                break;
            default:
                break;
            }
        }
    }
    return Stack.top();
}

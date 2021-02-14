#include "arithmetic1.h"

#include <math.h>

#include <iostream>
#include <list>
#include <stack>
#include <string>

#include "arithmetic.h"

/* 将中缀表达式字符串，转换为后缀表达式，存在链表中 */
std::list<std::string> conv(std::string s) {
    std::list<std::string> result;
    // auto it=result.begin();
    // std::cout<<*it<<std::endl;
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
            // result.append(to_string(num));
            result.push_back(std::to_string(num));
        } else {
            if (!stack.IsEmpty()) {
                node t = stack.GetTop();
                /* 字符为右括号')'，出栈直到左括号'(' */
                if (c == ')') {
                    while (t.data != '(') {
                        // result = result + t.data;
                        result.push_back(std::string(1, t.data));
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
                        result.push_back(std::string(1, t.data));
                        // result = result + t.data;
                        stack.pop();
                        if (!(stack.IsEmpty())) {
                            t = stack.GetTop();
                        }
                        result.push_back(std::string(1, t.data));
                        // result = result + t.data;
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
        result.push_back(std::string(1, t.data));
        // result = result + t.data;
        stack.pop();
        if (stack.IsEmpty()) {
            break;
        }
        t = stack.GetTop();
    }
    return result;
}

/* 计算后缀表达式实际值大小 */
float calcu(std::list<std::string> result) {
    auto it = result.begin();
    float first = 0, second = 0;
    size_t i = 0;

    std::stack<float> Stack;
    /* 遍历后缀表达式 */
    while (i < result.size()) {
        std::string s = *it;
        it++;
        char c = s.at(0);
        node *str = new (node);
        InitNode(c, str);
        if (str->level == 0) {
            /* 字符为数字，则直接压栈 */
            size_t j = 0;
            int n = transform(s, j, c, str);
            Stack.push(n);
        } else {
            /* 字符为计算符号，出栈栈顶两个元素，完成计算*/
            first = Stack.top();
            Stack.pop();
            second = Stack.top();
            Stack.pop();
            switch (c) {
            case '+':
                Stack.push(first + second);
                break;
            case '-':
                Stack.push(second - first);
                break;
            case '*':
                Stack.push(second * first);
                break;
            case '/':
                Stack.push(second / first);
                break;
            default:
                break;
            }
        }
        i++;
    }
    return Stack.top();
}
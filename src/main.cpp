#include <math.h>

#include <iostream>
#include <stack>
#include <string>

#include "arithmetic.h"

using namespace std;

int main() {
    string s;
    // cin>>s;
    s = "9+(3-1)*3+1/2";
    string result = conversion(s);
    cout << result << endl;
    /* float a=calculation(result);
    cout<<a; */

    float first = 0, second = 0;
    size_t i = 0;

    stack<float> Stack;
    while (i < result.length()) {
        char c = result.at(i);
        node *str = new (node);
        InitNode(c, str);
        float num = 0;
        if (str->level == 0) {
            // int n = transform(result, i, c, str);

            num = c - '0';
            Stack.push(num);
            i++;

        } else {
            switch (c) {
            case '+':
                first = Stack.top();
                Stack.pop();
                second = Stack.top();
                Stack.pop();
                num = first + second;
                Stack.push(num);
                break;
            case '-':
                first = Stack.top();
                Stack.pop();
                second = Stack.top();
                Stack.pop();
                num = second - first;
                Stack.push(num);
                break;
            case '*':
                first = Stack.top();
                Stack.pop();
                second = Stack.top();
                Stack.pop();
                num = first * second;
                Stack.push(num);
                break;
            case '/':
                first = Stack.top();
                Stack.pop();
                second = Stack.top();
                Stack.pop();
                num = second / first;
                Stack.push(num);
                break;
            default:
                break;
            }
            i++;
        }
        /* c = s.at(i);
        // node *str = new (node);
        InitNode(c, str); */
    }
    float a = Stack.top();
    cout << a;
    return 0;
}
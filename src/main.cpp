#include <math.h>

#include <iostream>
#include <stack>
#include <string>

#include "arithmetic.h"

using namespace std;

int main() {
    string s;
    // cin>>s;
    s = "9+(3-1)*3+10/2";
    char c;
    LinkStack Stack;
    int i = 0;
    while (i < s.length()) {
        c = s.at(i);
        node *str = new (node);
        InitNode(c, str);
        if (str->level == 0) {
            int digits = 0;
            int num = 0;
            stack<int> n;
            while (str->level == 0) {
                n.push(c - '0');
                i++;
                if (i >= s.length()) {
                    break;
                }
                c = s.at(i);
                InitNode(c, str);
            }
            while (!n.empty()) {
                num += (n.top()) * pow(10, digits);
                digits++;
                n.pop();
            }
            cout << num << " ";
        } else {
            if (!Stack.IsEmpty()) {
                node t = Stack.GetTop();
                if (c == ')') {
                    while (t.data != '(') {
                        cout << t.data << " ";
                        Stack.pop();
                        if (!(Stack.IsEmpty())) {
                            t = Stack.GetTop();
                        }
                    }
                    Stack.pop();
                } else {
                    while (str->level < t.level) {
                        cout << t.data << " ";
                        Stack.pop();
                        if (!(Stack.IsEmpty())) {
                            t = Stack.GetTop();
                        }
                        cout << t.data << " ";
                        Stack.pop();
                    }
                }
            }
            if (str->level && c != ')') {
                Stack.push(c);
            }
            i++;
        }
        // cout<<"hello world"<<endl;
    }
    node t = Stack.GetTop();
    while (!Stack.IsEmpty()) {
        cout << t.data << " ";
        Stack.pop();
        if (Stack.IsEmpty()) {
            break;
        }
        t = Stack.GetTop();
    }
    /* node t = stack.GetTop();
    while(!stack.IsEmpty()){
        cout<<t.data;
        stack.pop();
        t=stack.GetTop();
    } */
    // /cout<<"hello world"<<endl;
    return 0;
}
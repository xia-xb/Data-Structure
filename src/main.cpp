#include <iostream>

#include "arithmetic.h"

using namespace std;

int main() {
    char c;
    bool flag = 1;
    // cin>>c;
    LinkStack stack;
    while (cin >> c || !stack.IsEmpty()) {
        if (c != '+' && c != '-' && c != '*' && c != '/' && c != '(' &&
            c != ')') {
            int num = c - '0';
            cout << num;
        } else {
            node *str = new (node);
            InitNode(c, str);
            if (!stack.IsEmpty()) {
                node t = stack.GetTop();
                if (c=='('||c==')') {
                    flag=!flag;
                }
                if (flag && c == ')') {
                    flag=!flag;
                    while (t.data != '(') {
                        cout << t.data;
                        stack.pop();
                        if (!(stack.IsEmpty())) {
                            t = stack.GetTop();
                        }
                    }
                    stack.pop();
                } else {
                    while (str->level < t.level) {
                        cout << t.data;
                        stack.pop();
                        if (!(stack.IsEmpty())) {
                            t = stack.GetTop();
                        }
                        cout<<t.data;
                        stack.pop();
                    }
                    if(c==NULL && !stack.IsEmpty()){
                        node t = stack.GetTop();
                        while(!stack.IsEmpty()){
                            cout<<t.data;
                            stack.pop();
                            t=stack.GetTop();
                        }
                    }
                }
            }
            if (str->level && c!=')') {
                stack.push(c);
            }
        }
        
        // cout<<"hello world"<<endl;
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
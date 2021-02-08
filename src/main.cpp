#include <iostream>

#include "linkstack.h"

using namespace std;

int main() {
    LinkStack stack;
    if(stack.IsEmpty()){
        cout<<"创建成功"<<endl;
    }
    //cout<<"栈的长度为："<<stack.length<<endl;

    cout<<endl<<"依次push10个数据元素"<<endl;
    for(int i=1;i<=10;i++){
        if(stack.push(i)&&i==10){
            cout<<"push成功"<<endl;
        }
    }
    //cout<<"栈的长度为："<<stack.length<<endl;
    cout<<"栈顶元素："<<stack.GetTop()<<endl;

    SElemType e;
    if(stack.pop(e)){
        cout<<"pop成功"<<endl;
        //cout<<"栈的长度为："<<stack.length<<endl;
        cout<<"栈顶元素："<<stack.GetTop()<<endl;
    }

    stack.clear();
     if(stack.IsEmpty()){
        cout<<"清空成功"<<endl;
       // cout<<"栈的长度为："<<stack.length<<endl;
        cout<<"栈顶元素："<<stack.GetTop()<<endl;
    }

    return 0;
}
#include <iostream>

#include "dulist.h"

using namespace std;

int main() {
    Dulist list;
    cout<<"链表的长度："<<list.length<<endl;

    cout<<endl<<"依次插入10个元素"<<endl;
    for(int i=1;i<=10;i++){
        if(list.Insert(i,i)&&i==10){
            cout<<"插入元素成功"<<endl;
        }
    }
    cout<<"打印元素"<<endl;
    cout<<"链表的长度："<<list.length<<endl;
    for(int i=1;i<=list.length;i++){
        ElemType e;
        if(list.getElem(i,e)){
            cout<<"第"<<i<<"个元素为："<<e;
        }
        cout<<endl;
    }

    cout<<"在链表第5个元素位置插入20"<<endl;
    ElemType a=20;
    if(list.Insert(5,a)){
        cout<<"插入元素成功"<<endl;
    }else{
        cout<<"插入元素失败"<<endl;
    }
    cout<<"打印元素"<<endl;
    cout<<"链表的长度："<<list.length<<endl;
    for(int i=1;i<=list.length;i++){
        ElemType e;
        if(list.getElem(i,e)){
            cout<<"第"<<i<<"个元素为："<<e;
        }
        cout<<endl;
    }

    cout<<"在链表第15个元素位置插入40"<<endl;
    a=40;
    if(list.Insert(15,a)){
        cout<<"插入元素成功"<<endl;
    }else{
        cout<<"插入元素失败"<<endl;
    }
    cout<<"打印元素"<<endl;
    cout<<"链表的长度："<<list.length<<endl;
    for(int i=1;i<=list.length;i++){
        ElemType e;
        if(list.getElem(i,e)){
            cout<<"第"<<i<<"个元素为："<<e;
        }
        cout<<endl;
    }

    cout<<"删除链表中第3个元素"<<endl;
    if(list.Delete(3,a)){
        cout<<"删除元素成功"<<endl;
    }else{
        cout<<"删除元素失败"<<endl;
    }
    cout<<"打印元素"<<endl;
    cout<<"链表的长度："<<list.length<<endl;
    for(int i=1;i<=list.length;i++){
        ElemType e;
        if(list.getElem(i,e)){
            cout<<"第"<<i<<"个元素为："<<e;
        }
        cout<<endl;
    }

    cout<<"删除链表中第13个元素"<<endl;
    if(list.Delete(13,a)){
        cout<<"删除元素成功"<<endl;
    }else{
        cout<<"删除元素失败"<<endl;
    }
    cout<<"打印元素"<<endl;
    cout<<"链表的长度："<<list.length<<endl;
    for(int i=1;i<=list.length;i++){
        ElemType e;
        if(list.getElem(i,e)){
            cout<<"第"<<i<<"个元素为："<<e;
        }
        cout<<endl;
    }
    return 0;
}
#include <iostream>
#include "mylist2.h"

using namespace std;

int main(){
    HeadNode L;
    int length=10;
    CreatListHead(L,length);
    for(int i=1;i<=L.length;i++){
        ElemType *e=new(ElemType);
        if(GetElem(L,i,e)){
            cout<<"第"<<i<<"个元素：";
            cout<<*e<<endl;
        } 
    } 
    for(int i=1;i<=L.length;i++){
        ElemType *e=new(ElemType);
        if(GetElem(L,i,e)){
            cout<<"第"<<i<<"个元素：";
            cout<<*e<<endl;
        } 
    } 
    cout<<"在第5个元素位置插入20"<<endl;
    int i=5;
    ElemType a=20;
    if(ListInsert(L,i,a)){
        for(int i=1;i<=L.length;i++){
            ElemType *e=new(ElemType);
            if(GetElem(L,i,e)){
                cout<<"第"<<i<<"个元素：";
                cout<<*e<<endl;
            } 
        }    
    }
    cout<<"删除第7位置元素"<<endl;
    ElemType e;
    ListDelete(L,7,e);
    for(int i=1;i<=L.length;i++){
        ElemType *e=new(ElemType);
        if(GetElem(L,i,e)){
            cout<<"第"<<i<<"个元素：";
            cout<<*e<<endl;
        } 
    }
    return 0;
}
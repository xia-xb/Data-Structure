#include <iostream>
#include "swap.h"

using namespace std;

int main(){
    int val1=10,val2=20;
    cout<<"before swap:"<<endl;
    cout<<"val1:"<<val1<<endl;
    cout<<"val2:"<<val2<<endl;
    swap(val1,val2);
    cout<<"after swap:"<<endl;
    cout<<"val1:"<<val1<<endl;
    cout<<"val2:"<<val2<<endl;
    return 0;
}
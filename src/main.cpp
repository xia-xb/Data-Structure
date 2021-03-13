
#include <iostream>

#include "sort.h"

using namespace std;

int main() {
    int length=10;
    int a[10];
    for(int i=0;i<10;i++){
        a[i]=10-i;
    }
    cout<<"排序前\n";
    for(int i=0;i<10;i++){
        cout<<a[i]<<endl;
    }
    Bubble_sort(a,length);
    cout<<"排序后\n";
    for(int i=0;i<10;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
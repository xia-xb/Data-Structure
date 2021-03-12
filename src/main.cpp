
#include <iostream>

#include "heap.h"

using namespace std;

int main() {
    MaxHeap<int> heap;
    heap.create(100,100);
    for(int i=0;i<10;i++){
        heap.Insert(i);
    }
    for(int i=1;i<5;i++){
        heap.Delete();
    }
    return 0;
}
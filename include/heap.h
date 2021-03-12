#ifndef HEAP_H
#define HEAP_H

template <class ElementType>
class MaxHeap {
private:
    ElementType* elements;
    int Size, Capacity;

public:
    MaxHeap();
    ~MaxHeap();
    void create(int, ElementType);
    void Insert(ElementType);
    void Delete();
};

#include "E:\CPP\VSCode\Data-Structure\src\heap.inl"
#endif
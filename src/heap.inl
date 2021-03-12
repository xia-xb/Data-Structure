#include <iostream>

#include "heap.h"

template <class ElementType>
MaxHeap<ElementType>::MaxHeap() {}

template <class ElementType>
MaxHeap<ElementType>::~MaxHeap() {}

template <class ElementType>
void MaxHeap<ElementType>::create(int i, ElementType MaxData) {
    this->elements = (ElementType*)malloc((i+1)*sizeof(ElementType));
    this->elements[0] = MaxData;
    this->Size = 0;
    this->Capacity = i;
}

template <class ElementType>
void MaxHeap<ElementType>::Insert(ElementType item) {
    if (this->Size == this->Capacity) {
        std::cout << "堆已满";
        return;
    }
    int i = ++this->Size;
    while (this->elements[i / 2] < item) {
        this->elements[i] = this->elements[i / 2];
        i = i / 2;
    }
    this->elements[i] = item;
}

template <class ElementType>
void MaxHeap<ElementType>::Delete() {
    if (this->Size == 0) {
        std::cout << "堆已空" << std::endl;
        return;
    }
    std::cout << this->elements[1] << std::endl;
    ElementType tmp = this->elements[this->Size];
    this->Size--;
    int parent, child;
    for (parent = 1; parent * 2 <= this->Size; parent = child) {
        child = parent * 2;
        if (!(child == this->Size) &&
            this->elements[child] < this->elements[child + 1]) {
            child++;
        }
        if (tmp >= this->elements[child]) {
            break;
        } else {
            this->elements[parent] = this->elements[child];
        }
    }
    this->elements[parent] = tmp;
}
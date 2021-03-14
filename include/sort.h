#ifndef SORT_H
#define SORT_H

template <typename ElementType>
void swap(ElementType &, ElementType &);

template <typename ElementType>
void Bubble_sort(ElementType a[], int n);

template <typename ElementType>
void Insertion_sort(ElementType a[], int n);

#include "../src/sort.inl"
#endif
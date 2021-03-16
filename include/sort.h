#ifndef SORT_H
#define SORT_H

#define cutoff 5

template <typename ElementType>
void Swap(ElementType &, ElementType &);

template <typename ElementType>
void Bubble_sort(ElementType a[], int n);

template <typename ElementType>
void Insertion_sort(ElementType a[], int n);

template <typename ElementType>
void Shell_sort(ElementType a[], int n);

template <typename ElementType>
int ScanForMin(ElementType a[], int i, int n);

template <typename ElementType>
void Selection_sort(ElementType a[], int n);

template <typename ElementType>
void Heap_sort(ElementType a[], int n);

template <typename ElementType>
void Merge(ElementType a[], ElementType tmpa[], int l, int r, int rightend);

template <typename ElementType>
void MSort(ElementType a[], ElementType tmpa[], int l, int rightend);

template <typename ElementType>
void Merge_sort(ElementType a[], int n);

template <typename ElementType>
ElementType median3(ElementType a[], int left, int right);

template <typename ElementType>
void Quicksort(ElementType a[], int left, int right);

template <typename ElementType>
void Quick_sort(ElementType a[], int n);

#include "../src/sort.inl"
#endif
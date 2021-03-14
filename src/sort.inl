#include <iostream>

#include "sort.h"

template <typename ElementType>
void swap(ElementType &a, ElementType &b) {
    ElementType tmp = a;
    a = b;
    b = tmp;
}

template <typename ElementType>

void Bubble_sort(ElementType a[], int n) {
    for (int p = n - 1; p > 0; p--) {
        int flag = 0;
        for (int i = 0; i < p; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

template <typename ElementType>
void Insertion_sort(ElementType a[], int n) {
    for (int p = 1; p <= n - 1; p++) {
        ElementType tmp = a[p];
        int i = p;
        for (i = p; i > 0 && a[i - 1] > tmp; i--) {
            a[i] = a[i - 1];
        }
        a[i] = tmp;
    }
}
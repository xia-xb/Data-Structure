#include <iostream>

#include "sort.h"

template <typename ElementType>
void Swap(ElementType &a, ElementType &b) {
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
                Swap(a[i], a[i + 1]);
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

template <typename ElementType>
void Shell_sort(ElementType a[], int n) {
    for (int d = n / 2; d > 0; d = d / 2) {
        /* 此处即为插入排序 */
        for (int p = d; p < n; p++) {
            ElementType tmp = a[p];
            int i = p;
            for (i = p; i >= d && a[i - d] > tmp; i -= d) {
                a[i] = a[i - d];
            }
            a[i] = tmp;
        }
    }
}

template <typename ElementType>
int ScanForMin(ElementType a[], int i, int n) {
    int postion = i;
    for (int j = i; j <= n; j++) {
        postion = a[postion] < a[j] ? postion : j;
    }
    return postion;
}

template <typename ElementType>
void Selection_sort(ElementType a[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int minpostion = ScanForMin(a, i, n - 1);
        Swap(a[i], a[minpostion]);
    }
}

template <typename ElementType>
void Heap_sort(ElementType a[], int n) {}

template <typename ElementType>
void Merge(ElementType a[], ElementType tmpa[], int l, int r, int rightend) {
    int leftend = r - 1;
    int tmp = l;
    int numelements = rightend - l + 1;
    while (l <= leftend && r <= rightend) {
        if (a[l] < a[r]) {
            tmpa[tmp++] = a[l++];
        } else {
            tmpa[tmp++] = a[r++];
        }
    }
    while (l <= leftend) {
        tmpa[tmp++] = a[l++];
    }
    while (r <= rightend) {
        tmpa[tmp++] = a[r++];
    }
    for (int i = 0; i < numelements; i++, rightend--) {
        a[rightend] = tmpa[rightend];
    }
}

template <typename ElementType>
void MSort(ElementType a[], ElementType tmpa[], int l, int rightend) {
    int center;
    if (l < rightend) {
        center = (l + rightend) / 2;
        MSort(a, tmpa, l, center);
        MSort(a, tmpa, center + 1, rightend);
        Merge(a, tmpa, l, center + 1, rightend);
    }
}

template <typename ElementType>
void Merge_sort(ElementType a[], int n) {
    ElementType *tmpa;
    tmpa = new ElementType[n];
    if (tmpa) {
        MSort(a, tmpa, 0, n - 1);
        delete tmpa;
    }
}

template <typename ElementType>
ElementType median3(ElementType a[], int left, int right) {
    int center = (left + right) / 2;
    if (a[center] < a[left]) {
        Swap(a[center], a[left]);
    }
    if (a[left] > a[right]) {
        Swap(a[left], a[right]);
    }
    if (a[center] > a[right]) {
        Swap(a[center], a[right]);
    }
    Swap(a[center], a[right - 1]);
    return a[right - 1];
}

template <typename ElementType>
void Quicksort(ElementType a[], int left, int right) {
    if (cutoff < right - left + 1) {
        ElementType pivot = median3(a, left, right);
        int i = left, j = right - 1;
        for (;;) {
            while (a[++i] < pivot) {
            }
            while (a[--j] > pivot) {
            }
            if (i < j) {
                Swap(a[i], a[j]);
            } else {
                break;
            }
        }
        Swap(a[i], a[right - 1]);
        Quicksort(a, left, i - 1);
        Quicksort(a, i + 1, right);
    } else {
        Insertion_sort(a, right - left + 1);
    }
}

template <typename ElementType>
void Quick_sort(ElementType a[], int n) {
    Quicksort(a, 0, n - 1);
}
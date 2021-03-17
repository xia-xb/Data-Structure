#include <iostream>

#include "search.h"

template <typename ElementType>
int Sequential_search(ElementType a[], int length, ElementType key) {
    a[0] = key;
    int i = length;
    while (a[i] != key) {
        i--;
    }
    return i;
}

template <typename ElementType>
int Binary_search(ElementType a[], int length, ElementType key) {
    int low = 1, high = length;
    int mid;
    while (low <= high) {
        mid = (high + low) / 2;
        if (a[mid] > key) {
            high = mid - 1;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}

template <typename ElementType>
int Interpolation_search(ElementType a[], int length, ElementType key) {
    int low = 1, high = length;
    int mid;
    while (low <= high) {
        mid = low + (key - a[low]) / (a[high] - a[low]) * (high - low);
        if (a[mid] > key) {
            high = mid - 1;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}

template <class ElementType>
BinarySortTree<ElementType>::BinarySortTree() {}

template <class ElementType>
BinarySortTree<ElementType>::~BinarySortTree() {}

template <class ElementType>
void BinarySortTree<ElementType>::Create(ElementType a[], int length) {
    if (length == 0) {
        return;
    }
    Node<ElementType>* e = new Node<ElementType>;
    e->data = a[0];
    e->leftchild = e->rightchild = NULL;
    this->head = e;
    for (int i = 1; i < length; i++) {
        Node<ElementType>* e = new Node<ElementType>;
        e->data = a[i];
        e->leftchild = NULL;
        e->rightchild = NULL;
        Node<ElementType>* p = this->head;
        while (p) {
            if (a[i] < p->data) {
                if (!p->leftchild) {
                    p->leftchild = e;
                    break;
                } else {
                    p = p->leftchild;
                }
            }
            if (a[i] > p->data) {
                if (!p->rightchild) {
                    (p->rightchild) = e;
                    break;
                } else {
                    p = p->rightchild;
                }
            }
        }
    }
}

template <class ElementType>
bool BinarySortTree<ElementType>::SearchBst(Node<ElementType>* t,
                                            ElementType key,
                                            Node<ElementType>* parent,
                                            Node<ElementType>* p) {
    if (!t) {
        *p = *parent;
        return false;
    } else if (key == t->data) {
        *p = *t;
        return true;
    } else if (key < t->data) {
        return (this->SearchBst(t->leftchild, key, t, p));
    } else {
        return (this->SearchBst(t->rightchild, key, t, p));
    }
}

template <class ElementType>
bool BinarySortTree<ElementType>::SearchBST(ElementType key,
                                            Node<ElementType>* p) {
    return (this->SearchBst(this->head, key, NULL, p));
}

template <class ElementType>
bool BinarySortTree<ElementType>::InsertBST(ElementType key) {
    Node<ElementType>* p = new Node<ElementType>;
    if (!this->SearchBST(key, p)) {
        Node<ElementType>* e = new Node<ElementType>;
        e->data = key;
        e->leftchild = e->rightchild = NULL;
        if (!p) {
            this->head = e;
        } else if (key < p->data) {
            p->leftchild = e;
        } else {
            p->rightchild = e;
        }
        return true;
    } else {
        return false;
    }
}

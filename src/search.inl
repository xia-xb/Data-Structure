#include <math.h>

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
BinarySearchTree<ElementType>::BinarySearchTree() {}

template <class ElementType>
BinarySearchTree<ElementType>::~BinarySearchTree() {}

template <class ElementType>
void BinarySearchTree<ElementType>::Create(ElementType a[], int length) {
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
bool BinarySearchTree<ElementType>::SearchBst(Node<ElementType>* t,
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
bool BinarySearchTree<ElementType>::SearchBST(ElementType key,
                                              Node<ElementType>* p) {
    return (this->SearchBst(this->head, key, NULL, p));
}

template <class ElementType>
bool BinarySearchTree<ElementType>::InsertBST(ElementType key) {
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

template <class ElementType>
Node<ElementType>* BinarySearchTree<ElementType>::find(ElementType key,
                                                       Node<ElementType>* bst) {
    if (!bst) {
        return NULL;
    }
    if (key < bst->data) {
        return this->find(key, bst->leftchild);
    } else if (key > bst->data) {
        return this->find(key, bst->rightchild);
    } else {
        return bst;
    }
}

template <class ElementType>
Node<ElementType>* BinarySearchTree<ElementType>::Find(ElementType key) {
    return this->find(key, this->head);
}

template <class ElementType>
Node<ElementType>* BinarySearchTree<ElementType>::FindMin(
    Node<ElementType>* bst) {
    if (bst) {
        while (bst->leftchild) {
            bst = bst->leftchild;
        }
    }
    return bst;
}

template <class ElementType>
Node<ElementType>* BinarySearchTree<ElementType>::FindMin() {
    return this->FindMin(this->head);
}

template <class ElementType>
Node<ElementType>* BinarySearchTree<ElementType>::FindMax(
    Node<ElementType>* bst) {
    if (bst) {
        while (bst->rightchild) {
            bst = bst->rightchild;
        }
    }
    return bst;
}

template <class ElementType>
Node<ElementType>* BinarySearchTree<ElementType>::FindMax() {
    return this->FindMax(this->head);
}

template <class ElementType>
Node<ElementType>* BinarySearchTree<ElementType>::Insert(
    ElementType key, Node<ElementType>* bst) {
    if (!bst) {
        Node<ElementType>* e = new Node<ElementType>;
        e->data = key;
        e->leftchild = e->rightchild = NULL;
        bst = e;
    } else if (key < bst->data) {
        bst->leftchild = this->Insert(key, bst->leftchild);
    } else if (key > bst->data) {
        bst->rightchild = this->Insert(key, bst->rightchild);
    }
    return bst;
}

template <class ElementType>
void BinarySearchTree<ElementType>::Insert(ElementType key) {
    this->head = this->Insert(key, this->head);
}
template <class ElementType>
Node<ElementType>* BinarySearchTree<ElementType>::Delete(
    ElementType key, Node<ElementType>* bst) {
    Node<ElementType>* e;
    if (!bst) {
        std::cout << "该元素未找到\n";
    } else if (key < bst->data) {
        bst->leftchild = this->Delete(key, bst->leftchild);
    } else if (key > bst->data) {
        bst->rightchild = this->Delete(key, bst->rightchild);
    } else {
        if (bst->leftchild && bst->rightchild) {
            e = this->FindMin(bst->rightchild);
            bst->data = e->data;
            bst->rightchild = this->Delete(e->data, bst->rightchild);
        } else {
            e = bst;
            if (bst->leftchild) {
                bst = bst->leftchild;
            } else if (bst->rightchild) {
                bst = bst->rightchild;
            } else {
                bst = NULL;
            }
            delete (e);
        }
    }
    return bst;
}

template <class ElementType>
void BinarySearchTree<ElementType>::Delete(ElementType key) {
    this->head = this->Delete(key, this->head);
}

int NextPrime(int i) {
    if (i == 1) {
        return 2;
    }
    int p = i % 2 ? i + 2 : i + 1;
    int j;
    while (p < MAXTABLESIZE) {
        for (j = int(sqrt(p)); j > 2; j--) {
            if (p % j == 0) {
                break;
            }
        }
        if (j == 2) {
            break;
        }
        p += 2;
    }
    return p;
}

template <class ElementType>
int HashTable<ElementType>::Hash(ElementType key) {
    return key % this->TableSize;
}

template <class ElementType>
void HashTable<ElementType>::InitializeTable(int Size) {
    this->TableSize = NextPrime(Size);
    this->TheCells = new Cell<ElementType>[this->TableSize];
    for (int i = 0; i < this->TableSize; i++) {
        this->TheCells[i].Info = Empty;
    }
}

template <class ElementType>
int HashTable<ElementType>::Find(ElementType key) {
    int currentpos, newpos;
    int cnum = 0;
    currentpos = newpos = this->Hash(key);
    while (this->TheCells[newpos].Info != Empty &&
           this->TheCells[newpos].data != key) {
        if (++cnum % 2) {
            newpos = currentpos + (cnum + 1) / 2 * (cnum + 1) / 2;
            newpos %= this->TableSize;
        } else {
            newpos = currentpos - (cnum) / 2 * cnum / 2;
            newpos %= this->TableSize;
        }
    }
    return newpos;
}

template <class ElementType>
void HashTable<ElementType>::Insert(ElementType key) {
    int pos = this->Find(key);
    if (this->TheCells[pos].Info != Legitimate) {
        this->TheCells[pos].data = key;
        this->TheCells[pos].Info = Legitimate;
    }
}

template <class ElementType>
void HashTable<ElementType>::Delete(ElementType key) {
    int pos = this->Find(key);
    if (this->thisCells[pos].data == key) {
        this->TheCells[pos].Info = Deleted;
    }
}

template <class ElementType>
void HashTable<ElementType>::Output() {
    std::cout << "表的尺寸为：" << this->TableSize << std::endl;
    for (int i = 0; i < this->TableSize && this->TheCells[i].Info == Legitimate;
         i++) {
        std::cout << this->TheCells[i].data << " ";
    }
    std::cout << "\n";
}

template <class ElementType>
int HashTable1<ElementType>::Hash(ElementType key) {
    return key % this->TableSize;
}

template <class ElementType>
void HashTable1<ElementType>::InitializeTable(int Size) {
    this->TableSize = NextPrime(Size);
    this->TheLists = new LinkNode<ElementType>[this->TableSize];
    for (int i = 0; i < this->TableSize; i++) {
        this->TheLists[i].next = NULL;
    }
}

template <class ElementType>
LinkNode<ElementType>* HashTable1<ElementType>::Find(ElementType key) {
    int pos = this->Hash(key);
    LinkNode<ElementType>* p = this->TheLists[pos].next;
    while (p && p->data != key) {
        p = p->next;
    }
    return p;
}

template <class ElementType>
void HashTable1<ElementType>::Insert(ElementType key) {
    int pos = this->Hash(key);
    LinkNode<ElementType>* p = &this->TheLists[pos];
    while (p->next) {
        if (p->next->data == key) {
            return;
        }
        p = p->next;
    }
    if (p) {
        LinkNode<ElementType>* e = new LinkNode<ElementType>;
        e->data = key;
        e->next = NULL;
        p->next = e;
    }
}

template <class ElementType>
void HashTable1<ElementType>::Delete(ElementType key) {
    int pos = this->Hash(key);
    LinkNode<ElementType>* p = &this->TheLists[pos];
    while (p->next) {
        if (p->next->data == key) {
            break;
        }
        p = p->next;
    }
    if (p->next) {
        if (p->next->data == key) {
            LinkNode<ElementType>* tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        }
    }
}

template <class ElementType>
void HashTable1<ElementType>::Output() {
    std::cout << "表的尺寸为:" << this->TableSize << "\n";
    LinkNode<ElementType>* p;
    for (int i = 0; i < this->TableSize; i++) {
        p = this->TheLists[i].next;
        while (p) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << "\n";
    }
}
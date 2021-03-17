#ifndef SEARCHH_H
#define SEARCHH_H

template <typename ElementType>
int Sequential_search(ElementType a[], int length, ElementType key);

template <typename ElementType>
int Binary_search(ElementType a[], int length, ElementType key);

template <typename ElementType>
int Interpolation_search(ElementType a[], int length, ElementType key);

template <class ElementType>
struct Node {
    ElementType data;
    Node<ElementType>* leftchild;
    Node<ElementType>* rightchild;
};

template <class ElementType>
class BinarySortTree {
private:
    Node<ElementType>* head;
    bool SearchBst(Node<ElementType>*, ElementType, Node<ElementType>*,
                   Node<ElementType>*);

public:
    BinarySortTree();
    ~BinarySortTree();
    void Create(ElementType a[], int length);
    bool SearchBST(ElementType, Node<ElementType>*);
    bool InsertBST(ElementType);
};

#include "../src/search.inl"
#endif
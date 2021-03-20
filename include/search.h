#ifndef SEARCHH_H
#define SEARCHH_H
#define MAXTABLESIZE 50

/* 顺序表查找 */
template <typename ElementType>
int Sequential_search(ElementType a[], int length, ElementType key);

/* 二分查找 */
template <typename ElementType>
int Binary_search(ElementType a[], int length, ElementType key);

/* 插值查找 */
template <typename ElementType>
int Interpolation_search(ElementType a[], int length, ElementType key);

/* 二叉排序搜索树 */
template <class ElementType>
struct Node {
    ElementType data;
    Node<ElementType>* leftchild;
    Node<ElementType>* rightchild;
};

template <class ElementType>
class BinarySearchTree {
private:
    Node<ElementType>* head;
    bool SearchBst(Node<ElementType>*, ElementType, Node<ElementType>*,
                   Node<ElementType>*);
    Node<ElementType>* find(ElementType, Node<ElementType>*);
    Node<ElementType>* Insert(ElementType, Node<ElementType>*);
    Node<ElementType>* Delete(ElementType, Node<ElementType>*);
    Node<ElementType>* FindMin(Node<ElementType>*);
    Node<ElementType>* FindMax(Node<ElementType>*);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void Create(ElementType a[], int);
    bool SearchBST(ElementType, Node<ElementType>*);
    bool InsertBST(ElementType);
    Node<ElementType>* Find(ElementType);
    Node<ElementType>* FindMin();
    Node<ElementType>* FindMax();
    void Insert(ElementType);
    void Delete(ElementType);
};

int NextPrime(int);

enum status { Empty, Deleted, Legitimate };

template <class ElementType>
struct Cell {
    ElementType data;
    status Info;
};

template <class ElementType>
class HashTable {
private:
    int TableSize;
    Cell<ElementType>* TheCells;
    int Hash(ElementType);

public:
    HashTable(){};
    ~HashTable(){};
    void InitializeTable(int);
    int Find(ElementType);
    void Insert(ElementType);
    void Delete(ElementType);
    void Output();
};

template <class ElementType>
struct LinkNode {
    ElementType data;
    LinkNode<ElementType>* next;
};

template <class ElementType>
class HashTable1 {
private:
    int TableSize;
    LinkNode<ElementType>* TheLists;
    int Hash(ElementType);

public:
    HashTable1(){};
    ~HashTable1(){};
    void InitializeTable(int);
    LinkNode<ElementType>* Find(ElementType);
    void Insert(ElementType);
    void Delete(ElementType);
    void Output();
};

#include "../src/search.inl"
#endif
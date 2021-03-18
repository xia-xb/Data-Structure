#include <iostream>

#include "search.h"

using namespace std;

int main() {
    int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinarySearchTree<int> bst;
    bst.Create(a, 11);
    Node<int>* p = bst.Find(5);
    if (p) {
        cout << p->data << endl;
    }
    if (p = bst.FindMin()) {
        cout << p->data << endl;
    }
    if (p = bst.FindMax()) {
        cout << p->data << endl;
    }
    bst.Insert(18);
    p = bst.Find(18);
    if (p) {
        cout << p->data << endl;
    }
    bst.Delete(18);
    p = bst.Find(18);
    if (p) {
        cout << p->data << endl;
    } else {
        cout << "未找到18" << endl;
    }
    return 0;
}
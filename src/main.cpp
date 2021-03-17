#include <iostream>

#include "search.h"

using namespace std;

int main() {
    int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinarySortTree<int> bst;
    bst.Create(a, 11);
    Node<int>* p = new Node<int>;
    if (bst.SearchBST(4, p)) {
        cout << "查找成功" << endl;
        cout << p->data << endl;
    } else {
        cout << "查找失败" << endl;
    }
    if(bst.InsertBST(18)){
        cout<<"插入成功"<<endl;
    };
    if (bst.SearchBST(18, p)) {
        cout << "查找成功" << endl;
        cout << p->data << endl;
    } else {
        cout << "查找失败" << endl;
    }
    return 0;
}
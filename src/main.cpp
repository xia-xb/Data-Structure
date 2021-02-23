
#include <iostream>

#include "binaryTree.h"

using namespace std;

int main() {
    BinaryTree tree('a');
    tree.create();
    tree.PreOrderTraverse();
    cout<<endl;
    tree.InOrderTraverse();
    cout<<endl;
    tree.PostOrderTraverse();
    return 0;
}
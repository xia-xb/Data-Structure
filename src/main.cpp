
#include <iostream>

#include "binThrTree.h"

using namespace std;

int main() {
    BiThrTree tree;
    tree.create();
    tree.InThreading_head();
    tree.InOrderTraverse_Thr();
    return 0;
}
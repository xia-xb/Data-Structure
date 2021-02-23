#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef char TElemType;

class BinaryTree {
private:
    TElemType data;
    BinaryTree *lchild, *rchild;

public:
    BinaryTree(/* args */);
    BinaryTree(TElemType val);
    ~BinaryTree();
    void PreOrderTraverse();
    void InOrderTraverse();
    void PostOrderTraverse();
    void create();
};

#endif
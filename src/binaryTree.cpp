#include "binaryTree.h"

#include <iostream>

BinaryTree::BinaryTree(/* args */) {}
BinaryTree::BinaryTree(TElemType val){
    this->data=val;
    this->lchild=NULL;
    this->rchild=NULL;
}

BinaryTree::~BinaryTree() {}

void BinaryTree::PreOrderTraverse() {
    if (this == NULL) {
        return;
    }
    std::cout << this->data;
    this->lchild->PreOrderTraverse();
    this->rchild->PreOrderTraverse();
}

void BinaryTree::InOrderTraverse() {
    if (this == NULL) {
        return;
    }
    this->lchild->InOrderTraverse();
    std::cout << this->data;
    this->rchild->InOrderTraverse();
}

void BinaryTree::PostOrderTraverse() {
    if (this == NULL) {
        return;
    }
    this->lchild->PostOrderTraverse();
    this->rchild->PostOrderTraverse();
    std::cout << this->data;
}

void BinaryTree::create() {
    TElemType ch;
    std::cin >> ch;
    if (ch=='#'){
        *this=NULL;
    } else{
        this->data = ch;
        BinaryTree *left=new(BinaryTree),*right=new(BinaryTree);
        this->lchild=left;
        this->rchild=right;
        this->lchild->create();
        this->rchild->create();
    }
}
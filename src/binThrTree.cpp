#include "binThrTree.h"

#include <iostream>

TreeNode *pre;

BiThrTree::BiThrTree() {}

BiThrTree::~BiThrTree() {}



void BiThrTree::create(TreeNode *&T) {
    TElemType ch;
    std::cin >> ch;
    if (ch == '#') {
        T = NULL;
    } else {
        T=new(TreeNode);
        T->data=ch;
        T->LTag=Link;
        T->RTag=Link;
        this->create(T->lchild);
        this->create(T->rchild);
    }
}

void BiThrTree::InThreading(TreeNode* &T) {
    if (T) {
        this->InThreading(T->lchild);
        if (!T->lchild) {
            T->LTag = Thred;
            T->lchild = pre;
        }
        if (!pre->rchild) {
            pre->RTag = Thred;
            pre->rchild = T;
        }
        pre = T;
        this->InThreading(T->rchild);
    }
}

void BiThrTree::InOrderTraverse_Thr(TreeNode* &T) {
    TreeNode *p;
    p = T->lchild;
    while (p != T) {
        while (p->LTag == Link) {
            p = p->lchild;
        }
        std::cout << p->data;
        while (p->RTag && p->rchild != T) {
            p = p->rchild;
            std::cout << p->data;
        }
        p = p->rchild;
    }
}
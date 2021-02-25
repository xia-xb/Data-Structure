#ifndef BINTHRTREE_H
#define BINTHRTREE_H

typedef char TElemType;
typedef enum { Link, Thred } pointerTag;

class TreeNode {
    friend class BiThrTree;

private:
    TElemType data;
    TreeNode *lchild, *rchild;
    pointerTag LTag;
    pointerTag RTag;
};

class BiThrTree {
private:
    TreeNode *root;

public:
    BiThrTree();
    ~BiThrTree();
    void InThreading() { this->InThreading(this->root); };
    void InThreading(TreeNode *&);
    void InOrderTraverse_Thr() { this->InOrderTraverse_Thr(this->root); };
    void InOrderTraverse_Thr(TreeNode *&);
    void create() { this->create(this->root); };
    void create(TreeNode *&);
};

/* BiThrTree::BiThrTree()
{
}

BiThrTree::~BiThrTree()
{
}
 */

#endif
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
    TreeNode *head;

public:
    BiThrTree();
    ~BiThrTree();
    void InThreading() { this->InThreading(this->root); };
    void InThreading(TreeNode *&);
    void InThreading_head(){this->InThreading_head(this->root);}
    void InThreading_head(TreeNode *&);
    void InOrderTraverse_Thr() { this->InOrderTraverse_Thr(this->head); };
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
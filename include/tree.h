#ifndef TREE_H
#define TREE_H

/* 双亲表示法 */

#define MAX_TREE_SIZE 100
typedef int TElemType;

struct PTNode {/* 结点结构 */
    TElemType data;
    int data;
};

struct PTree {
    PTNode nodes[MAX_TREE_SIZE];/* 树结构 */
    int r, n; /* 根的位置和结点数 */
};

/* 孩子表示法 */

struct CTNode{/* 孩子结点 */
    int child;
    CTNode *next;
};

struct CTBox{/* 表头结点 */
    TElemType data;
    CTNode *firstchild;
};

struct CTree/* 树结构 */
{
    CTBox nodes[MAX_TREE_SIZE];
    int r,n;/* 根的位置和结点数 */
};


/* 双亲孩子表示法 */

struct CTnode/* 孩子结点 */
{
    int child;
    CTnode *next;
};

struct CTbox/* 表头结点 */
{
    TElemType data;
    int parent;
    CTnode *firstchild;
};

struct Ctree/* 树结构 */
{
    CTbox nodes[MAX_TREE_SIZE];
    int r,n;/* 根的位置和结点数 */
};

/* 孩子兄弟表示法 */

struct CSNode
{
    TElemType data;
    CSNode *firstchild;
    CSNode *rightsib;
};




#endif
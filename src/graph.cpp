#include "graph.h"

#include <iostream>

#include "queue2.h"

using namespace std;

/* ******************************************************************** */
MGraph::MGraph() {
    std::cout << "输入顶点数和边数\n";
    std::cin >> this->numVertexes;
    std::cin >> this->numEdges;
    std::cout << "输入顶点数据\n";
    for (int i = 0; i < this->numVertexes; i++) {
        std::cin >> this->vexs[i];
    }
    for (int i = 0; i < this->numVertexes; i++) {
        for (int j = 0; j < this->numVertexes; j++) {
            this->arc[i][j] = INFINITY;
        }
    }
    for (int k = 0; k < this->numEdges; k++) {
        std::cout << "输入边(vi,vj)的下标i,j和权w\n";
        int i, j, w;
        std::cin >> i >> j >> w;
        this->arc[i][j] = w;
        this->arc[j][i] = this->arc[i][j];
    }
}

MGraph::~MGraph() {}

/* 从第i个顶点开始遍历 */
void MGraph::DFS(int i) {
    std::cout << this->vexs[i];
    this->visited[i] = true;
    /* 迭代，依次找到与第i个顶点联通的顶点，则从该顶点迭代遍历 */
    for (int j = 0; j < this->numVertexes; j++) {
        if (this->arc[i][j] == 1 && !this->visited[j]) {
            this->DFS(j);
        }
    }
}

/* 遍历图中所有顶点 */
void MGraph::DFSTraverse() {
    for (int i = 0; i < this->numVertexes; i++) {
        this->visited[i] = false;
    }
    for (int i = 0; i < this->numVertexes; i++) {
        if (!this->visited[i]) {
            this->DFS(i);
        }
    }
}

void MGraph::BFSTraverse() {
    LinkQueue<int> Q;
    for (int i = 0; i < this->numVertexes; i++) {
        this->visited[i] = false;
    }
    for (int i = 0; i < this->numVertexes; i++) {
        if (!this->visited[i]) {
            // this->visited[i] = true;
            // std::cout << this->vexs[i];
            Q.QueueInsert(i);
            while (!Q.IsEmpty()) {
                this->visited[i] = true;
                std::cout << this->vexs[i];
                Q.QueueDelete(i);
                for (int j = 0; j < this->numVertexes; j++) {
                    if (this->arc[i][j] == 1 && !this->visited[j]) {
                        // this->visited[j] = true;
                        // std::cout << this->vexs[j];
                        Q.QueueInsert(j);
                    }
                }
            }
        }
    }
}

/* *************************************************************************/
GraphAdjList::GraphAdjList() {
    std::cout << "输入顶点数和边数\n";
    std::cin >> this->numVertexes >> this->numEdges;
    std::cout << "输入顶点数据\n";
    for (int i = 0; i < this->numVertexes; i++) {
        std::cin >> this->adjList[i].data;
        this->adjList[i].firstedge = NULL;
    }
    for (int k = 0; k < this->numEdges; k++) {
        std::cout << "输入边(vi,vj)的顶点序号\n";
        int i, j;
        std::cin >> i >> j;
        EdgeNode* e = new (EdgeNode);
        e->adjvex = j;
        e->next = this->adjList[i].firstedge;
        this->adjList[i].firstedge = e;

        e = new (EdgeNode);
        e->adjvex = i;
        e->next = this->adjList[j].firstedge;
        this->adjList[j].firstedge = e;
    }
}

GraphAdjList::~GraphAdjList() {}

void GraphAdjList::DFS(int i) {
    std::cout << this->adjList[i].data;
    this->visited[i] = true;
    EdgeNode* e = this->adjList[i].firstedge;
    while (e) {
        if (!this->visited[e->adjvex]) {
            this->DFS(e->adjvex);
        }
        e = e->next;
    }
}

void GraphAdjList::DFSTraverse() {
    for (int i = 0; i < this->numVertexes; i++) {
        this->visited[i] = false;
    }
    for (int i = 0; i < this->numVertexes; i++) {
        if (!this->visited[i]) {
            this->DFS(i);
        }
    }
}

void GraphAdjList::BFSTraverse() {
    LinkQueue<int> Q;
    for (int i = 0; i < this->numVertexes; i++) {
        this->visited[i] = false;
    }
    for (int i = 0; i < this->numVertexes; i++) {
        if (!this->visited[i]) {
            // this->visited[i] = true;
            // std::cout << this->adjList[i].data;
            Q.QueueInsert(i);
            while (!Q.IsEmpty()) {
                this->visited[Q.GetHead()]=true;
                std::cout<<this->adjList[Q.GetHead()].data;
                Q.QueueDelete(i);
                EdgeNode* e = this->adjList[i].firstedge;
                while (e) {
                    if (!this->visited[e->adjvex]) {
                        // this->visited[e->adjvex] = true;
                        // std::cout << this->adjList[e->adjvex].data;
                        Q.QueueInsert(e->adjvex);
                    }
                    e = e->next;
                }
            }
        }
    }
}

/* ********************************************************************************************/
OrthList::OrthList() {
    std::cout << "输入顶点数和边数\n";
    std::cin >> this->numVertexes >> this->numEdges;
    std::cout << "输入顶点数据\n";
    for (int i = 0; i < this->numVertexes; i++) {
        cin >> this->OrthAdjList[i].data;
        this->OrthAdjList[i].firstin = NULL;
        this->OrthAdjList[i].firstout = NULL;
    }
    for (int k = 0; k < this->numEdges; k++) {
        std::cout << "输入弧<vi,vj>的下标i,j\n";
        int i, j;
        std::cin >> i >> j;
        EEdgeNode* e = new (EEdgeNode);
        e->tailvex = i;
        e->headvex = j;
        e->headlink = this->OrthAdjList[j].firstin;
        this->OrthAdjList[j].firstin = e;
        e->taillink = this->OrthAdjList[i].firstout;
        this->OrthAdjList[i].firstout = e;
    }
}

OrthList::~OrthList() {}

/* 十字链表的DFS遍历方法与邻接表类似，可以只根据邻接表或者逆邻接表遍历即可 */
/* 邻接表遍历为例，firstout连接后，迭代headvex顶点 */
/* 遍历下一个链接顶点，需要taillink替代 */
void OrthList::DFS(int i) {
    std::cout << this->OrthAdjList[i].data;
    this->visited[i] = true;
    EEdgeNode* e = this->OrthAdjList[i].firstout;
    while (e) {
        if (!this->visited[e->headvex]) {
            this->DFS(e->headvex);
        }
        e = e->taillink;
    }
}

void OrthList::DFSTraverse() {
    for (int i = 0; i < this->numVertexes; i++) {
        this->visited[i] = false;
    }
    for (int i = 0; i < this->numVertexes; i++) {
        if (!this->visited[i]) {
            this->DFS(i);
        }
    }
}

/* ************************************************************************************************/
AdjMulTables::AdjMulTables() {
    std::cout << "输入顶点数和边数\n";
    std::cin >> this->numVertexes >> this->numEdges;
    std::cout << "输入顶点数据\n";
    for (int i = 0; i < this->numVertexes; i++) {
        std::cin >> this->AdjMulList[i].data;
        this->AdjMulList[i].firstedge = NULL;
    }
    for (int k = 0; k < this->numEdges; k++) {
        std::cout << "输入边(vi,vj)的下标i,j\n";
        int i, j;
        std::cin >> i >> j;
        EEEdgeNode* e = new (EEEdgeNode);
        e->ivex = i;
        e->jvex = j;
        e->ilink = this->AdjMulList[i].firstedge;
        this->AdjMulList[i].firstedge = e;
        e->jlink = this->AdjMulList[j].firstedge;
        this->AdjMulList[j].firstedge = e;
    }
}

AdjMulTables::~AdjMulTables() {}

/* 无向图邻接多重表的DFS遍历，与前面类似 */
/* 注意通过firstedge连接后，迭代jvex顶点 */
/* 遍历下一个链接顶点是ilink替代 */
void AdjMulTables::DFS(int i) {
    std::cout << this->AdjMulList[i].data;
    this->visited[i] = true;
    EEEdgeNode* e = this->AdjMulList[i].firstedge;
    while (e) {
        if (!this->visited[e->jvex]) {
            this->DFS(e->jvex);
        }
        e = e->ilink;
    }
}

void AdjMulTables::DFSTraverse() {
    for (int i = 0; i < this->numVertexes; i++) {
        this->visited[i] = false;
    }
    for (int i = 0; i < this->numVertexes; i++) {
        if (!this->visited[i]) {
            this->DFS(i);
        }
    }
}

/* **********************************************************************************************/
ArrayEdge::ArrayEdge() {
    std::cout << "输入顶点数和边数\n";
    std::cin >> this->numVex >> this->numEdge;
    std::cout << "输入顶点数据\n";
    for (int i = 0; i < this->numVex; i++) {
        std::cin >> this->vex[i];
    }
    for (int k = 0; k < this->numEdge; k++) {
        std::cout << "输入边(vi,vj)的下标i,j以及权重w\n";
        int i, j, w;
        std::cin >> i >> j >> w;
        this->edge[k].begin = i;
        this->edge[k].end = j;
        this->edge[k].weight = w;
    }
}

ArrayEdge::~ArrayEdge() {}

/* 边集数组DFS遍历与邻接矩阵DFS遍历类似 */
/* 通过遍历边数组，寻找与顶点i链接的边，之后进行迭代 */
void ArrayEdge::DFS(int i) {
    std::cout << this->vex[i];
    this->visited[i] = true;
    for (int k = 0; k < this->numEdge; k++) {
        if (this->edge[k].begin == i && !this->visited[this->edge[k].end]) {
            this->DFS(this->edge[k].end);
        }
    }
}

void ArrayEdge::DFSTraverse() {
    for (int i = 0; i < this->numVex; i++) {
        this->visited[i] = false;
    }
    for (int i = 0; i < this->numVex; i++) {
        if (!this->visited[i]) {
            this->DFS(i);
        }
    }
}
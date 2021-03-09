#include "graph.h"

#include <iostream>
using namespace std;

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

AdjMulTables::AdjMulTables() {}

AdjMulTables::~AdjMulTables() {}

ArrayEdge::ArrayEdge() {
    std::cout << "输入顶点数和边数\n";
    int numVex, numEdge;
    std::cin >> numVex >> numEdge;
    std::cout << "输入顶点数据\n";
    for (int i = 0; i < numVex; i++) {
        std::cin >> this->vex[i];
    }
    for (int i = 0; i < numEdge; i++) {
        std::cout << "输入边(vi,vj)的下标i,j以及权重w\n";
        int i, j, w;
        std::cin >> i >> j >> w;
        this->edge[i].begin = i;
        this->edge[i].end = j;
        this->edge[i].weight = w;
    }
}

ArrayEdge::~ArrayEdge() {}
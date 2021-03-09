#ifndef GRAPH_H
#define GRAPH_H

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

/* 图邻接矩阵结构 */
class MGraph {
private:
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;

public:
    MGraph();
    ~MGraph();
};

/* 图邻接表结构 */
struct EdgeNode {
    int adjvex;
    // EdgeType weight;
    EdgeNode *next;
};

struct VertexNode {
    VertexType data;
    EdgeNode *firstedge;
};

class GraphAdjList {
private:
    VertexNode adjList[MAXVEX];
    int numVertexes, numEdges;

public:
    GraphAdjList();
    ~GraphAdjList();
};

/* 有向图十字链表 */
struct EEdgeNode {
    int tailvex, headvex;
    EEdgeNode *headlink, *taillink;
};

struct VVertexNode {
    VertexType data;
    EEdgeNode *firstin, *firstout;
};

class OrthList {
private:
    VVertexNode OrthAdjList[MAXVEX];
    int numVertexes, numEdges;

public:
    OrthList();
    ~OrthList();
};

/* 无向图邻接多重表 */
struct EEEdgeNode {
    int ivex, jvex;
    EEEdgeNode *ilink, *jlink;
};

struct VVVertexNode {
    VertexType data;
    EEEdgeNode *firstedge;
};

class AdjMulTables {
private:
    VVVertexNode AdjMulList[MAXVEX];
    int numVertexes, numEdges;

public:
    AdjMulTables();
    ~AdjMulTables();
};

/* 边集数组 */
struct EEEEdgeNode {
    int begin, end;
    EdgeType weight;
};

class ArrayEdge {
private:
    VertexType vex[MAXVEX];
    EEEEdgeNode edge[MAXVEX];

public:
    ArrayEdge(/* args */);
    ~ArrayEdge();
};

#endif
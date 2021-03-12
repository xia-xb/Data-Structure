
#include <iostream>

#include "graph.h"
#include "queue2.h"

using namespace std;

int main() {
    MGraph graph;
    // graph.DFSTraverse();
    // cout<<endl;
    // graph.BFSTraverse();
    graph.Dijkstra(0,3);
    return 0;
}
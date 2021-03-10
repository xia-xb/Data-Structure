
#include <iostream>

#include "queue2.h"
#include "graph.h"

using namespace std;

int main() {
    GraphAdjList graph;
    graph.DFSTraverse();
    cout<<endl;
    graph.BFSTraverse();
    return 0;
}
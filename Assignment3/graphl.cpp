// ----------------------------------graphl.cpp----------------------------------------
// Lei CSS343 section A
// February 4, 2019
// February 14, 2019
// ------------------------------------------------------------------------------------
// this project is to display the graph information and implement desth-first.
// Descrition of each node is 50 chars max length. There can be several graphs, each
// has at most 100 nodes.
// edges in the input are always shown in reverse order in the output
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// - the output of the edges for each node will be in the reverse order in which they
// are listed in the input file
// - assume the input data file has correctly formatted, valid data.
//-------------------------------------------------------------------------------------

#include "graphl.h"

// -------------------------------------------------------------------------------------
// default constructor
// creates empty graph and sets the size of array to 0
//  ------------------------------------------------------------------------------------
GraphL::GraphL()
{
    size = 0;
    for(int i = 0; i < L_MAXNODES; i++) {
        graph[i].edgeHead = NULL;
        graph[i].data = NULL;
        graph[i].visited = false;
    }
}

// -------------------------------------------------------------------------------------
// destructor
// deletes all the NodeData, EdgeNode, and GraphNode data
// -------------------------------------------------------------------------------------
GraphL::~GraphL()
{
    emptyGraph();
}

// -------------------------------------------------------------------------------------
// builds up graph node information and adjacency list of edges between each node reading
// from a data file.
// -------------------------------------------------------------------------------------
void GraphL::buildGraph(ifstream& infile)
{
    int from, to;
    infile >> size;
    if(size > 0) {
        string str;
        getline(infile, str);
        for(int i = 1; i <= size; i++) {
            graph[i].data = new NodeData();
            graph[i].data -> setData(infile);
        }
        while(infile >> from >> to) {
            if(from == 0) {
                break;
            }
            EdgeNode* node = new EdgeNode;
            node -> adjGraphNode = to;
            if(graph[from].edgeHead == NULL) {
                graph[from].edgeHead = node;
                graph[from].edgeHead -> nextEdge = NULL;
            } else {
                node -> nextEdge = graph[from].edgeHead;
                graph[from].edgeHead = node;
            }
        }
    }
}

// -------------------------------------------------------------------------------------
// makes a depth-frist search and displays each node in depth-first order
// -------------------------------------------------------------------------------------
void GraphL::depthFirstSearch()
{
    cout << "Depth-first ordering: ";
    for(int i = 1; i <= size; i++) {
        if(!graph[i].visited) {
            dfsHelper(i);
        }
    }
    cout << "\n" << endl;
}

// -------------------------------------------------------------------------------------
// takes an integer as parameter which represents the index of the source code.
// outputs the source node and recursively calls inself which the adjacent node as it
// parameter
// -------------------------------------------------------------------------------------
void GraphL::dfsHelper(int v)
{
    cout << "  " << v;
    graph[v].visited = true;
    EdgeNode* current = graph[v].edgeHead;
    while(current != NULL) {
        if(!graph[current -> adjGraphNode].visited) {
            dfsHelper(current -> adjGraphNode);
        }
        current = current -> nextEdge;
    }
}

// -------------------------------------------------------------------------------------
// displays each node information and edge in the graph.
// -------------------------------------------------------------------------------------
void GraphL::displayGraph()
{
    cout << "Graph: " << endl;
    for(int i = 1; i <= size; i++) {
        cout << "Node" << i << "\t\t " << *graph[i].data << endl;
        cout << endl;
        EdgeNode* current = graph[i].edgeHead;
        while(current != NULL) {
            cout << "  " << "edge  " << i << "  " << current -> adjGraphNode << endl;
            current = current -> nextEdge;
        }
    }
    cout << endl;
}

// -------------------------------------------------------------------------------------
// deletes current object
// -------------------------------------------------------------------------------------
void GraphL::emptyGraph()
{
    for(int i = 1; i <= size; i++) {
        graph[i].visited = false;
        delete graph[i].data;
        graph[i].data = NULL;
        if(graph[i].edgeHead != NULL) {
            EdgeNode* target = graph[i].edgeHead;
            while(target != NULL) {
                graph[i].edgeHead = graph[i].edgeHead -> nextEdge;
                delete target;
                target = NULL;
                target = graph[i].edgeHead;
            }
        }
    }
}

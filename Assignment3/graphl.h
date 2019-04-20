// ----------------------------------graphl.h---------------------------------------
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
//------------------------------------------------------------------------------------

#ifndef graphl_h
#define graphl_h
#include <stdio.h>
#include "nodedata.h"

class GraphL {
    static const int L_MAXNODES = 101; // index from 1 - 101. at most 100 nodes
public:
    GraphL();                          // default constructor
    ~GraphL();                         // destructor
    void buildGraph(ifstream&);        // insert all data
    void displayGraph();               // display DFS graph
    void depthFirstSearch();           // initiate the DFS algorithm
    
private:
    int size;                          // number of nodes in the graph
    struct EdgeNode;                   // forward reference for the compiler
    struct GraphNode                   // structs used for simplicity, use classes if desired
    {
        EdgeNode* edgeHead;            // head of the list of edges
        NodeData* data;                // contains description
        bool visited;                  // flag to signal if visited
    };
    struct EdgeNode                    // structure for linked list
    {
        int adjGraphNode;              // subscript of the adjacent graph node
        EdgeNode* nextEdge;            // the next node
    };
    GraphNode graph[L_MAXNODES];       // graph node size
    void emptyGraph();                 // make the table empty
    void dfsHelper(int v);             // helper method for depthFirstSearch
};
#endif /* graphl_h */

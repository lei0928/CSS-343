// ----------------------------------graphm.h---------------------------------------
// Lei CSS343 section A
// February 4, 2019
// February 14, 2019
// ------------------------------------------------------------------------------------
// this project is to implement Dijkstra's shortest path algorithm. Descrition of each
// node is 50 chars max length. There can be several graphs, each has at most 100 nodes.
// Class includes adjacency matrix, number of nodes, TableType array, and array of
// NodeData.
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// - it's assumed the user will provide a .txt file with the integer n on first line to
// tell how many nodes.
// - on n following lines, a description of each node.
// - on following lines input sources node, space, destination, space, and final cost
// - end input with 0 for the first integer ------------------------------------------------------------------------------------

#ifndef graphm_h
#define graphm_h
#include "nodedata.h"
#include <stdio.h>

class GraphM {
    static const int M_MAXNODES = 101;                     // index from 1 - 101, at most 100 nodes
public:
        GraphM();                                          // default constructor
        ~GraphM();                                         // destructor
        void buildGraph(ifstream&);                        // insert all data
        void findShortestPath();                           // perform Dijkstra's algorithm
        void insertEdge(const int, const int, const int);  // insert cost
        void removeEdge(const int, const int);             // remove cost
        void display(const int, const int) const;          // display from/to node data
        void displayAll() const;                           // display all data
    
private:
        struct TableType
        {
            bool visited;                        // where node has been visited
            int dist;                            // shorstest distance from source
            int path;                            // previous node in path of min distance
        };
        NodeData data[M_MAXNODES];               // data for graph nodes information
        int size;                                // number of nodes in the graph
        int C[M_MAXNODES] [M_MAXNODES];          // cost array, the adjacency matrix
        TableType T[M_MAXNODES][M_MAXNODES];     // store visited, distance, path
        void makeEmpty();                        // make the table empty
        void displayPath(int, int) const;        // print path from/to node
        void displayName(int, int) const;        // print descriptions
    
};

#endif /* graphl_h */

// ----------------------------------graphm.cpp-----------------------------------------
// Lei CSS343 section A
// February 4, 2019
// February 14, 2019
// -------------------------------------------------------------------------------------
// this project is to implement Dijkstra's shortest path algorithm. Descrition of each
// node is 50 chars max length. There can be several graphs, each has at most 100 nodes.
// Class includes adjacency matrix, number of nodes, TableType array, and array of
// NodeData.
// -------------------------------------------------------------------------------------
// specifications and assumptions:
// - it's assumed the user will provide a .txt file with the integer n on first line to
// tell how many nodes.
// - on n following lines, a description of each node.
// - on following lines input sources node, space, destination, space, and final cost
// - end input with 0 for the first integer ------------------------------------------------------------------------------------

#include "graphm.h"
#include <iomanip>
#include <limits.h>
using namespace std;

// -------------------------------------------------------------------------------------
// default constructor
// among others that need to be initialized, the data member T is initialized to sets
// all dist to infinity, sets all visited to false, and sets all path to 0.
// -------------------------------------------------------------------------------------
GraphM::GraphM()
{
    size = 0;
    for(int i = 0; i < M_MAXNODES; i++) {
        for(int j = 0; j < M_MAXNODES; j++) {
            T[i][j].dist = INT_MAX;
            T[i][j].visited = false;
            T[i][j].path = 0;
            C[i][j] = INT_MAX;
        }
    }
}

// -------------------------------------------------------------------------------------
// destructor
// eliminates the remaining memory in a given table
// -------------------------------------------------------------------------------------
GraphM::~GraphM()
{
    makeEmpty();
}

// --------------------------------------------------------------------------------------
// builds up graph node information and adjacency matrix of edges between each node
// reading from a data file.
// --------------------------------------------------------------------------------------
void GraphM::buildGraph(ifstream& infile)
{
    makeEmpty();
    int from, to, distance;
    infile >> size;
    if(size > 0) {
        string str;
        getline(infile, str);
        for(int i = 1; i <= size; i++) {
            data[i].setData(infile);
        }
        while(infile >> from >> to >> distance) {
            if(from == 0) {
                break;
            }
            insertEdge(from, to, distance);
        }
    }
}

// --------------------------------------------------------------------------------------
// insert an edge into graph between two given nodes
// --------------------------------------------------------------------------------------
void GraphM::insertEdge(const int from, const int to, const int distance)
{
    if(from > 0 && from <=size && to > 0 && to <= size) {
        C[from][to] = distance;
    }
}

// --------------------------------------------------------------------------------------
//  removes an edge between two given nodes
// --------------------------------------------------------------------------------------
void GraphM::removeEdge(const int from, const int to)
{
    if(from > 0 && from <= size && to > 0 && to <=size) {
        C[from][to] = INT_MAX;
    }
}

// --------------------------------------------------------------------------------------
// find the shortest path between every node to every other node in the graph -------------------------------------------------------------------------------------
void GraphM::findShortestPath()
{
    for(int source = 1; source <= size; source++) {
        T[source][source].dist = 0;
        for(int i = 1; i <=size; i++) {
            int v = -1;
            int minDist = INT_MAX;
            for(int j = 1; j <= size; j++) {
                if(T[source][j].dist <minDist && !T[source][j].visited) {
                    minDist = T[source][j].dist;
                    v = j;
                }
            }
            if(v == -1) {
                break;
            }
            T[source][v].visited = true;
            for(int w = 1; w <= size; w++) {
                if(C[v][w] < INT_MAX && !T[source][w].visited) {
                    if(T[source][v].dist + C[v][w] < T[source][w].dist) {
                        T[source][w].dist = T[source][v].dist + C[v][w];
                        T[source][w].path = v;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= size; j++) {
            T[i][j].visited = false;
        }
    }
}

// --------------------------------------------------------------------------------------
// uses couts to demonstrate that the algorithm works properly.
// uses "----" for infinity Dijkstra's -------------------------------------------------------------------------------------
void GraphM::displayAll() const
{
    cout << "Description" << setw(20) << "From node" << setw(10) << "To node" << setw(14) << "Dijkstra's" << setw(7) << "Path" << endl;
    for(int i = 1; i <= size; i++) {
        cout << data[i] << endl;
        for(int j = 1; j <= size; j++) {
            if(i != j) {
                cout << setw(27) << i << setw(10) << j;
                if(T[i][j].dist < INT_MAX) {
                    cout << setw(12) << T[i][j].dist;
                } else {
                    cout << setw(12) << "----";
                }
                cout << setw(10);
                displayPath(i,j);
                cout << endl;
            }
        }
    }
    cout << endl;
}

// --------------------------------------------------------------------------------------
// takes two integer values and diaplays from, to, distance, and the names of the path.
//  -------------------------------------------------------------------------------------
void GraphM::display(const int from, const int to) const
{
    if(from < 1 || from > size || to < 1 || to > size) {
        return;
    }
    cout << setw(7) << from << setw(7) << to;
    if(T[from][to].dist < INT_MAX) {
        cout << setw(12) << T[from][to].dist;
    } else {
        cout << setw(15) << "----";
    }
    cout << setw(15);
    displayPath(from, to);
    cout << endl;
    displayName(from, to);
    cout << endl;
}

// --------------------------------------------------------------------------------------
// outputs Dijkstra's path as integer values to cout and retrieves the path backwards
// using recursion and prints in proper order.
//  -------------------------------------------------------------------------------------
void GraphM::displayPath(int from, int to) const
{
    int v = T[from][to].path;
    if(v != 0) {
        displayPath(from, v);
        cout << to << " ";
    } else if (from == to) {
        cout << to << " ";
    }
}

// --------------------------------------------------------------------------------------
// displays the path data of the two integers that passed in
//  -------------------------------------------------------------------------------------
void GraphM::displayName(int from, int to) const
{
    int v = T[from][to].path;
    if(v != 0) {
        displayName(from, v);
        cout << data[to] << endl;
    } else if (from == to) {
        cout << data[to] << endl;
    }
    cout << endl;
}

// --------------------------------------------------------------------------------------
// make the table empty
//-------------------------------------------------------------------------------------
void GraphM::makeEmpty()
{
    size = 0;
    for(int i = 0; i < M_MAXNODES; i++) {
        for(int j = 0; j < M_MAXNODES; j++) {
            T[i][j].dist = INT_MAX;
            T[i][j].visited = false;
            T[i][j].path = 0;
            C[i][j] = INT_MAX;
        }
    }
}

// ----------------------------------BST.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// ADT binary search tree using nodes
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// includes some of the common BST functions
// specialized node that points to movies
// ------------------------------------------------------------------------------------
#ifndef BST_h
#define BST_h

#include <iostream>
#include "movie.h"
using namespace std;

// BST Node contains pointer for left, right, and movie
struct Node
{
    Node* left;
    Node* right;
    Movie* movie;
};

class BST {
    
    // Overloaded << : prints BST in correct structure
    friend ostream& operator<< (ostream&, const BST&);
    
public:
    
    BST ();             // constructor
    ~BST ();            // desctructor
    
    bool getMovie (const Movie&, Movie*&) const;            // get movie from the tree
    bool addMovie(Movie*&);                                 // add movie node
    bool getMovieByTitle (string, int, Movie*&);
    void resetCounted();                                    // reset movie counted status to false
    
    
private:
    Node* root;                                 // points to the root of the BST
    
    void makeEmptyHelper (Node* &);             // private functions
    void printHelper (Node* cur) const;
    bool insertHelper (Node *&, Movie*&);
    bool retrieveHelper (const Movie&, Movie*& , Node*) const;
    void resetHelper(Node*);
    bool getMovieByTitleHelper (string title, int year, Movie*&, Node*);
};
#endif

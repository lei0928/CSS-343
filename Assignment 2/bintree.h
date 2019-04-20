// ----------------------------------bintree.h---------------------------------------
// Lei CSS343 section A
// January 18, 2019
// January 31, 2019
// ------------------------------------------------------------------------------------
// to create a binary search tree class called BinTree along with some additional
// functions.
// terms
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// - it has the additional functionality of being able to find the depth of a given
// node.
// - to retrieve a given node, convert a binary search tree to array or array to
// binary search tree.
// ------------------------------------------------------------------------------------

#ifndef bintree_h
#define bintree_h
#include "nodedata.h"

class BinTree {
    friend ostream& operator<<(ostream& output, const BinTree &);  // operator << (output)
 
private:
    struct Node {
        NodeData* data;           // pointer to data object
        Node* left;               // left subtree pointer
        Node* right;              // right subtree pointer
    };
    Node* root;                   // root of the tree
    void sideways(Node*, int) const; // displaySideways() helper
    
public:
    BinTree();                    // default constructor
    BinTree(const BinTree &);     // copy constructor
    ~BinTree();                   // destructor
    
    bool isEmpty() const;         // true if the tree is empty, otherwise is false
    void makeEmpty();             // make the tree empty so the isEmpty returns true
    void makeEmptyHelper(Node *&);
    BinTree& operator=(const BinTree &);
    void recursiveAssign(Node *&, Node*) const;
    void recursiveAssignHelper(const BinTree &);
    bool operator==(const BinTree &) const;          // equality operator
    bool equalHelper(Node*, Node*) const;
    bool operator!=(const BinTree &) const;          // inequality operator
    bool insert(NodeData*);
    bool retrieve(const NodeData &, NodeData *&);    // look for the input, store in the right hand
    void retrieveHelper(Node*, const NodeData&, NodeData *&, bool &);
    int getHeight(const NodeData &);
    int getHeightHelper(Node *&, const NodeData &, int &);
    void displaySideways() const;                    // displays the tree sideways
    void deleteRoot();
    void printTreePreorder();
    void printTreePreorderHelper(Node *);
    void inorderTraversal(Node *) const;
    void bstreeToArray(NodeData* []);
    int bstreeToArrayHelper(Node* current, NodeData *tempArray[]);
    void arrayToBSTree(NodeData* []);
    void arrayToBSTreeHelper(NodeData* tempArray[], const Node* current, int low, int high);
    
};
#endif /* bintree_h */

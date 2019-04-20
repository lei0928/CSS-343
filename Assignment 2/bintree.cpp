 // ----------------------------------bintree.cpp---------------------------------------
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

#include "bintree.h"

// ------------------------------------------------------------------------------------
// default constructor
// builds an empty tree
// ------------------------------------------------------------------------------------
BinTree::BinTree()
{
    root = NULL;
}

// ------------------------------------------------------------------------------------
// copy constructor
// deep copy of an existing binary search tree
// ------------------------------------------------------------------------------------
BinTree::BinTree(const BinTree & rhs)
{
    recursiveAssign(root, rhs.root);
}

// ------------------------------------------------------------------------------------
// destructor
// eliminates the remaining memory in a given binary search tree
// ------------------------------------------------------------------------------------
BinTree::~BinTree()
{
    makeEmpty();
}

// ------------------------------------------------------------------------------------
// returns true or false whether a tree has a null root pointer
// ------------------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
    return (root == NULL);
}

// ------------------------------------------------------------------------------------
// to call the recursive mothod helper
// ------------------------------------------------------------------------------------
void BinTree::makeEmpty()
{
    if(!isEmpty()) {
        makeEmptyHelper(root);
    }
}

// ------------------------------------------------------------------------------------
// - if the left child isn't null, call make empty on it
// - if the right child isn't null, call make empty on it
// - otherwise, delete the current node and it's child pointers
// ------------------------------------------------------------------------------------
void BinTree::makeEmptyHelper(Node *& currentNode)
{
    if (currentNode->left != NULL) {
        makeEmptyHelper(currentNode->left);
    }
    if (currentNode->right != NULL) {
        makeEmptyHelper(currentNode->right);
    }
    delete currentNode->data;
    delete currentNode;
    currentNode = NULL;
}

// ------------------------------------------------------------------------------------
// manages the memory of the root deletion
// ------------------------------------------------------------------------------------
void BinTree::deleteRoot()
{
    root->left = NULL;
    root->right = NULL;
    delete root;
}

// ------------------------------------------------------------------------------------
// inserts a nodedata into a new tree and declares memory for this
// ------------------------------------------------------------------------------------
bool BinTree::insert(NodeData* dataPtr)
{
    Node* newPtr = new Node;
    newPtr->data = dataPtr;
    dataPtr = NULL;
    newPtr->left = newPtr->right = NULL;
    if (isEmpty()) {
        root = newPtr;
    } else {
        Node* current = root;
        bool inserted = false;
        while(!inserted) {
            if(*newPtr->data == *current->data) {
                delete newPtr;
                newPtr = NULL;
                return false;
            } else if (*newPtr->data < *current->data) {
                if (current->left == NULL) {
                    current->left = newPtr;
                    inserted = true;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = newPtr;
                    inserted = true;
                } else {
                    current = current->right;
                }
            }
        }
    }
    return true;
}

// ------------------------------------------------------------------------------------
// clears "this" and assigns the right hand argument's value to it
// ------------------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree & rhs)
{
    if (this != &rhs) {
        makeEmpty();
        recursiveAssign(root, rhs.root);
        return *this;
    } else {
        return *this;
    }
}

// ------------------------------------------------------------------------------------
// recursively copies the right hand to the passed root called "copied"
// ------------------------------------------------------------------------------------
void BinTree::recursiveAssign(Node *& copied, Node* rhs) const
{
    if (rhs != NULL) {
        Node* temp = new Node;
        NodeData* tempNode = new NodeData(*rhs->data);
        temp->data = tempNode;
        copied = temp;
        recursiveAssign(copied->left, rhs->left);
        recursiveAssign(copied->right, rhs->right);
    } else {
        copied = rhs;
    }
}

// ------------------------------------------------------------------------------------
// recursive method helper
// ------------------------------------------------------------------------------------
void BinTree::recursiveAssignHelper(const BinTree &rhs)
{
    recursiveAssign(root, rhs.root);
}

// ------------------------------------------------------------------------------------
// print tree function
// ------------------------------------------------------------------------------------
void BinTree::printTreePreorder()
{
    printTreePreorderHelper(root);
}

// ------------------------------------------------------------------------------------
// print tree revursive method helper
// ------------------------------------------------------------------------------------
void BinTree::printTreePreorderHelper(Node* toPrint)
{
    if (toPrint != NULL) {
        cout << *toPrint->data;
        printTreePreorderHelper(toPrint->left);
        printTreePreorderHelper(toPrint->right);
    }
}

// ------------------------------------------------------------------------------------
// to get the NodeData* of a given object in the tree and to report whether the objest
// is found
// ------------------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData& search, NodeData*& found)
{
    bool isFound = false;
    retrieveHelper(root, search, found, isFound);
    return isFound;
}

// ------------------------------------------------------------------------------------
// retrieve recursive method helper
// ------------------------------------------------------------------------------------
void BinTree::retrieveHelper(Node* current, const NodeData& search, NodeData*& found, bool& isFound)
{
    if (current != NULL) {
        if(*current->data == search) {
            isFound = true;
            found = current->data;
        } else {
            if (search < *current->data) {
                retrieveHelper(current->left, search, found, isFound);
            } else {
                retrieveHelper(current->right, search, found, isFound);
            }
        }
    }
    found = NULL;
}

// ------------------------------------------------------------------------------------
// define two trees to be equal if they have the same data and same structure
// ------------------------------------------------------------------------------------
bool BinTree::operator==(const BinTree & rhs) const
{
    return equalHelper(root, rhs.root);
}

// ------------------------------------------------------------------------------------
// define two trees if they are not to be equal
// ------------------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree & rhs) const
{
    return !(*this == rhs);
}

// ------------------------------------------------------------------------------------
// equal function recursive method helper
// ------------------------------------------------------------------------------------
bool BinTree::equalHelper(Node* current, Node* rhs) const
{
    if (current == NULL && rhs == NULL) {
        return true;
    }
    if ((current == NULL) || (rhs == NULL)) {
        return false;
    }
    if (*current->data != *rhs->data) {
        return false;
    }
    return (equalHelper(current->left, rhs->left) && equalHelper(current->right, rhs->right));
}

// ------------------------------------------------------------------------------------
// to find the height of a given value in the tree
// ------------------------------------------------------------------------------------
int BinTree::getHeight(const NodeData & toFind)
{
    int height = 0;
    getHeightHelper(root, toFind, height);
    return height;
}

// ------------------------------------------------------------------------------------
// recursive method to find the deepest past based on a postorder traversal
// ------------------------------------------------------------------------------------
int BinTree::getHeightHelper(Node *& current, const NodeData & theNode, int & theHeight)
{
    if (!current) {
        return 0;
    }
    int leftHeight = getHeightHelper(current->left, theNode, theHeight);
    int rightHeight = getHeightHelper(current->right, theNode, theHeight);
    if (*current->data == theNode) {
        theHeight = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// ------------------------------------------------------------------------------------
// to fill an array of NodeData* by using an inorder traversal of the tree
// ------------------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* tempArray[])
{
    bstreeToArrayHelper(root, tempArray);
    makeEmpty();
}

// ------------------------------------------------------------------------------------
// recursive method to fill up the binary serach tree while updating the array indenx
// using pointer arithmatic
// ------------------------------------------------------------------------------------
int BinTree::bstreeToArrayHelper(Node* current, NodeData* tempArray[])
{
    if (current == NULL) {
        return 0;
    }
    int left = bstreeToArrayHelper(current->left, tempArray);
    NodeData *temp;
    temp = current->data;
    current->data = NULL;
    *(tempArray + left) = temp;
    temp = NULL;
    int right = bstreeToArrayHelper(current->right, tempArray + left + 1);
    return left + right + 1;
}

// ------------------------------------------------------------------------------------
// to build a balanced BinTree from a sorted array of NodeData*, leaving the array
// filled with NULLs
// ------------------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* tempArray[])
{
    int high = 0;
    for (int i = 0; i < 100; i++) {
        if (tempArray[i] != NULL) {
            high++;
        } else {
            tempArray[i] = NULL;
        }
    }
    arrayToBSTreeHelper(tempArray, root, 0, high - 1);
}

// ------------------------------------------------------------------------------------
// recursive method for calculations
// ------------------------------------------------------------------------------------
void BinTree::arrayToBSTreeHelper(NodeData* tempArray[], const Node* current, int low, int high)
{
    if (low > high) {
        current = NULL;
    } else {
        int root = (low + high) / 2;
        NodeData *temp;
        temp = tempArray[root];
        tempArray[root] = NULL;
        insert(temp);
        arrayToBSTreeHelper(tempArray, current, low, root - 1);
        arrayToBSTreeHelper(tempArray, current, root + 1, high);
    }
}

// ------------------------------------------------------------------------------------
// prints the tree using inorder traversal
// ------------------------------------------------------------------------------------
ostream& operator<<(ostream& output, const BinTree& tree)
{
    tree.inorderTraversal(tree.root);
    output << "  " << endl;
    return output;
}

// ------------------------------------------------------------------------------------
// inorder traversal and prints data
// ------------------------------------------------------------------------------------
void BinTree::inorderTraversal(Node *current) const
{
    if (current != NULL) {
        inorderTraversal(current->left);
        cout << *current->data << " ";
        inorderTraversal(current->right);
    }
}

// ------------------------------------------------------------------------------------
// display a binary tree as if you are viewing it from the side
// ------------------------------------------------------------------------------------
void BinTree::displaySideways() const
{
    sideways(root, 0);
}

// ------------------------------------------------------------------------------------
// helper method for displaySideways
// ------------------------------------------------------------------------------------
void BinTree::sideways(Node* current, int level) const
{
    if (current != NULL) {
        level++;
        sideways(current->right, level);
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }
        cout << *current->data << endl;
        sideways(current->left, level);
    }
}

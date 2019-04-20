// ----------------------------------BST.cpp---------------------------------------
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
#include "BST.h"

// --------------------------------------------------------------------------------------
// default constructor
// creates an empty tree
// --------------------------------------------------------------------------------------
BST::BST ()
{
    root = NULL;
}

// --------------------------------------------------------------------------------------
// destructor
// empty out the tree and deletes the root
// ----------------------------------------------------------------------------
BST::~BST ()
{
    makeEmptyHelper(root);
}

// --------------------------------------------------------------------------------------
// returns true if movieSearch is found in BSTree
// assigns found movie to the found Movie pointer parameter
// --------------------------------------------------------------------------------------
bool BST::getMovie (const Movie& movieSearch, Movie*& found) const
{
    return retrieveHelper (movieSearch, found, root);
}

bool BST::addMovie(Movie*& movieAdd)
{
    return insertHelper(root, movieAdd);
}

// --------------------------------------------------------------------------------------
// calls recursive helper function to print the contents of the BSTree
// --------------------------------------------------------------------------------------
ostream& operator<< (ostream& out, const BST& bst)
{
    bst.printHelper(bst.root);
    cout << endl;
    return out;
}

// --------------------------------------------------------------------------------------
// inserts the newMovie pointer into the BSTree
// --------------------------------------------------------------------------------------
bool BST::insertHelper(Node* &cur, Movie*& newMovie)
{
    if (cur == NULL) // insert
    {
        cur = new Node;
        cur -> right = NULL;
        cur -> left = NULL;
        cur -> movie = newMovie;
        return true;
    }
    else if (*cur -> movie == *newMovie) // duplicate exists, data not inserted
        return false;
    else if (*cur -> movie > *newMovie)
        return insertHelper (cur -> left, newMovie);
    else
        return insertHelper (cur -> right, newMovie);
}

// --------------------------------------------------------------------------------------
// returns true if the movieSearch movie is found in the BSTree
// retrieves the movieSearch movie from the BSTree and assigns it to the found Movie
// pointer
// --------------------------------------------------------------------------------------
bool BST::retrieveHelper (const Movie& movieSearch, Movie*& found, Node* cur) const
{
    if (cur == NULL) // movie not found
        return false;
    else if (*cur -> movie == movieSearch) // movie found
    {
        found = cur -> movie;
        return true;
    }
    else if (*cur -> movie > movieSearch)
        return retrieveHelper (movieSearch, found, cur -> left);
    else
        return retrieveHelper (movieSearch, found, cur -> right);
    
}

// --------------------------------------------------------------------------------------
// recursive helper function for destructor
// deletes dynamic memory
// --------------------------------------------------------------------------------------
void BST::makeEmptyHelper(Node* &cur)
{
    if (cur != NULL)
    {
        makeEmptyHelper(cur -> left);
        makeEmptyHelper(cur -> right);
        
        delete cur -> movie;
        cur -> movie = NULL;
        delete cur;
        cur = NULL;
    }
}

// --------------------------------------------------------------------------------------
// prints inorder traversal of BSTree
// --------------------------------------------------------------------------------------
void BST::printHelper (Node* cur) const
{
    if (cur != NULL)
    {
        printHelper(cur -> left);
        if (!cur -> movie -> getCountedStatus()) // if the movie has not been counted already
        {
            cur -> movie -> display();
            cur -> movie -> setCounted(true);
            cout << endl;
        }
        printHelper(cur -> right);
    }
}

// --------------------------------------------------------------------------------------
// resets all the Classic movies counted to false
// uses recursive helper function
// --------------------------------------------------------------------------------------
void BST::resetCounted()
{
    resetHelper(root);
}

// --------------------------------------------------------------------------------------
// recursive helper function for resetCounted()
// sets all Classic movies' counted variable to false
// --------------------------------------------------------------------------------------
void BST::resetHelper(Node* cur)
{
    if (cur != NULL)
    {
        resetHelper(cur -> left);
        cur -> movie -> setCounted(false);
        resetHelper(cur -> right);
    }
}

// --------------------------------------------------------------------------------------
// returns true if movie is found in BSTree by its title
// calls recursive helper function
// --------------------------------------------------------------------------------------
bool BST::getMovieByTitle(string title, int year, Movie*& found)
{
    return getMovieByTitleHelper(title, year, found, root);
}

// --------------------------------------------------------------------------------------
// recursive helper function for gotMovieByTitle()
// returns true if the movie is found by its title
// --------------------------------------------------------------------------------------
bool BST::getMovieByTitleHelper (string title, int year, Movie*& found,  Node* cur)
{
    if (cur == NULL) // movie not found
        return false;
    else if (cur -> movie -> getTitle() == title && cur -> movie -> getYearReleased() == year && !cur -> movie -> getCountedStatus()) // movie found
    {
        found = cur -> movie;
        found -> setCounted(true);
        return true;
    }
    else
        return getMovieByTitleHelper (title, year, found, cur-> left) || getMovieByTitleHelper (title, year, found, cur-> right);
}

// ----------------------------------customer.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// customer object
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// stores information about a customer, including frist and last name, ID, history
// and movies currently borrowed
// ------------------------------------------------------------------------------------
#ifndef customer_h
#define customer_h

#include <iostream>
#include "movie.h"
#include "MovieFactory.h"
using namespace std;

class Customer
{
public:
    Customer();                            // constructor
    Customer(int, string, string);         // ID, first, last
    ~Customer();                           // destructor
    
    // Accessors
    void display();                        // display customer's name and id
    void displayHistory();                 //display history of transactions
    
    int getID();                           //return ID of customer
    string getName();                      // return full name of customer
    
    // Mutators
    void addHistory(string);               // add transaction to history
    void addCheckedOut(Movie*);            // add movie to customer's checkedOut list
    bool removeCheckedOut(Movie*);         // remove movie from checkedOut list
    
private:
    struct historyNode {                   // Node to keep track of history
        historyNode* next;
        string data;                       // transaction summary
    };
    
    struct checkedOutNode {                // Node to keep track of movies borrowed
        checkedOutNode* next;
        Movie* movieBorrowed;              // pointer to movies borrowed
    };
    
    string lastName;
    string firstName;
    int ID; // unique user ID
    historyNode *history;                  // linked list of transaction history nodes
    checkedOutNode *checkedOut;            // linked list of movies checked out
};
#endif

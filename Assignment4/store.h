// ----------------------------------store.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// store class holds the business logic for the inventory system
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// The performTransaction method which performs either borrowing or returning a movie,
// printing inventory of all the items, and pringting transaction history of a customer,
// performTransaction also cheecks for bad inputs from the imput file
// ------------------------------------------------------------------------------------
#ifndef store_h
#define store_h

#include <iostream>
#include <fstream>
#include <sstream>
#include "customer.h"
#include "CustomerInventory.h"
#include "movie.h"
#include "MovieFactory.h"
#include "MovieInventory.h"
#include "transaction.h"
#include "TransactionFactory.h"
using namespace std;

class Store
{
public:
    Store();         // constructor
    ~Store();        // destructor
    
    void readCustomerFile (ifstream&);             // load customers into customerTable
    void readMovieFile (ifstream&);                // load movies into movieTable
    void readTransactionFile (ifstream&);          // read transactions and execute
    bool performTransaction (Transaction*);        // execute a transaction
    
private:
    MovieInventory movieTree;                      // BST of movies
    CustomerInventory customerTable;               // hash table of customers
    MovieFactory movieFactory;                     // movie factory
    TransactionFactory transFactory;               // transaction factory
    
    string readStringStream(stringstream&);        // helpers
};
#endif


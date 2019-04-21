// ----------------------------------transaction.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// super class of transactions
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// contains functions to perform a transaction and get summary of the transaction
// ------------------------------------------------------------------------------------
#ifndef transaction_h
#define transaction_h
#include "CustomerInventory.h"
#include "movie.h"
#include "MovieInventory.h"
using namespace std;

class Transaction
{
public:
    Transaction();                    // constructor
    virtual ~Transaction();           // destructor
    virtual bool perform(MovieInventory&, CustomerInventory&);    // perform transaction
    
private:
    char transType;                   // type of transaction
};
#endif

// ----------------------------------TransactionFactory.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// super class of transactions
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// contains functions to perform a transaction and get summary of the transaction
// ------------------------------------------------------------------------------------
#ifndef TransactionFactory_h
#define TransactionFactory_h
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "history.h"
#include "movie.h"
#include <sstream>
using namespace std;

class TransactionFactory
{
public:
    TransactionFactory();               // constructor
    ~TransactionFactory();              // destructor
    Transaction* create(char type, int customerID, Movie*& m);   // create transactions
};
#endif

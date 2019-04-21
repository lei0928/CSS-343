// ----------------------------------transaction.cpp---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// super class of transactions
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// contains functions to perform a transaction and get summary of the transaction
// ------------------------------------------------------------------------------------
#include "transaction.h"

// --------------------------------------------------------------------------------------
// default constructor
// initialize transaction type to "Z"
// summary indicates default transaction
// --------------------------------------------------------------------------------------
Transaction::Transaction()
{
    transType = 'Z';
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
Transaction::~Transaction()
{
    
}

// --------------------------------------------------------------------------------------
// default perform
// --------------------------------------------------------------------------------------
bool Transaction::perform(MovieInventory& movies, CustomerInventory& customers)
{
    return true;
}

// ----------------------------------TransactionFactory.cpp---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// super class of transactions
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// contains functions to perform a transaction and get summary of the transaction
// ------------------------------------------------------------------------------------
#include "TransactionFactory.h"

// --------------------------------------------------------------------------------------
// default constructor
// --------------------------------------------------------------------------------------
TransactionFactory::TransactionFactory()
{
    
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
TransactionFactory::~TransactionFactory()
{
    
}

// --------------------------------------------------------------------------------------
// creates new transaction object based on type passed in
// --------------------------------------------------------------------------------------
Transaction* TransactionFactory::create(char type, int customerID, Movie*& m)
{
    Transaction* transaction = NULL;
    switch(type)
    {
        case 'B':
            transaction = new Borrow(customerID, m);
            return transaction;
            break;
        case 'R':
            transaction = new Return(customerID, m);
            return transaction;
            break;
        case 'I':
            transaction = new Inventory;
            return transaction;
            break;
        case 'H': 
            transaction = new History(customerID);
            return transaction;
            break;
        default:
            cout << "ERROR: " << type << " Invalid Transaction Type. Try Again." << endl;
            return transaction;
            break;
    }
}
